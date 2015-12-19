/*
 * ADS7846 based touchscreen and sensor driver
 *
 * Copyright (c) 2005 David Brownell
 * Copyright (c) 2006 Nokia Corporation
 * Various changes: Imre Deak <imre.deak@nokia.com>
 *
 * Using code from:
 *  - corgi_ts.c
 *	Copyright (C) 2004-2005 Richard Purdie
 *  - omap_ts.[hc], ads7846.h, ts_osk.c
 *	Copyright (C) 2002 MontaVista Software
 *	Copyright (C) 2004 Texas Instruments
 *	Copyright (C) 2005 Dirk Behme
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */
#include <linux/hwmon.h>
#include <linux/init.h>
#include <linux/err.h>
#include <linux/delay.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/spi/spi.h>
#include <linux/spi/ads7846.h>
#include <asm/irq.h>

/*
 * This code has been heavily tested on a Nokia 770, and lightly
 * tested on other ads7846 devices (OSK/Mistral, Lubbock, Spitz).
 * TSC2046 is just newer ads7846 silicon.
 * Support for ads7843 tested on Atmel at91sam926x-EK.
 * Support for ads7845 has only been stubbed in.
 *
 * IRQ handling needs a workaround because of a shortcoming in handling
 * edge triggered IRQs on some platforms like the OMAP1/2. These
 * platforms don't handle the ARM lazy IRQ disabling properly, thus we
 * have to maintain our own SW IRQ disabled status. This should be
 * removed as soon as the affected platform's IRQ handling is fixed.
 *
 * App note sbaa036 talks in more detail about accurate sampling...
 * that ought to help in situations like LCDs inducing noise (which
 * can also be helped by using synch signals) and more generally.
 * This driver tries to utilize the measures described in the app
 * note. The strength of filtering can be set in the board-* specific
 * files.
 */

#define TS_POLL_DELAY	(1 * 1000000)	/* ns delay before the first sample */
#define TS_POLL_PERIOD	(5 * 1000000)	/* 5mS ns delay between samples */

/* this driver doesn't aim at the peak continuous sample rate */
#define	SAMPLE_BITS	(8 /*cmd*/ + 16 /*sample*/ + 2 /* before, after */)

struct ts_event {
	/* For portability, we can't read 12 bit values using SPI (which
	 * would make the controller deliver them as native byteorder u16
	 * with msbs zeroed).  Instead, we read them as two 8-bit values,
	 * *** WHICH NEED BYTESWAPPING *** and range adjustment.
	 */
	u16	x;
	u16	y;
	u16	z1, z2;
	int	ignore;
};

/*
 * We allocate this separately to avoid cache line sharing issues when
 * driver is used with DMA-based SPI controllers (like atmel_spi) on
 * systems where main memory is not DMA-coherent (most non-x86 boards).
 */
struct ads7846_packet {
	u8			read_x, read_y, read_z1, read_z2, pwrdown;
	u16			dummy;		/* for the pwrdown read */
	struct ts_event		tc;
};

struct ads7846 {
	struct input_dev	*input;
	char			phys[32];
	char			name[32];

	struct spi_device	*spi;

#if defined(CONFIG_HWMON) || defined(CONFIG_HWMON_MODULE)
	struct attribute_group	*attr_group;
	struct device		*hwmon;
#endif

	u16			model;
	u16			vref_mv;
	u16			vref_delay_usecs;
	u16			x_plate_ohms;
	u16			pressure_max;

	bool			swap_xy;

	struct ads7846_packet	*packet;

	struct spi_transfer	xfer[18];
	struct spi_message	msg[5];
	struct spi_message	*last_msg;
	int			msg_idx;
	int			read_cnt;
	int			read_rep;
	int			last_read;

	u16			debounce_max;
	u16			debounce_tol;
	u16			debounce_rep;

	u16			penirq_recheck_delay_usecs;

