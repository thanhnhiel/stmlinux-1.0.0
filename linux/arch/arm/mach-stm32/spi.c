/*
 * linux/arch/arm/mach-stm32/spi.c
 *
 * Copyright (C) 2013 Vladimir Khusainov, Emcraft Systems
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/sysdev.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/mtd/physmap.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/spi/spi.h>
#include <linux/spi/spi_stm32.h>
#include <linux/spi/flash.h>
#include <mach/stm32.h>
#include <mach/platform.h>
#include <mach/clock.h>
#include <mach/spi.h>
#include <mach/exti.h>
#include <linux/spi/ads7846.h>

/* 
 * Size of the SPI controller register area
 */
#define SPI_STM32_REGS_SIZE	0x3FF

/*
 * SPI_1
 */
#if defined(CONFIG_STM32_SPI1)

#define SPI_STM32_DEV1_IRQ	35
#define SPI_STM32_DEV1_REGS	0x40013000

static struct resource spi_stm32_dev1_resources[] = {
	{
		.start	= SPI_STM32_DEV1_IRQ,
		.end	= SPI_STM32_DEV1_IRQ,
		.flags	= IORESOURCE_IRQ,
	},
	{
		.start	= SPI_STM32_DEV1_REGS,
		.end	= SPI_STM32_DEV1_REGS + SPI_STM32_REGS_SIZE,
		.flags	= IORESOURCE_MEM,
	},
};

static struct platform_device spi_stm32_dev1 = {
	.name           = "spi_stm32",
	.id             = 0,
	.num_resources  = ARRAY_SIZE(spi_stm32_dev1_resources),
	.resource       = spi_stm32_dev1_resources,
};

#endif

/*
 * SPI_2
 */
#if defined(CONFIG_STM32_SPI2)

#define SPI_STM32_DEV2_IRQ	36
#define SPI_STM32_DEV2_REGS	0x40003800

static struct resource spi_stm32_dev2_resources[] = {
	{
		.start	= SPI_STM32_DEV2_IRQ,
		.end	= SPI_STM32_DEV2_IRQ,
		.flags	= IORESOURCE_IRQ,
	},
	{
		.start	= SPI_STM32_DEV2_REGS,
		.end	= SPI_STM32_DEV2_REGS + SPI_STM32_REGS_SIZE,
		.flags	= IORESOURCE_MEM,
	},
};

static struct platform_device spi_stm32_dev2 = {
	.name           = "spi_stm32",
	.id             = 1,
	.num_resources  = ARRAY_SIZE(spi_stm32_dev2_resources),
	.resource       = spi_stm32_dev2_resources,
};

#endif	/* CONFIG_STM32_SPI2 */

/*
 * SPI_3
 */
#if defined(CONFIG_STM32_SPI3)

#define SPI_STM32_DEV3_IRQ	51
#define SPI_STM32_DEV3_REGS	0x40003C00

static struct resource spi_stm32_dev3_resources[] = {
	{
		.start	= SPI_STM32_DEV3_IRQ,
		.end	= SPI_STM32_DEV3_IRQ,
		.flags	= IORESOURCE_IRQ,
	},
	{
		.start	= SPI_STM32_DEV3_REGS,
		.end	= SPI_STM32_DEV3_REGS + SPI_STM32_REGS_SIZE,
		.flags	= IORESOURCE_MEM,
	},
};

static struct platform_device spi_stm32_dev3 = {
	.name           = "spi_stm32",
	.id             = 2,
	.num_resources  = ARRAY_SIZE(spi_stm32_dev3_resources),
	.resource       = spi_stm32_dev3_resources,
};

#endif

/*
 * SPI_4
 */
#if defined(CONFIG_STM32_SPI4)

#define SPI_STM32_DEV4_IRQ	84
#define SPI_STM32_DEV4_REGS	0x40013400

