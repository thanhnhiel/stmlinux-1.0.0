/*
 * (C) Copyright 2011, 2015
 *
 * Yuri Tikhonov, Emcraft Systems, yur@emcraft.com
 * Vladimir Skvortsov, Emcraft Systems, vskvortsov@emcraft.com
 * Alexander Potashev, Emcraft Systems, aspotashev@emcraft.com
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

/*
 * STM32 processor definitions
 */
#ifndef _MACH_STM32_H_
#define _MACH_STM32_H_

/******************************************************************************
 * Peripheral memory map
 ******************************************************************************/
#define PERIPH_BB_BASE         	((uint32_t)0x42000000) 		/*!< Peripheral base address in the bit-band region                                */
#define BKPSRAM_BB_BASE        	((uint32_t)0x42024000) 		/*!< Backup SRAM(4 KB) base address in the bit-band region                         */

#define STM32_PERIPH_BASE	0x40000000
#define STM32_APB1PERIPH_BASE	(STM32_PERIPH_BASE + 0x00000000)
#define STM32_APB2PERIPH_BASE	(STM32_PERIPH_BASE + 0x00010000)
#define STM32_AHB1PERIPH_BASE	(STM32_PERIPH_BASE + 0x00020000)
#define STM32_AHB2PERIPH_BASE	(STM32_PERIPH_BASE + 0x10000000)

/******************************************************************************
 * Reset and Clock Control
 ******************************************************************************/

/*
 * RCC register map
 */
struct stm32_rcc_regs {
	u32	cr;		/* RCC clock control			      */
	u32	pllcfgr;	/* RCC PLL configuration		      */
	u32	cfgr;		/* RCC clock configuration		      */
	u32	cir;		/* RCC clock interrupt			      */
	u32	ahb1rstr;	/* RCC AHB1 peripheral reset		      */
	u32	ahb2rstr;	/* RCC AHB2 peripheral reset		      */
	u32	ahb3rstr;	/* RCC AHB3 peripheral reset		      */
	u32	rsv0;
	u32	apb1rstr;	/* RCC APB1 peripheral reset		      */
	u32	apb2rstr;	/* RCC APB2 peripheral reset		      */
	u32	rsv1[2];
	u32	ahb1enr;	/* RCC AHB1 peripheral clock enable	      */
	u32	ahb2enr;	/* RCC AHB2 peripheral clock enable	      */
	u32	ahb3enr;	/* RCC AHB3 peripheral clock enable	      */
	u32	rsv2;
	u32	apb1enr;	/* RCC APB1 peripheral clock enable	      */
	u32	apb2enr;	/* RCC APB2 peripheral clock enable	      */
	u32	rsv3[2];
	u32	ahb1lpenr;	/* RCC AHB1 periph clk enable in low pwr mode */
	u32	ahb2lpenr;	/* RCC AHB2 periph clk enable in low pwr mode */
	u32	ahb3lpenr;	/* RCC AHB3 periph clk enable in low pwr mode */
	u32	rsv4;
	u32	apb1lpenr;	/* RCC APB1 periph clk enable in low pwr mode */
	u32	apb2lpenr;	/* RCC APB2 periph clk enable in low pwr mode */
	u32	rsv5[2];
	u32	bdcr;		/* RCC Backup domain control		      */
	u32	csr;		/* RCC clock control & status		      */
	u32	rsv6[2];
	u32	sscgr;		/* RCC spread spectrum clock generation	      */
	u32	plli2scfgr;	/* RCC PLLI2S configuration		      */

	/* Only for STM32F4{2,3}xxx and STM32F7 */
	u32	pllsaicfgr;	/* RCC PLLSAI configuration */
	u32	dckcfgr;	/* RCC Dedicated Clocks configuration */
};

/*
 * Clocks enumeration
 */
enum clock {
	CLOCK_SYSCLK,		/* SYSCLK clock frequency expressed in Hz     */
	CLOCK_HCLK,		/* HCLK clock frequency expressed in Hz       */
	CLOCK_PCLK1,		/* PCLK1 clock frequency expressed in Hz      */
	CLOCK_PCLK2,		/* PCLK2 clock frequency expressed in Hz      */
	CLOCK_SYSTICK,		/* Systimer clock frequency expressed in Hz   */
	CLOCK_DIVM,		/* Input clock for PLL, PLLI2S, PLLSAI in Hz */
	CLOCK_END		/* for internal usage			      */
};