	spinlock_t		lock;
	struct hrtimer		timer;
	unsigned		pendown:1;	/* P: lock */
	unsigned		pending:1;	/* P: lock */
// FIXME remove "irq_disabled"
	unsigned		irq_disabled:1;	/* P: lock */
	unsigned		disabled:1;
	unsigned		is_suspended:1;

	int			(*filter)(void *data, int data_idx, int *val);
	void			*filter_data;
	void			(*filter_cleanup)(void *data);
	int			(*get_pendown_state)(void);
	int			gpio_pendown;

	void			(*wait_for_sync)(void);
  struct work_struct irq_work;
};

/* leave chip selected when we're done, for quicker re-select? */
#if	0
#define	CS_CHANGE(xfer)	((xfer).cs_change = 1)
#else
#define	CS_CHANGE(xfer)	((xfer).cs_change = 0)
#endif

/*--------------------------------------------------------------------------*/

/* The ADS7846 has touchscreen and other sensors.
 * Earlier ads784x chips are somewhat compatible.
 */
#define	ADS_START		(1 << 7)
#define	ADS_A2A1A0_d_y		(1 << 4)	/* differential */
#define	ADS_A2A1A0_d_z1		(3 << 4)	/* differential */
#define	ADS_A2A1A0_d_z2		(4 << 4)	/* differential */
#define	ADS_A2A1A0_d_x		(5 << 4)	/* differential */
#define	ADS_A2A1A0_temp0	(0 << 4)	/* non-differential */
#define	ADS_A2A1A0_vbatt	(2 << 4)	/* non-differential */
#define	ADS_A2A1A0_vaux		(6 << 4)	/* non-differential */
#define	ADS_A2A1A0_temp1	(7 << 4)	/* non-differential */
#define	ADS_8_BIT		(1 << 3)
#define	ADS_12_BIT		(0 << 3)
#define	ADS_SER			(1 << 2)	/* non-differential */
#define	ADS_DFR			(0 << 2)	/* differential */
#define	ADS_PD10_PDOWN		(0 << 0)	/* lowpower mode + penirq */
#define	ADS_PD10_ADC_ON		(1 << 0)	/* ADC on */
#define	ADS_PD10_REF_ON		(2 << 0)	/* vREF on + penirq */
#define	ADS_PD10_ALL_ON		(3 << 0)	/* ADC + vREF on */

#define	MAX_12BIT	((1<<12)-1)

/* leave ADC powered up (disables penirq) between differential samples */
#define	READ_12BIT_DFR(x, adc, vref) (ADS_START | ADS_A2A1A0_d_ ## x \
	| ADS_12_BIT | ADS_DFR | \
	(adc ? ADS_PD10_ADC_ON : 0) | (vref ? ADS_PD10_REF_ON : 0))

#define	READ_Y(vref)	(READ_12BIT_DFR(y,  1, vref))
#define	READ_Z1(vref)	(READ_12BIT_DFR(z1, 1, vref))
#define	READ_Z2(vref)	(READ_12BIT_DFR(z2, 1, vref))

#define	READ_X(vref)	(READ_12BIT_DFR(x,  1, vref))
#define	PWRDOWN		(READ_12BIT_DFR(y,  0, 0))	/* LAST */

/* single-ended samples need to first power up reference voltage;
 * we leave both ADC and VREF powered
 */
#define	READ_12BIT_SER(x) (ADS_START | ADS_A2A1A0_ ## x \
	| ADS_12_BIT | ADS_SER)

#define	REF_ON	(READ_12BIT_DFR(x, 1, 1))
#define	REF_OFF	(READ_12BIT_DFR(y, 0, 0))

/*--------------------------------------------------------------------------*/

/*
 * Non-touchscreen sensors only use single-ended conversions.
 * The range is GND..vREF. The ads7843 and ads7835 must use external vREF;
 * ads7846 lets that pin be unconnected, to use internal vREF.
 */

struct ser_req {
	u8			ref_on;
	u8			command;
	u8			ref_off;
	u16			scratch;
	__be16			sample;
	struct spi_message	msg;
	struct spi_transfer	xfer[6];
};