static struct resource spi_stm32_dev4_resources[] = {
	{
		.start	= SPI_STM32_DEV4_IRQ,
		.end	= SPI_STM32_DEV4_IRQ,
		.flags	= IORESOURCE_IRQ,
	},
	{
		.start	= SPI_STM32_DEV4_REGS,
		.end	= SPI_STM32_DEV4_REGS + SPI_STM32_REGS_SIZE,
		.flags	= IORESOURCE_MEM,
	},
};

static struct platform_device spi_stm32_dev4 = {
	.name           = "spi_stm32",
	.id             = 3,
	.num_resources  = ARRAY_SIZE(spi_stm32_dev4_resources),
	.resource       = spi_stm32_dev4_resources,
};

#endif

/*
 * SPI_5
 */
#if defined(CONFIG_STM32_SPI5)

#define SPI_STM32_DEV5_IRQ	85
#define SPI_STM32_DEV5_REGS	0x40015000

static struct resource spi_stm32_dev5_resources[] = {
	{
		.start	= SPI_STM32_DEV5_IRQ,
		.end	= SPI_STM32_DEV5_IRQ,
		.flags	= IORESOURCE_IRQ,
	},
	{
		.start	= SPI_STM32_DEV5_REGS,
		.end	= SPI_STM32_DEV5_REGS + SPI_STM32_REGS_SIZE,
		.flags	= IORESOURCE_MEM,
	},
};

static struct platform_device spi_stm32_dev5 = {
	.name           = "spi_stm32",
	.id             = 4,
	.num_resources  = ARRAY_SIZE(spi_stm32_dev5_resources),
	.resource       = spi_stm32_dev5_resources,
};

#endif	/* CONFIG_STM32_SPI5 */

/*
 * SPI_6
 */
#if defined(CONFIG_STM32_SPI6)

#define SPI_STM32_DEV6_IRQ	86
#define SPI_STM32_DEV6_REGS	0x40015400

static struct resource spi_stm32_dev6_resources[] = {
	{
		.start	= SPI_STM32_DEV6_IRQ,
		.end	= SPI_STM32_DEV6_IRQ,
		.flags	= IORESOURCE_IRQ,
	},
	{
		.start	= SPI_STM32_DEV6_REGS,
		.end	= SPI_STM32_DEV6_REGS + SPI_STM32_REGS_SIZE,
		.flags	= IORESOURCE_MEM,
	},
};

static struct platform_device spi_stm32_dev6 = {
	.name           = "spi_stm32",
	.id             = 5,
	.num_resources  = ARRAY_SIZE(spi_stm32_dev6_resources),
	.resource       = spi_stm32_dev6_resources,
};

#endif

#ifdef CONFIG_ENC28J60

#define ENABLE      1
#define ENC28J60_EXTI_GPIO    2   // PH4 : 7,4. PC4 : 2,4
#define ENC28J60_LINE_IRQ     4
#define ENC28J60_GPIO_IRQ     STM32_GPIO_PORTPIN2NUM( \
                                ENC28J60_EXTI_GPIO,\
                                ENC28J60_LINE_IRQ)
#define SPI_ENC28J60_GPIO_CS    STM32_GPIO_PORTPIN2NUM(0,4) // PA4         
#define SPI_ENC28J60_GPIO_PWR   STM32_GPIO_PORTPIN2NUM(2,5) // PC5
                               
void enc28j60_exti_enable_int(int enable)
{
  stm32_exti_enable_int(ENC28J60_LINE_IRQ, enable); //line 4 : Enable 
  if (enable)
  {
    stm32_exti_connect(ENC28J60_LINE_IRQ, ENC28J60_EXTI_GPIO);
    stm32_exti_set_falling(ENC28J60_LINE_IRQ);
  }
}
#endif

#define ADS7846_EXTI_GPIO    7   // PH4
#define ADS7846_LINE_IRQ     4
#define ADS7846_GPIO_IRQ     STM32_GPIO_PORTPIN2NUM( \
                                ADS7846_EXTI_GPIO,\
                                ADS7846_LINE_IRQ)
                                
