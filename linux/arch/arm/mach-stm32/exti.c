/*
 * (C) Copyright 2012-2015
 * Emcraft Systems, <www.emcraft.com>
 * Alexander Potashev <aspotashev@emcraft.com>
 * Vladimir Khusainov <vlad@emcraft.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <linux/module.h>
#include <linux/io.h>
#include <mach/exti.h>

#if 0
#define DEBUG
#endif




/*
 * EXTI control and status registers
 */
struct stm32_exti_regs {
	u32 imr;	/* Interrupt mask register */
	u32 emr;	/* Event mask register */
	u32 rtsr;	/* Rising trigger selection register */
	u32 ftsr;	/* Falling trigger selection register */
	u32 swier;	/* Software interrupt event register */
	u32 pr;		/* Pending register */
};

/*
 * EXTI register map base
 */
#define STM32_EXTI_BASE		0x40013c00
#define STM32_EXTI		((volatile struct stm32_exti_regs *) \
				STM32_EXTI_BASE)

/*
 * EXTI-related SYSCFG control and status registers
 */
struct stm32_exti_syscfg_regs {
	u32 rsvd[2];	/* Reserved */
	u32 exticr[4];	/* External interrupt config registers */
};

/*
 * EXTI register map base
 */
#define STM32_EXTI_SYSCFG_BASE	0x40013800
#define STM32_EXTI_SYSCFG	((volatile struct stm32_exti_syscfg_regs *) \
				STM32_EXTI_SYSCFG_BASE)

/*
 * connect an exti line to a specified STM32 pin
 * @line	EXTI line
 * @pin		pin: port within the range for this line (0..15)A->L
 */
void stm32_exti_connect(unsigned int line, int pin)
{
  u32 tmp = 0x00;

  tmp = ((u32)0x0F) << (0x04 * (line & (u8)0x03));
  STM32_EXTI_SYSCFG->exticr[line >> 0x02] &= ~tmp;
  STM32_EXTI_SYSCFG->exticr[line >> 0x02] |= (((u32)pin) << (0x04 * (line & (u8)0x03)));
  
#if defined(DEBUG)
	printk("%s:%d,%d=%d,%d,%x\n", __func__, line, pin, line >> 0x02, (0x04 * (line & (u8)0x03)),
		readl(&STM32_EXTI_SYSCFG->exticr[line >> 0x02]));
#endif
}
EXPORT_SYMBOL(stm32_exti_connect);



/*
 * Enable or disable interrupt on the rising edge of a event line
 */
void stm32_exti_enable_int(unsigned int line, int enable)
{
	if (line >= STM32F2_EXTI_NUM_LINES)
		goto out;

	if (enable) {
		stm32_exti_clear_pending(line);
    
    //stm32_exti_connect(line, EXTI_PortSourceGPIOH);

		/* Enable trigger on rising edge */
		//STM32_EXTI->rtsr |= (1 << line);
		/* Disable trigger on falling edge */
		//STM32_EXTI->ftsr &= ~(1 << line);

    
		stm32_exti_clear_pending(line);

		/* Enable interrupt for the event */
    STM32_EXTI->imr |= (1 << line);
		//writel(readl(&STM32_EXTI->imr) | (1 << line),
		//	&STM32_EXTI->imr);    
	} else {
		/* Disable interrupt for the event */
		STM32_EXTI->imr &= ~(1 << line);
		/* Disable trigger on rising edge */
		STM32_EXTI->rtsr &= ~(1 << line);
		/* Disable trigger on falling edge */
		STM32_EXTI->ftsr &= ~(1 << line);

		stm32_exti_clear_pending(line);
	}

out:
	;
}
EXPORT_SYMBOL(stm32_exti_enable_int);

void stm32_exti_gen_sw_irq(unsigned int  line)
{
  STM32_EXTI->swier |=  1<<line;
}
EXPORT_SYMBOL(stm32_exti_gen_sw_irq);


/*
 * set rising trigger
 * @line	EXTI line
 */
void stm32_exti_set_rising(unsigned int line)
{
	/* Enable trigger on rising edge */
	//writel(readl(&STM32_EXTI->rtsr) | (1 << line), &STM32_EXTI->rtsr);
  u32 tmp = 0;
  u32 exti_Line = 1<<line;

  tmp = (u32)STM32_EXTI_BASE;
  tmp += 0x08; // 0x08 : EXTI_Trigger_Rising, EXTI_Trigger_Falling = 0x0C
  *(volatile u32 *) tmp |= exti_Line;
#if defined(DEBUG)
	printk("%s:%d=%x\n", __func__, line, readl(&STM32_EXTI->rtsr));
#endif
}
EXPORT_SYMBOL(stm32_exti_set_rising);

/*
 * set falling trigger
 * @line	EXTI line
 */
void stm32_exti_set_falling(unsigned int line)
{
	/* Enable trigger on falling edge */
	//writel(readl(&STM32_EXTI->ftsr) | (1 << line), &STM32_EXTI->ftsr);
  
  u32 tmp = 0;
  u32 exti_Line = 1<<line;

  tmp = (u32)STM32_EXTI_BASE;
  tmp += 0x0C; // 0x08 : EXTI_Trigger_Rising, EXTI_Trigger_Falling = 0x0C
  *(volatile u32 *) tmp |= exti_Line;
#if defined(DEBUG)
	printk("%s:%d=%x\n", __func__, line, readl(&STM32_EXTI->ftsr));
#endif
}
EXPORT_SYMBOL(stm32_exti_set_falling);

/*
 * get the bit mask of pending EXTI interrupts
 * @ret		current value of the PR register
 */
unsigned long stm32_exti_get_pending(void)
{
	unsigned long ret = readl(&STM32_EXTI->pr);

#if defined(DEBUG)
	printk("%s:%lx\n", __func__, ret);
#endif
	return ret;
}
EXPORT_SYMBOL(stm32_exti_get_pending);

/*
 * clear the pending state of an EXTI event
 * @line	EXTI line
 */
void stm32_exti_clear_pending(unsigned int line)
{
  #if 0
	writel(1 << line, &STM32_EXTI->pr);
  #endif
  u32 tmp = 0;
  u32 exti_Line = 1<<line;

  tmp = (u32)STM32_EXTI_BASE + 5*4;
  
  *(volatile u32 *) tmp = exti_Line;

#if defined(DEBUG)
	printk("%s:%d=%x\n", __func__, line, readl(&STM32_EXTI->pr));
#endif
}
EXPORT_SYMBOL(stm32_exti_clear_pending);