static void ads7846_enable(struct ads7846 *ts);
static void ads7846_disable(struct ads7846 *ts);

static int device_suspended(struct device *dev)
{
	struct ads7846 *ts = dev_get_drvdata(dev);
	return ts->is_suspended || ts->disabled;
}



static int is_pen_down(struct device *dev)
{
	struct ads7846	*ts = dev_get_drvdata(dev);

	return ts->pendown;
}

static ssize_t ads7846_pen_down_show(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%u\n", is_pen_down(dev));
}

static DEVICE_ATTR(pen_down, S_IRUGO, ads7846_pen_down_show, NULL);

static ssize_t ads7846_disable_show(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	struct ads7846	*ts = dev_get_drvdata(dev);

	return sprintf(buf, "%u\n", ts->disabled);
}

static ssize_t ads7846_disable_store(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf, size_t count)
{
	struct ads7846 *ts = dev_get_drvdata(dev);
	unsigned long i;

	if (strict_strtoul(buf, 10, &i))
		return -EINVAL;

	spin_lock_irq(&ts->lock);

	if (i)
		ads7846_disable(ts);
	else
		ads7846_enable(ts);

	spin_unlock_irq(&ts->lock);

	return count;
}

static DEVICE_ATTR(disable, 0664, ads7846_disable_show, ads7846_disable_store);

static struct attribute *ads784x_attributes[] = {
	&dev_attr_pen_down.attr,
	&dev_attr_disable.attr,
	NULL,
};

static struct attribute_group ads784x_attr_group = {
	.attrs = ads784x_attributes,
};

/*--------------------------------------------------------------------------*/

static int get_pendown_state(struct ads7846 *ts)
{
	if (ts->get_pendown_state)
		return ts->get_pendown_state();

	return !gpio_get_value(ts->gpio_pendown);
}

static void null_wait_for_sync(void)
{
}



static u16 ads_read_adc(struct ads7846	*ts, u8 cmd)
{
  u16 val=0; 
	u8 tx_buf[2];
	u8 rx_buf[4];  
	int ret;

	tx_buf[0] = cmd;

	ret = spi_write_then_read(ts->spi, tx_buf, 1, rx_buf, 2);
  
 // printk("ads_read_adc=%x,%x\n",rx_buf[0],rx_buf[1]);  
  
  if (ret)  
  {
		//printk(KERN_DEBUG DRV_NAME ": %s() failed: ret = %d\n",
		//	__func__, ret);
    val = 0;
  }
  else
  {
    val = rx_buf[0];
    val <<= 8;
    val |= rx_buf[1];
    val >>= 3; 
  }
   
	return val;
}

#define READ_TIMES 15 // 10
#define LOST_VAL 5	  //	
u16 ADS_Read_XY(struct ads7846	*ts, u16 xy)
{
	u16 i, j;
	u16 buf[READ_TIMES];
	u16 sum=0;
	u16 temp;
	
	for(i=0;i<READ_TIMES;i++)
	{				 
		buf[i]=ads_read_adc(ts, xy);	    
	}				    
	
	for(i=0;i<READ_TIMES-1; i++)
	{
		for(j=i+1;j<READ_TIMES;j++)
		{
			if(buf[i]>buf[j])
			{
				temp=buf[i];
				buf[i]=buf[j];
				buf[j]=temp;
			}
		}
	}	  
	
	sum=0;
	for (i=LOST_VAL;i<READ_TIMES-LOST_VAL;i++) {
		sum+=buf[i];
	}
	temp= sum /(READ_TIMES-2*LOST_VAL);
	return temp;   
} 

#define CMD_RDX 0x90
#define CMD_RDY	0xD0 
u8 Read_ADS(struct ads7846	*ts, u16 *x,u16 *y)
{
	u16 xtemp,ytemp;			 	 		  
	xtemp=ADS_Read_XY(ts, CMD_RDX);
	ytemp=ADS_Read_XY(ts, CMD_RDY);	  												   
	if(xtemp<100||ytemp<100)return 0;
	*x = xtemp;
	*y = ytemp;
	return 1;
}