#define ADS7846_GPIO_CS     STM32_GPIO_PORTPIN2NUM(7,5) // PH5
#define LCD_GPIO_CS         STM32_GPIO_PORTPIN2NUM(5,6) // PF6
#define FLASH_GPIO_CS       STM32_GPIO_PORTPIN2NUM(8,3) // PI3

#if (!defined(CONFIG_SPI_SPIDEV) && defined(CONFIG_TOUCHSCREEN_ADS7846))
#ifndef ENABLE
#define ENABLE      1
#endif

void ads7846_exti_enable_int(int enable)
{
  stm32_exti_enable_int(ADS7846_LINE_IRQ, enable); //line 4 : Enable 
  if (enable)
  {
    stm32_exti_connect(ADS7846_LINE_IRQ, ADS7846_EXTI_GPIO);
    stm32_exti_set_falling(ADS7846_LINE_IRQ);
  }
}

int ads7846_pendown_state(void)
{
  return !gpio_get_value(ADS7846_GPIO_IRQ);	/* Touchscreen PENIRQ - PH4*/
}

static struct ads7846_platform_data ads_info = {
      .model			= 7846,
      .swap_xy = 1,
      .x_min			= 0,
      .x_max			= 319,
      .y_min			= 0,
      .y_max			= 239,
      .vref_delay_usecs	= 100,

      .x_plate_ohms		= 576,
      .y_plate_ohms		= 366,

      .pressure_max		= 15000, /* generally nonsense on the 7843 */
      .debounce_max		= 1,
      .debounce_rep		= 0,
      .debounce_tol		= (~0),
      .get_pendown_state	= ads7846_pendown_state,
      .gpio_pendown = ADS7846_GPIO_IRQ,
      .exti_enable_int = ads7846_exti_enable_int,
    };     
     


#endif

/*
 * Register the STM32 specific SPI controllers and devices with the kernel.
 */
