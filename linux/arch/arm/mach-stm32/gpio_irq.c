#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/delay.h>
#include <linux/wait.h>
#include <linux/timer.h>

/* For GPIO and interrupt */
#include <linux/gpio.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <mach/exti.h>



#define ENABLE      1
#define ENC28J60_EXTI_GPIO    2   // PH4 : 7,4. PC4 : 2,4
#define ENC28J60_LINE_IRQ     4
#define ENC28J60_GPIO_IRQ     STM32_GPIO_PORTPIN2NUM( \
                                ENC28J60_EXTI_GPIO,\
                                ENC28J60_LINE_IRQ)

static int irq;

static irqreturn_t gpio_irq_handler (int irq, void *dev_id)
{
  printk ("gpio_irq: gpio isr handler in irq %d\n", irq);

  stm32_exti_clear_pending(ENC28J60_LINE_IRQ);

	return IRQ_HANDLED;
}

static int gpio_irq_init(void)
{
	int ret;
  
  ret = gpio_request(ENC28J60_GPIO_IRQ,"ENC28J60_GPIO_IRQ");
  
  if (ret) {
		printk("gpio_irq: failed to request gpio: %d\n", ret);
		return 0;
	}
  
  irq = gpio_to_irq(ENC28J60_GPIO_IRQ);
  printk("gpio_irq: IRQ = %d\n", irq);

	ret = request_irq(irq, gpio_irq_handler,
				   IRQF_ONESHOT,
				   "gpio_irq", NULL);
           
	if (ret) {
		printk("gpio_irq_init: IRQ %d not free. Error = %d\n", irq, ret);
		return 0;
	}

	/* Enable the exti interrupt if this callback is available. */
  stm32_exti_connect(ENC28J60_LINE_IRQ, ENC28J60_EXTI_GPIO);
	stm32_exti_enable_int(ENC28J60_LINE_IRQ, ENABLE);
    
  return 0;
}


static void gpio_irq_exit(void)
{
   printk ("gpio_irq: exit gpio_irq module\n");
   free_irq  (irq, NULL);
   gpio_free (ENC28J60_GPIO_IRQ);

}

module_init(gpio_irq_init);
module_exit(gpio_irq_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("thanhnhi");
MODULE_DESCRIPTION("gpio irq example");