#define ERR_RANGE 50 
u8 Read_ADS2(struct ads7846	*ts, u16 *x,u16 *y) 
{
	volatile u16 x1,y1;
 	volatile u16 x2,y2;
 	volatile u8 flag;    
  
  flag=Read_ADS(ts, &x1,&y1);
 // printf("x,y=%d,%d:\n", x1,y1);
  if(flag==0) return(0);
  
  flag=Read_ADS(ts, &x2,&y2);	   
  if(flag==0)return(0);
  //printf("x,y=%d,%d:\n", x2,y2);
  
  if(((x2<=x1&&x1<x2+ERR_RANGE)||(x1<=x2&&x2<x1+ERR_RANGE))
    &&((y2<=y1&&y1<y2+ERR_RANGE)||(y1<=y2&&y2<y1+ERR_RANGE)))
  {
    *x=(x1+x2)/2;
    *y=(y1+y2)/2;
    return 1;
  }
  else return 0;	  
}

static int touchx=0;

static volatile int press=0;

static int An = 0xfff7be1e;
static int Bn = 0xffffef6d;
static int Cn = 0x7b3c8df;
static int Dn = 0x89e;
static int En = 0xfff9b55c;
static int Fn = 0x7346c4c;
static int Divider = 0xffa280fe;



static void ads7846_irq_work_handler(struct work_struct *work)
{
  struct ads7846	*ts =
		container_of(work, struct ads7846, irq_work);

	int		status = 0;
  struct input_dev *input = ts->input;
  u16 x,y;
  long x2,y2;
  
	spin_lock(&ts->lock);
  
  //printk("ads7846_timer\n");


	if (!get_pendown_state(ts))
  {
      //printk("ads7846_irq released\n");

			input_report_key(input, BTN_TOUCH, 0);
			input_report_abs(input, ABS_PRESSURE, 0);
			input_sync(input);
      press = 0;
	} 
  else
  {
    if (Read_ADS2(ts, &y, &x) && x<4096  && y<4096)
    {
      x2 = ((An * x) + (Bn * y) + Cn) / Divider;
      y2 = ((Dn * x) + (En * y) + Fn) / Divider; 

      input_report_abs(input, ABS_X, x2);
      input_report_abs(input, ABS_Y, y2);
      input_report_abs(input, ABS_PRESSURE, 1);
      input_report_key(input, BTN_TOUCH, 1);
      input_sync(input);     

    }
    //printk("ads7846_irq down x,y=%d,%d\n",x,y);
    hrtimer_start(&ts->timer, ktime_set(0, TS_POLL_PERIOD),
            HRTIMER_MODE_REL);    
  }    
  

	spin_unlock(&ts->lock);
  
}

	/*
	 * Can't do anything in interrupt context because we need to
	 * block (spi_sync() is blocking) so fire of the interrupt
	 * handling workqueue.
	 * Remember that we access ads7846 registers through SPI bus
	 * via spi_sync() call.
	 */
static enum hrtimer_restart ads7846_timer(struct hrtimer *handle)
{
	struct ads7846	*ts = container_of(handle, struct ads7846, timer);

  schedule_work(&ts->irq_work);
  
	return HRTIMER_NORESTART;
}

static struct input_dev * _default_input_dev;