/*
 * RCC registers base
 */
#define STM32_RCC_BASE			(STM32_AHB1PERIPH_BASE + 0x3800)
#define STM32_RCC			((volatile struct stm32_rcc_regs *) \
					STM32_RCC_BASE)
#define STM32_RCC_OFFSET     	(STM32_RCC_BASE - STM32_PERIPH_BASE)
#define STM32_CR_OFFSET         (STM32_RCC_OFFSET + 0x00)

/* Alias word address of PLLSAION bit */
#define PLLSAION_BitNumber   	0x1C
#define CR_PLLSAION_BB         (PERIPH_BB_BASE + (STM32_CR_OFFSET * 32) + (PLLSAION_BitNumber * 4))
					
/*
 * PWR registers map
 */
struct stm32_pwr_regs {
	u32 cr1;   /* power control register 1 */
	u32 csr1;  /* power control/status register 2 */
	u32 cr2;   /* power control register 2 */
	u32 csr2;  /* power control/status register 2 */
};


#define STM32_PWR_BASE			(STM32_APB1PERIPH_BASE + 0x7000)
#define STM32_PWR			((volatile struct stm32_pwr_regs *) \
					STM32_PWR_BASE)

/******************************************************************************
 * LCD-TFT Display Controller
 ******************************************************************************/

struct stm32_ltdc_regs {
	uint32_t reserved0[2];  /*!< Reserved, 0x00-0x04 */
	uint32_t sscr;          /*!< LTDC Synchronization Size Configuration Register,    Address offset: 0x08 */
  	uint32_t bpcr;          /*!< LTDC Back Porch Configuration Register,              Address offset: 0x0C */
  	uint32_t awcr;          /*!< LTDC Active Width Configuration Register,            Address offset: 0x10 */
  	uint32_t twcr;          /*!< LTDC Total Width Configuration Register,             Address offset: 0x14 */
  	uint32_t gcr;           /*!< LTDC Global Control Register,                        Address offset: 0x18 */
  	uint32_t reserved1[2];  /*!< Reserved, 0x1C-0x20 */
  	uint32_t srcr;          /*!< LTDC Shadow Reload Configuration Register,           Address offset: 0x24 */
  	uint32_t reserved2[1];  /*!< Reserved, 0x28 */
  	uint32_t bccr;          /*!< LTDC Background Color Configuration Register,        Address offset: 0x2C */
  	uint32_t reserved3[1];  /*!< Reserved, 0x30 */
  	uint32_t ier;           /*!< LTDC Interrupt Enable Register,                      Address offset: 0x34 */
  	uint32_t isr;           /*!< LTDC Interrupt Status Register,                      Address offset: 0x38 */
  	uint32_t icr;           /*!< LTDC Interrupt Clear Register,                       Address offset: 0x3C */
  	uint32_t lipcr;         /*!< LTDC Line Interrupt Position Configuration Register, Address offset: 0x40 */
  	uint32_t cpsr;          /*!< LTDC Current Position Status Register,               Address offset: 0x44 */
  	uint32_t cdsr;          /*!< LTDC Current Display Status Register,                       Address offset: 0x48 */
};
#define STM32F4_LTDC_BASE	(STM32_APB2PERIPH_BASE + 0x6800)
#define STM32_LTDC_BASE       	(STM32_APB2PERIPH_BASE + 0x6800)
#define STM32_LTDC			((volatile struct stm32_ltdc_regs *)STM32F4_LTDC_BASE)

/******************************************************************************
 * LCD-TFT Display layer x Controller
 ******************************************************************************/
