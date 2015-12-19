/*
 * (C) Copyright (C) 2009
 * ARM Ltd.
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

#ifndef __ASM_ARCH_IRQS_H
#define __ASM_ARCH_IRQS_H

#if defined(CONFIG_ARCH_STM32F1)
#define NVIC_IRQS	68
#define STM32_GPIO_NUM	140
#else
#define NVIC_IRQS		91	/* STM32F42xxx, STM32F43xxx and others */
#define STM32_GPIO_NUM	168
#endif

#if defined(CONFIG_MFD_STMPE)
#define STMPE_IRQS		8	/* STM32F42 + 8 internal interrupts (stmpe811)*/
#else
#define STMPE_IRQS		0
#endif
#if defined (CONFIG_STM32_GPIO_INT)
#define NR_IRQS		(NVIC_IRQS + STM32_GPIO_NUM + STMPE_IRQS)
#else
#define NR_IRQS		(NVIC_IRQS + STMPE_IRQS)
#endif
#endif