//volatile int ads_irq = 0;
static irqreturn_t ads7846_irq(int irq, void *handle)
{
	struct ads7846 *ts = handle;
  struct input_dev *input = ts->input;
	unsigned long flags;
 
  //printk("ads7846_irq\n");
 
  //spin_lock_irqsave(&ts->lock, flags);  
 // printk("ads7846_irq press\n");
  //ads_irq = 1;
  
  if (press==0) 
  {
    //
    //if (likely(get_pendown_state(ts))) {

        press = 1;
        hrtimer_start(&ts->timer, ktime_set(0, TS_POLL_DELAY),
            HRTIMER_MODE_REL);
     // }

    //
  }
  //spin_unlock_irqrestore(&ts->lock, flags);
  
#if 0

	spin_lock_irqsave(&ts->lock, flags);
	if (likely(get_pendown_state(ts))) {
		if (!ts->irq_disabled) 
    {
			/* The ARM do_simple_IRQ() dispatcher doesn't act
			 * like the other dispatchers:  it will report IRQs
			 * even after they've been disabled.  We work around
			 * that here.  (The "generic irq" framework may help...)
			 */
			ts->irq_disabled = 1;
			disable_irq_nosync(ts->spi->irq);
			ts->pending = 1;
			//hrtimer_start(&ts->timer, ktime_set(0, TS_POLL_DELAY),
			//		HRTIMER_MODE_REL);
          
		}
	}
	spin_unlock_irqrestore(&ts->lock, flags);
#endif
	return IRQ_HANDLED;
}

/*--------------------------------------------------------------------------*/

/* Must be called with ts->lock held */
static void ads7846_disable(struct ads7846 *ts)
{
	if (ts->disabled)
		return;

	ts->disabled = 1;

	/* are we waiting for IRQ, or polling? */
	if (!ts->pending) {
		ts->irq_disabled = 1;
		disable_irq(ts->spi->irq);
	} else {
		/* the timer will run at least once more, and
		 * leave everything in a clean state, IRQ disabled
		 */
		while (ts->pending) {
			spin_unlock_irq(&ts->lock);
			msleep(1);
			spin_lock_irq(&ts->lock);
		}
	}

	/* we know the chip's in lowpower mode since we always
	 * leave it that way after every request
	 */
}

/* Must be called with ts->lock held */
static void ads7846_enable(struct ads7846 *ts)
{
	if (!ts->disabled)
		return;

	ts->disabled = 0;
	ts->irq_disabled = 0;
	enable_irq(ts->spi->irq);
}

static int ads7846_suspend(struct spi_device *spi, pm_message_t message)
{
	struct ads7846 *ts = dev_get_drvdata(&spi->dev);

	spin_lock_irq(&ts->lock);

	ts->is_suspended = 1;
	ads7846_disable(ts);

	spin_unlock_irq(&ts->lock);

	return 0;

}

static int ads7846_resume(struct spi_device *spi)
{
	struct ads7846 *ts = dev_get_drvdata(&spi->dev);

	spin_lock_irq(&ts->lock);

	ts->is_suspended = 0;
	ads7846_enable(ts);

	spin_unlock_irq(&ts->lock);

	return 0;
}

static int __devinit setup_pendown(struct spi_device *spi, struct ads7846 *ts)
{
	struct ads7846_platform_data *pdata = spi->dev.platform_data;
	int err;

	/* REVISIT when the irq can be triggered active-low, or if for some
	 * reason the touchscreen isn't hooked up, we don't need to access
	 * the pendown state.
	 */
	if (!pdata->get_pendown_state && !gpio_is_valid(pdata->gpio_pendown)) {
		dev_err(&spi->dev, "no get_pendown_state nor gpio_pendown?\n");
		return -EINVAL;
	}

	if (pdata->get_pendown_state) {
		ts->get_pendown_state = pdata->get_pendown_state;
		return 0;
	}

	err = gpio_request(pdata->gpio_pendown, "ads7846_pendown");
	if (err) {
		dev_err(&spi->dev, "failed to request pendown GPIO%d\n",
				pdata->gpio_pendown);
		return err;
	}

	ts->gpio_pendown = pdata->gpio_pendown;
	return 0;
}

#define LINEOFF 1