struct stm32_ltdc_layer_regs
{
  	uint32_t cr;            /*!< LTDC Layerx Control Register                                  Address offset: 0x84 */
  	uint32_t whpcr;         /*!< LTDC Layerx Window Horizontal Position Configuration Register Address offset: 0x88 */
  	uint32_t wvpcr;         /*!< LTDC Layerx Window Vertical Position Configuration Register   Address offset: 0x8C */
  	uint32_t ckcr;          /*!< LTDC Layerx Color Keying Configuration Register               Address offset: 0x90 */
  	uint32_t pfcr;          /*!< LTDC Layerx Pixel Format Configuration Register               Address offset: 0x94 */
  	uint32_t cacr;          /*!< LTDC Layerx Constant Alpha Configuration Register             Address offset: 0x98 */
  	uint32_t dccr;          /*!< LTDC Layerx Default Color Configuration Register              Address offset: 0x9C */
  	uint32_t bfcr;          /*!< LTDC Layerx Blending Factors Configuration Register           Address offset: 0xA0 */
  	uint32_t reserved0[2];  /*!< Reserved */
  	uint32_t cfbar;         /*!< LTDC Layerx Color Frame Buffer Address Register               Address offset: 0xAC */
  	uint32_t cfblr;         /*!< LTDC Layerx Color Frame Buffer Length Register                Address offset: 0xB0 */
  	uint32_t cfblnr;        /*!< LTDC Layerx ColorFrame Buffer Line Number Register            Address offset: 0xB4 */
  	uint32_t reserved1[3];  /*!< Reserved */
  	uint32_t clutwr;        /*!< LTDC Layerx CLUT Write Register                               Address offset: 0x144 */
};

/*
 * LCD-TFT Display Layer x Controller base
 */
#define STM32_LTDC_LAYER1_BASE 		(STM32_LTDC_BASE + 0x084)
#define STM32_LTDC_LAYER2_BASE 		(STM32_LTDC_BASE + 0x104)
#define STM32_LTDC_LAYER1			((volatile struct stm32_ltdc_layer_regs *)STM32_LTDC_LAYER1_BASE)
#define STM32_LTDC_LAYER2			((volatile struct stm32_ltdc_layer_regs *)STM32_LTDC_LAYER2_BASE)

/******************************************************************************
 * Serial Peripheral Interface
 ******************************************************************************/
struct stm32_spi_regs
{
  	uint16_t cr1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
  	uint16_t reserved0;  /*!< Reserved, 0x02                                                           */
  	uint16_t cr2;        /*!< SPI control register 2,                             Address offset: 0x04 */
  	uint16_t reserved1;  /*!< Reserved, 0x06                                                           */
  	uint16_t sr;         /*!< SPI status register,                                Address offset: 0x08 */
  	uint16_t reserved2;  /*!< Reserved, 0x0A                                                           */
  	uint16_t dr;         /*!< SPI data register,                                  Address offset: 0x0C */
  	uint16_t reserved3;  /*!< Reserved, 0x0E                                                           */
  	uint16_t crcpr;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
  	uint16_t reserved4;  /*!< Reserved, 0x12                                                           */
  	uint16_t rxcrcr;     /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
  	uint16_t reserved5;  /*!< Reserved, 0x16                                                           */
  	uint16_t txcrcr;     /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
  	uint16_t reserved6;  /*!< Reserved, 0x1A                                                           */
  	uint16_t i2scfgr;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  	uint16_t reserved7;  /*!< Reserved, 0x1E                                                           */
  	uint16_t i2spr;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
  	uint16_t reserved8;  /*!< Reserved, 0x22                                                           */
};
/*
 * Serial Peripheral Interface base
 */
#define STM32_SPI5_BASE       	(STM32_APB2PERIPH_BASE + 0x5000)
#define STM32_SPI6_BASE       	(STM32_APB2PERIPH_BASE + 0x5400)
#define STM32_SPI5				((volatile struct stm32_spi_regs *)STM32_SPI5_BASE)
#define STM32_SPI6				((volatile struct stm32_spi_regs *)STM32_SPI6_BASE)



/******************************************************************************
 * FIXME: get rid of this
 ******************************************************************************/

/*
 * Return a clock value for the specified clock.
 * Note that we need this function in RAM because it will be used
 * during self-upgrade of U-boot into eNMV.
 * @param clck          id of the clock
 * @returns             frequency of the clock
 */
unsigned long  __attribute__((section(".ramcode")))
	       __attribute__ ((long_call))
	       clock_get(enum clock clck);

#define PAGE_SIZE	4096

#endif /* _MACH_STM32_H_ */