void __init stm32_spi_init(void)
{
  int i;
	int bus = 0, port = 0, pin = 0;
	int p = stm32_platform_get();

#if defined(CONFIG_STM32_SPI1)
	platform_set_drvdata(&spi_stm32_dev1, 
		(void *) stm32_clock_get(CLOCK_PCLK2));
	platform_device_register(&spi_stm32_dev1);
#endif
#if defined(CONFIG_STM32_SPI2)
	platform_set_drvdata(&spi_stm32_dev2, 
		(void *) stm32_clock_get(CLOCK_PCLK1));
	platform_device_register(&spi_stm32_dev2);
#endif
#if defined(CONFIG_STM32_SPI3)
	platform_set_drvdata(&spi_stm32_dev3, 
		(void *) stm32_clock_get(CLOCK_PCLK1));
	platform_device_register(&spi_stm32_dev3);
#endif
#if defined(CONFIG_STM32_SPI4)
	platform_set_drvdata(&spi_stm32_dev4, 
		(void *) stm32_clock_get(CLOCK_PCLK2));
	platform_device_register(&spi_stm32_dev4);
#endif
#if defined(CONFIG_STM32_SPI5)
	platform_set_drvdata(&spi_stm32_dev5, 
		(void *) stm32_clock_get(CLOCK_PCLK2));
	platform_device_register(&spi_stm32_dev5);
#endif
#if defined(CONFIG_STM32_SPI6)
	platform_set_drvdata(&spi_stm32_dev6, 
		(void *) stm32_clock_get(CLOCK_PCLK2));
	platform_device_register(&spi_stm32_dev6);
#endif

#define SPI_FLASH_CS_PORT__STM32F4_SOM		7
#define SPI_FLASH_CS_PIN__STM32F4_SOM		5
#define SPI_FLASH_CS_PORT__STM32F439_SOM	1
#define SPI_FLASH_CS_PIN__STM32F439_SOM		9
#define SPI_FLASH_CS_PORT__STM32F7_SOM		1
#define SPI_FLASH_CS_PIN__STM32F7_SOM		9
#define SPI_FLASH_CS_PORT__STM32F4_DISCO	4
#define SPI_FLASH_CS_PIN__STM32F4_DISCO		4

	if (p == PLATFORM_STM32_STM_SOM) {
		bus = 4;
		port = SPI_FLASH_CS_PORT__STM32F4_SOM;
		pin = SPI_FLASH_CS_PIN__STM32F4_SOM;
	}
	else if (p == PLATFORM_STM32_STM_STM32F439_SOM) {
		bus = 1;
		port = SPI_FLASH_CS_PORT__STM32F439_SOM;
		pin = SPI_FLASH_CS_PIN__STM32F439_SOM;
	}
	else if (p == PLATFORM_STM32_STM_STM32F7_SOM) {
		bus = 1;
		port = SPI_FLASH_CS_PORT__STM32F7_SOM;
		pin = SPI_FLASH_CS_PIN__STM32F7_SOM;
	}
	else if (p == PLATFORM_STM32_STM_DISCO) {
		bus = 3;
		port = SPI_FLASH_CS_PORT__STM32F4_DISCO;
		pin = SPI_FLASH_CS_PIN__STM32F4_DISCO;
	}


	if (p == PLATFORM_STM32_STM_SOM ||
	    p == PLATFORM_STM32_STM_STM32F439_SOM ||
	    p == PLATFORM_STM32_STM_STM32F7_SOM ||
	    p == PLATFORM_STM32_STM_DISCO) {

      
#if defined(CONFIG_MTD_M25P80) || defined(CONFIG_TOUCHSCREEN_ADS7846) || \
	(defined(CONFIG_ENC28J60) || defined(CONFIG_SPI_SPIDEV))
    
//#define SPI_ENC28J60_GPIO_CS     STM32_GPIO_PORTPIN2NUM(0,4) // PA4

  /*
   * Set up the Chip Select GPIO for the SPI Flash
   */
  gpio_request(FLASH_GPIO_CS,"F_CS");
  gpio_request(ADS7846_GPIO_CS,"T_CS");
  gpio_request(LCD_GPIO_CS,"L_CS");
  gpio_direction_output(FLASH_GPIO_CS, 1); // F_CS - PI3 
  gpio_direction_output(ADS7846_GPIO_CS, 1); // T_CS - PH5 
  gpio_direction_output(LCD_GPIO_CS, 1); //L_CS - PF6 
  
		/* This assumes that there is an SPI Flash device
		 * handwired to SPI5 on the breadboard area of SOM-BSB-EXT.
		 * SPI Flash can be accessed either via SPIDEV interface
		 * and this takes precedence if SPIDEV is enabled in the kernel.
		 * If SPIDEV is disabled, then SPI Flash can be
		 * accessed via the Flash MTD interface
		 */
#if (defined(CONFIG_MTD_M25P80) || defined(CONFIG_SPI_SPIDEV))

		/* 
		 * Flash MTD partitioning.
		 * This is used only if CONFIG_SPIDEV is undefined
		 */
#if !defined(CONFIG_SPI_SPIDEV)

		/*
		 * SPI Flash partitioning:
		 */
#		define FLASH_JFFS2_OFFSET__DONGLE	(1024 * 1024 * 1)
#		define FLASH_SIZE__DONGLE		(1024 * 1024 * 4)
		static struct mtd_partition 
			spi_stm32_flash_partitions__dongle[] = {
			{
				.name = "spi_flash_part0",
				.size = FLASH_JFFS2_OFFSET__DONGLE,
				.offset = 0,
			},
			{
				.name = "spi_flash_part1",
				.size = FLASH_SIZE__DONGLE -
					FLASH_JFFS2_OFFSET__DONGLE,
				.offset = FLASH_JFFS2_OFFSET__DONGLE,
			},
		};

		/*
		 * SPI Flash
 		 */
		static struct flash_platform_data 
			spi_stm32_flash_data__dongle = {
			.name = "m25p32",
			.parts =  spi_stm32_flash_partitions__dongle,
			.nr_parts = 
			ARRAY_SIZE(spi_stm32_flash_partitions__dongle),
			.type = "m25p32",
		};
#endif

		/*
 		 * SPI slave
 		 */
		static struct spi_stm32_slv 
			spi_stm32_flash_slv__dongle = {
      .cs_gpio = FLASH_GPIO_CS,
			.timeout = 3,
		};
#if 0
		static struct spi_board_info 
			spi_stm32_flash_info__dongle = {
			/*
			 * SPIDEV has precedence over Flash MTD
			 */
#if defined(CONFIG_SPI_SPIDEV)
			.modalias = "spidev",
#else
			.modalias = "m25p32",
			.platform_data = &spi_stm32_flash_data__dongle,
#endif
			.max_speed_hz = 25000000,
			.chip_select = 1,
			.controller_data = &spi_stm32_flash_slv__dongle,
			.mode = SPI_MODE_3,
      .bus_num = 4,
      .irq = -1,
		};
#endif

		/*
		 * Set up the Chip Select GPIO for the SPI Flash
		 */
		//gpio_direction_output(FLASH_GPIO_CS, 1);

		/*
		 * Register SPI slaves
		 */
		/*spi_register_board_info(&spi_stm32_flash_info__dongle,
			sizeof(spi_stm32_flash_info__dongle) /
			sizeof(struct spi_board_info)); */
#endif
  
  
#if defined(CONFIG_ENC28J60) || defined(CONFIG_SPI_SPIDEV)
		/*
 		 * SPI slave
 		 */
		static struct spi_stm32_slv spi_stm32_enc28j60_slv__stm32f4_som  = {
			.cs_gpio = SPI_ENC28J60_GPIO_CS,
      .exti_enable_int = enc28j60_exti_enable_int,
			.timeout = 3,
		};
    
#if 0   
		static struct spi_board_info 
			spi_stm32_enc28j60_info__stm32f4_som = {
			/*
			 * SPIDEV has precedence over Flash MTD
			 */
#if defined(CONFIG_SPI_SPIDEV)
			.modalias = "spidev",
#else
			.modalias = "enc28j60",
#endif
			.max_speed_hz = 12000000,
			.bus_num = 0,
			.chip_select = 0,
			.irq = -1, 
			.controller_data = &spi_stm32_enc28j60_slv__stm32f4_som,
      .platform_data = &spi_stm32_enc28j60_slv__stm32f4_som,
			.mode = SPI_MODE_0,
		};
#endif

		//printk("SPI_ENC28J60_CS_GPIO__STM32F4_SOM	= %ld" , SPI_ENC28J60_CS_GPIO__STM32F4_SOM);

    //stm32_exti_connect(ENC28J60_LINE_IRQ, ENC28J60_EXTI_GPIO);
   // stm32_exti_enable_int(ENC28J60_LINE_IRQ, 1); //line 4 : Enable
    //stm32_exti_set_falling(ENC28J60_LINE_IRQ);
		/*
		 * Set up the Chip Select GPIO for the SPI Flash
		 */
    gpio_request(SPI_ENC28J60_GPIO_CS,"ENC_CS");
		gpio_direction_output(SPI_ENC28J60_GPIO_CS, 1);
    gpio_request(SPI_ENC28J60_GPIO_PWR,"ENC_PWR");
    gpio_direction_output(SPI_ENC28J60_GPIO_PWR, 0); //Power on

		/*
		 * Register SPI slaves
		 */
		printk("enc28j60: spi_register_board_info\n");
    //spi_stm32_enc28j60_info__stm32f4_som.irq = gpio_to_irq(ENC28J60_GPIO_IRQ);
    //spi_stm32_enc28j60_info__stm32f4_som.irq = ENC28J60_GPIO_IRQ;
		//spi_register_board_info(&spi_stm32_enc28j60_info__stm32f4_som, sizeof(struct spi_board_info));
#endif

#if defined(CONFIG_TOUCHSCREEN_ADS7846) || defined(CONFIG_SPI_SPIDEV) \
      || defined(CONFIG_ENC28J60) || defined(CONFIG_MTD_M25P80)
		/*
 		 * SPI slave
 		 */
#if defined(CONFIG_TOUCHSCREEN_ADS7846) 
		static struct spi_stm32_slv spi_stm32_ads7846_slv_stm32f4  = {
			.cs_gpio = ADS7846_GPIO_CS,
			.timeout = 3,
		};
#endif

 
		static struct spi_board_info spi_stm32_disco_info[] = {
#if defined(CONFIG_TOUCHSCREEN_ADS7846)      
      {
        /*
         * SPIDEV has precedence over Flash MTD
         */
  #if defined(CONFIG_SPI_SPIDEV)
        .modalias = "spidev",
  #else
        .modalias = "ads7846",
        .platform_data = &ads_info,
  #endif
        .max_speed_hz = 1000000,
        .chip_select = 0,
        .controller_data = &spi_stm32_ads7846_slv_stm32f4,
        .mode = SPI_MODE_3,
        .bus_num = 4,
        .irq = ADS7846_GPIO_IRQ, //STM32_EXTI4_IRQn        
      },
#endif

#if defined(CONFIG_MTD_M25P80)  
      {
        /*
         * SPIDEV has precedence over Flash MTD
         */
  #if defined(CONFIG_SPI_SPIDEV)
        .modalias = "spidev",
  #else
        .modalias = "m25p32",
        .platform_data = &spi_stm32_flash_data__dongle,
  #endif
        .max_speed_hz = 25000000,
        .chip_select = 1,
        .controller_data = &spi_stm32_flash_slv__dongle,
        .mode = SPI_MODE_3,
        .bus_num = 4,
        .irq = -1,
      },
#endif

#if defined(CONFIG_ENC28J60) 
      {
        /*
         * SPIDEV has precedence over Flash MTD
         */
  #if defined(CONFIG_SPI_SPIDEV)
        .modalias = "spidev",
  #else
        .modalias = "enc28j60",
  #endif
        .max_speed_hz = 12000000,
        .bus_num = 0,
        .chip_select = 0,
        .irq = ENC28J60_GPIO_IRQ, 
        .controller_data = &spi_stm32_enc28j60_slv__stm32f4_som,
        .platform_data = &spi_stm32_enc28j60_slv__stm32f4_som,
        .mode = SPI_MODE_0,
      },
#endif

    };

//    gpio_direction_input(ADS7846_GPIO_IRQ); // PH4 - IRQ
/******************************************************************
 * Register SPI slaves
 ******************************************************************/
     
    for (i=0;i<sizeof(spi_stm32_disco_info) / sizeof(struct spi_board_info);i++)
    {
      printk("spi_info %d irq=%d\n",i,spi_stm32_disco_info[i].irq);
      if (spi_stm32_disco_info[i].irq != -1)
        spi_stm32_disco_info[i].irq = gpio_to_irq(spi_stm32_disco_info[i].irq);
    }
  
    // spi_stm32_touch_info.irq = 207; //ADS7846_GPIO_IRQ;
    //spi_stm32_disco_info.irq = gpio_to_irq(ADS7846_GPIO_IRQ);
    //printk("touch_info.irq=%d\n", spi_stm32_touch_info.irq);
		spi_register_board_info(spi_stm32_disco_info, 
    			sizeof(spi_stm32_disco_info) / sizeof(struct spi_board_info) );
#endif

    
#endif
	}
}