static int __devinit ads7846_probe(struct spi_device *spi)
{
	struct ads7846			*ts;
	struct ads7846_packet		*packet;
	struct input_dev		*input_dev;
	struct ads7846_platform_data	*pdata = spi->dev.platform_data;
	struct spi_message		*m;
	struct spi_transfer		*x;
	int				vref;
	int				err;
  int   irq;
  u16 xx,y;
  
  printk("ads7846: ads7846_probe start\n");  
  

    
  
	if (!spi->irq) {
		dev_dbg(&spi->dev, "no IRQ?\n");
		return -ENODEV;
	}

	if (!pdata) {
		dev_dbg(&spi->dev, "no platform data?\n");
		return -ENODEV;
	}

	/* We'd set TX wordsize 8 bits and RX wordsize to 13 bits ... except
	 * that even if the hardware can do that, the SPI controller driver
	 * may not.  So we stick to very-portable 8 bit words, both RX and TX.
	 */
#if 0   
	spi->bits_per_word = 8;
  spi->max_speed_hz = 800000;
	spi->mode = SPI_MODE_0;
	err = spi_setup(spi);
	if (err < 0)
		return err;
#endif
	ts = kzalloc(sizeof(struct ads7846), GFP_KERNEL);
	packet = kzalloc(sizeof(struct ads7846_packet), GFP_KERNEL);
	input_dev = input_allocate_device();
  _default_input_dev = input_dev;
	if (!ts || !packet || !input_dev) {
		err = -ENOMEM;
		goto err_free_mem;
	}

	dev_set_drvdata(&spi->dev, ts);

	ts->packet = packet;
	ts->spi = spi;
	ts->input = input_dev;
	ts->vref_mv = pdata->vref_mv;
	ts->swap_xy = pdata->swap_xy;

	hrtimer_init(&ts->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	ts->timer.function = ads7846_timer;

	spin_lock_init(&ts->lock);

	ts->model = pdata->model ? : 7846;
	ts->vref_delay_usecs = pdata->vref_delay_usecs ? : 100;
	ts->x_plate_ohms = pdata->x_plate_ohms ? : 400;
	ts->pressure_max = pdata->pressure_max ? : ~0;

	if (pdata->filter != NULL) {
		if (pdata->filter_init != NULL) {
			err = pdata->filter_init(pdata, &ts->filter_data);
			if (err < 0)
				goto err_free_mem;
		}
		ts->filter = pdata->filter;
		ts->filter_cleanup = pdata->filter_cleanup;
	} else if (pdata->debounce_max) {
		ts->debounce_max = pdata->debounce_max;
		if (ts->debounce_max < 2)
			ts->debounce_max = 2;
		ts->debounce_tol = pdata->debounce_tol;
		ts->debounce_rep = pdata->debounce_rep;
//		ts->filter = ads7846_debounce;
		ts->filter_data = ts;
	} //else
		//ts->filter = ads7846_no_filter;

	err = setup_pendown(spi, ts);
	if (err)
		goto err_cleanup_filter;

	if (pdata->penirq_recheck_delay_usecs)
		ts->penirq_recheck_delay_usecs =
				pdata->penirq_recheck_delay_usecs;

	ts->wait_for_sync = pdata->wait_for_sync ? : null_wait_for_sync;

	snprintf(ts->phys, sizeof(ts->phys), "%s/input0", dev_name(&spi->dev));
	snprintf(ts->name, sizeof(ts->name), "ADS%d Touchscreen", ts->model);

	input_dev->name = ts->name;
	input_dev->phys = ts->phys;
	input_dev->dev.parent = &spi->dev;

	input_dev->evbit[0] = BIT_MASK(EV_SYN) | BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
	input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
	input_set_abs_params(input_dev, ABS_X,
			pdata->x_min ? : 0,
			pdata->x_max ? : MAX_12BIT,
			0, 0);
	input_set_abs_params(input_dev, ABS_Y,
			pdata->y_min ? : 0,
			pdata->y_max ? : MAX_12BIT,
			0, 0);
	input_set_abs_params(input_dev, ABS_PRESSURE,
			pdata->pressure_min, pdata->pressure_max, 0, 0);

	vref = pdata->keep_vref_on;
  
  INIT_WORK(&ts->irq_work, ads7846_irq_work_handler);
                        
  //err = gpio_request(pdata->gpio_pendown, "ADS7846_GPIO_IRQ");
	//if (err != 0) {
	//	printk(KERN_DEBUG "error requesting GPIO for IRQ %d\n", err);
	//	goto err_free_gpio;
	//}
  //irq = 207; //gpio_to_irq()
  //spi->irq = irq;
  printk("ads7846: IRQ = %d\n",spi->irq);
  
  /* request irq trigger falling */
	err = request_irq(spi->irq, ads7846_irq,
				IRQF_TRIGGER_FALLING, "ads7846", ts);
        
	/* Enable the exti interrupt if this callback is available. */
  //pdata->exti_enable_int(1);
  
	if (err < 0) {
		printk(KERN_DEBUG "IRQ %d not free\n", irq);
		goto err_free_gpio;
  }             

	dev_info(&spi->dev, "touchscreen, irq %d\n", spi->irq);

	/* take a first sample, leaving nPENIRQ active and vREF off; avoid
	 * the touchscreen, in case it's not connected.
	 */
//	(void) ads7846_read12_ser(&spi->dev,
//			  READ_12BIT_SER(vaux) | ADS_PD10_ALL_ON);

	err = sysfs_create_group(&spi->dev.kobj, &ads784x_attr_group);
	if (err)
		goto err_remove_hwmon;

	err = input_register_device(input_dev);
	if (err) {
    printk("ads7846: err-> input_register_device");
    goto err_remove_attr_group;
  }
  

  
  #if 0
	printk("wait ads7846 press\n");
  while(!get_pendown_state(ts)) ;
  
  while (get_pendown_state(ts))
  {
    if ( Read_ADS2(ts, &xx, &y))
    {
      printk("ads7846_irq down x,y=%d,%d\n",xx,y);
    }
  }
#endif
	return 0;

 err_remove_attr_group:
	sysfs_remove_group(&spi->dev.kobj, &ads784x_attr_group);
 err_remove_hwmon:
	//ads784x_hwmon_unregister(spi, ts);
 err_free_irq:
	free_irq(spi->irq, ts);
 err_free_gpio:
	if (ts->gpio_pendown != -1)
		gpio_free(ts->gpio_pendown);
 err_cleanup_filter:
	if (ts->filter_cleanup)
		ts->filter_cleanup(ts->filter_data);
 err_free_mem:
	input_free_device(input_dev);
	kfree(packet);
	kfree(ts);
	return err;
}

static int __devexit ads7846_remove(struct spi_device *spi)
{
	struct ads7846		*ts = dev_get_drvdata(&spi->dev);


	input_unregister_device(ts->input);

	ads7846_suspend(spi, PMSG_SUSPEND);

	sysfs_remove_group(&spi->dev.kobj, &ads784x_attr_group);

	free_irq(ts->spi->irq, ts);
	/* suspend left the IRQ disabled */
	enable_irq(ts->spi->irq);

	if (ts->gpio_pendown != -1)
		gpio_free(ts->gpio_pendown);

	if (ts->filter_cleanup)
		ts->filter_cleanup(ts->filter_data);

	kfree(ts->packet);
	kfree(ts);

	dev_dbg(&spi->dev, "unregistered touchscreen\n");
	return 0;
}

static struct spi_driver ads7846_driver = {
	.driver = {
		.name	= "ads7846",
		.bus	= &spi_bus_type,
		.owner	= THIS_MODULE,
	},
	.probe		= ads7846_probe,
	.remove		= __devexit_p(ads7846_remove),
	//.suspend	= ads7846_suspend,
	//.resume		= ads7846_resume,
};

static int __init ads7846_init(void)
{
	return spi_register_driver(&ads7846_driver);
}
module_init(ads7846_init);

static void __exit ads7846_exit(void)
{
	spi_unregister_driver(&ads7846_driver);
}
module_exit(ads7846_exit);

MODULE_DESCRIPTION("ADS7846 TouchScreen Driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("spi:ads7846");
