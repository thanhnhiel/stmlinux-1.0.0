/*
*********************************************************************************************************
*                                 ENDA PLC GROUP ILI9341 DRIVER MODULE	
*
*                            (c) Copyright 2012; Enda, Inc.; Istanbul, TR
*
*                   All rights reserved.  Protected by international copyright laws.
*                   Knowledge of the source code may not be used to write a similar
*                   product.  This file may only be used in accordance with a license
*                   and should not be redistributed in any way.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                        ILI9341 DRIVER MODULE
*
*                                             STM32F4XXX
*                                              with the
*                                             HMI Module
*
* Filename      : disp.c
* Version       : V1.00
* Developer(s) 	: tmk
*********************************************************************************************************
*/
#ifdef USE_STDPERIPH_DRIVER
  #include "stm32f4xx.h"
	#include "stm32.h"
	#include "stm32f2_gpio.h"
	#include "disp.h"
	
	#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))	
	
#ifdef USE_STDPERIPH_DRIVER
 #define NOP()	__nop()
#endif	
	
#else
	#include <common.h>
	#include <asm/arch/stm32.h>
	#include <asm/arch/stm32f2_gpio.h>
	#include <asm/arch/disp.h>
#endif


/*
*********************************************************************************************************
*                                             EXTERNAL FUNCTIONS
*********************************************************************************************************
*/

void udelay(unsigned long usec);


/*
*********************************************************************************************************
*                                             LOCAL DEFINITIONS
*********************************************************************************************************
*/


/******************************************************************************/
/*                                                                            */
/*                      LCD-TFT Display Controller (LTDC)                     */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for LTDC_SSCR register  *****************/

#define LTDC_SSCR_VSH                       ((uint32_t)0x000007FF)              /*!< Vertical Synchronization Height */
#define LTDC_SSCR_HSW                       ((uint32_t)0x0FFF0000)              /*!< Horizontal Synchronization Width */

/********************  Bit definition for LTDC_BPCR register  *****************/

#define LTDC_BPCR_AVBP                      ((uint32_t)0x000007FF)              /*!< Accumulated Vertical Back Porch */
#define LTDC_BPCR_AHBP                      ((uint32_t)0x0FFF0000)              /*!< Accumulated Horizontal Back Porch */

/********************  Bit definition for LTDC_AWCR register  *****************/

#define LTDC_AWCR_AAH                       ((uint32_t)0x000007FF)              /*!< Accumulated Active heigh */
#define LTDC_AWCR_AAW                       ((uint32_t)0x0FFF0000)              /*!< Accumulated Active Width */

/********************  Bit definition for LTDC_TWCR register  *****************/

#define LTDC_TWCR_TOTALH                    ((uint32_t)0x000007FF)              /*!< Total Heigh */
#define LTDC_TWCR_TOTALW                    ((uint32_t)0x0FFF0000)              /*!< Total Width */

/********************  Bit definition for LTDC_GCR register  ******************/

#define LTDC_GCR_LTDCEN                     ((uint32_t)0x00000001)              /*!< LCD-TFT controller enable bit */
#define LTDC_GCR_DBW                        ((uint32_t)0x00000070)              /*!< Dither Blue Width */
#define LTDC_GCR_DGW                        ((uint32_t)0x00000700)              /*!< Dither Green Width */
#define LTDC_GCR_DRW                        ((uint32_t)0x00007000)              /*!< Dither Red Width */
#define LTDC_GCR_DTEN                       ((uint32_t)0x00010000)              /*!< Dither Enable */
#define LTDC_GCR_PCPOL                      ((uint32_t)0x10000000)              /*!< Pixel Clock Polarity */
#define LTDC_GCR_DEPOL                      ((uint32_t)0x20000000)              /*!< Data Enable Polarity */
#define LTDC_GCR_VSPOL                      ((uint32_t)0x40000000)              /*!< Vertical Synchronization Polarity */
#define LTDC_GCR_HSPOL                      ((uint32_t)0x80000000)              /*!< Horizontal Synchronization Polarity */

/********************  Bit definition for LTDC_SRCR register  *****************/

#define LTDC_SRCR_IMR                      ((uint32_t)0x00000001)               /*!< Immediate Reload */
#define LTDC_SRCR_VBR                      ((uint32_t)0x00000002)               /*!< Vertical Blanking Reload */

/********************  Bit definition for LTDC_BCCR register  *****************/

#define LTDC_BCCR_BCBLUE                    ((uint32_t)0x000000FF)              /*!< Background Blue value */
#define LTDC_BCCR_BCGREEN                   ((uint32_t)0x0000FF00)              /*!< Background Green value */
#define LTDC_BCCR_BCRED                     ((uint32_t)0x00FF0000)              /*!< Background Red value */

/********************  Bit definition for LTDC_IER register  ******************/

#define LTDC_IER_LIE                        ((uint32_t)0x00000001)              /*!< Line Interrupt Enable */
#define LTDC_IER_FUIE                       ((uint32_t)0x00000002)              /*!< FIFO Underrun Interrupt Enable */
#define LTDC_IER_TERRIE                     ((uint32_t)0x00000004)              /*!< Transfer Error Interrupt Enable */
#define LTDC_IER_RRIE                       ((uint32_t)0x00000008)              /*!< Register Reload interrupt enable */

/********************  Bit definition for LTDC_ISR register  ******************/

#define LTDC_ISR_LIF                        ((uint32_t)0x00000001)              /*!< Line Interrupt Flag */
#define LTDC_ISR_FUIF                       ((uint32_t)0x00000002)              /*!< FIFO Underrun Interrupt Flag */
#define LTDC_ISR_TERRIF                     ((uint32_t)0x00000004)              /*!< Transfer Error Interrupt Flag */
#define LTDC_ISR_RRIF                       ((uint32_t)0x00000008)              /*!< Register Reload interrupt Flag */

/********************  Bit definition for LTDC_ICR register  ******************/

#define LTDC_ICR_CLIF                       ((uint32_t)0x00000001)              /*!< Clears the Line Interrupt Flag */
#define LTDC_ICR_CFUIF                      ((uint32_t)0x00000002)              /*!< Clears the FIFO Underrun Interrupt Flag */
#define LTDC_ICR_CTERRIF                    ((uint32_t)0x00000004)              /*!< Clears the Transfer Error Interrupt Flag */
#define LTDC_ICR_CRRIF                      ((uint32_t)0x00000008)              /*!< Clears Register Reload interrupt Flag */

/********************  Bit definition for LTDC_LIPCR register  ****************/

#define LTDC_LIPCR_LIPOS                    ((uint32_t)0x000007FF)              /*!< Line Interrupt Position */

/********************  Bit definition for LTDC_CPSR register  *****************/

#define LTDC_CPSR_CYPOS                     ((uint32_t)0x0000FFFF)              /*!< Current Y Position */
#define LTDC_CPSR_CXPOS                     ((uint32_t)0xFFFF0000)              /*!< Current X Position */

/********************  Bit definition for LTDC_CDSR register  *****************/

#define LTDC_CDSR_VDES                      ((uint32_t)0x00000001)              /*!< Vertical Data Enable Status */
#define LTDC_CDSR_HDES                      ((uint32_t)0x00000002)              /*!< Horizontal Data Enable Status */
#define LTDC_CDSR_VSYNCS                    ((uint32_t)0x00000004)              /*!< Vertical Synchronization Status */
#define LTDC_CDSR_HSYNCS                    ((uint32_t)0x00000008)              /*!< Horizontal Synchronization Status */

/********************  Bit definition for LTDC_LxCR register  *****************/

#define LTDC_LxCR_LEN                       ((uint32_t)0x00000001)              /*!< Layer Enable */
#define LTDC_LxCR_COLKEN                    ((uint32_t)0x00000002)              /*!< Color Keying Enable */
#define LTDC_LxCR_CLUTEN                    ((uint32_t)0x00000010)              /*!< Color Lockup Table Enable */

/********************  Bit definition for LTDC_LxWHPCR register  **************/

#define LTDC_LxWHPCR_WHSTPOS                ((uint32_t)0x00000FFF)              /*!< Window Horizontal Start Position */
#define LTDC_LxWHPCR_WHSPPOS                ((uint32_t)0xFFFF0000)              /*!< Window Horizontal Stop Position */

/********************  Bit definition for LTDC_LxWVPCR register  **************/

#define LTDC_LxWVPCR_WVSTPOS                ((uint32_t)0x00000FFF)              /*!< Window Vertical Start Position */
#define LTDC_LxWVPCR_WVSPPOS                ((uint32_t)0xFFFF0000)              /*!< Window Vertical Stop Position */

/********************  Bit definition for LTDC_LxCKCR register  ***************/

#define LTDC_LxCKCR_CKBLUE                  ((uint32_t)0x000000FF)              /*!< Color Key Blue value */
#define LTDC_LxCKCR_CKGREEN                 ((uint32_t)0x0000FF00)              /*!< Color Key Green value */
#define LTDC_LxCKCR_CKRED                   ((uint32_t)0x00FF0000)              /*!< Color Key Red value */

/********************  Bit definition for LTDC_LxPFCR register  ***************/

#define LTDC_LxPFCR_PF                      ((uint32_t)0x00000007)              /*!< Pixel Format */

/********************  Bit definition for LTDC_LxCACR register  ***************/

#define LTDC_LxCACR_CONSTA                  ((uint32_t)0x000000FF)              /*!< Constant Alpha */

/********************  Bit definition for LTDC_LxDCCR register  ***************/

#define LTDC_LxDCCR_DCBLUE                  ((uint32_t)0x000000FF)              /*!< Default Color Blue */
#define LTDC_LxDCCR_DCGREEN                 ((uint32_t)0x0000FF00)              /*!< Default Color Green */
#define LTDC_LxDCCR_DCRED                   ((uint32_t)0x00FF0000)              /*!< Default Color Red */
#define LTDC_LxDCCR_DCALPHA                 ((uint32_t)0xFF000000)              /*!< Default Color Alpha */
                                
/********************  Bit definition for LTDC_LxBFCR register  ***************/

#define LTDC_LxBFCR_BF2                     ((uint32_t)0x00000007)              /*!< Blending Factor 2 */
#define LTDC_LxBFCR_BF1                     ((uint32_t)0x00000700)              /*!< Blending Factor 1 */

/********************  Bit definition for LTDC_LxCFBAR register  **************/

#define LTDC_LxCFBAR_CFBADD                 ((uint32_t)0xFFFFFFFF)              /*!< Color Frame Buffer Start Address */

/********************  Bit definition for LTDC_LxCFBLR register  **************/

#define LTDC_LxCFBLR_CFBLL                  ((uint32_t)0x00001FFF)              /*!< Color Frame Buffer Line Length */
#define LTDC_LxCFBLR_CFBP                   ((uint32_t)0x1FFF0000)              /*!< Color Frame Buffer Pitch in bytes */

/********************  Bit definition for LTDC_LxCFBLNR register  *************/

#define LTDC_LxCFBLNR_CFBLNBR               ((uint32_t)0x000007FF)              /*!< Frame Buffer Line Number */

/********************  Bit definition for LTDC_LxCLUTWR register  *************/

#define LTDC_LxCLUTWR_BLUE                  ((uint32_t)0x000000FF)              /*!< Blue value */
#define LTDC_LxCLUTWR_GREEN                 ((uint32_t)0x0000FF00)              /*!< Green value */
#define LTDC_LxCLUTWR_RED                   ((uint32_t)0x00FF0000)              /*!< Red value */
#define LTDC_LxCLUTWR_CLUTADD               ((uint32_t)0xFF000000)              /*!< CLUT address */


/*
 *  External GPIOs for TFT :
 +------------------------+-----------------------+----------------------------+
 +                       LCD pins assignment                                   +
 +------------------------+-----------------------+----------------------------+
 |  LCD_TFT R2 <-> PC.10  |  LCD_TFT G2 <-> PA.06 |  LCD_TFT B2 <-> PD.06      |
 |  LCD_TFT R3 <-> PB.00  |  LCD_TFT G3 <-> PG.10 |  LCD_TFT B3 <-> PG.11      |
 |  LCD_TFT R4 <-> PA.11  |  LCD_TFT G4 <-> PB.10 |  LCD_TFT B4 <-> PG.12      |
 |  LCD_TFT R5 <-> PA.12  |  LCD_TFT G5 <-> PB.11 |  LCD_TFT B5 <-> PA.03      |
 |  LCD_TFT R6 <-> PB.01  |  LCD_TFT G6 <-> PC.07 |  LCD_TFT B6 <-> PB.08      |
 |  LCD_TFT R7 <-> PG.06  |  LCD_TFT G7 <-> PD.03 |  LCD_TFT B7 <-> PB.09      |
 -------------------------------------------------------------------------------
          |  LCD_TFT HSYNC <-> PC.06  | LCDTFT VSYNC <->  PA.04 |
          |  LCD_TFT CLK   <-> PG.07  | LCD_TFT DE   <->  PF.10 |
           -----------------------------------------------------

*/

struct stm32f2_gpio_dsc_ext {
	struct stm32f2_gpio_dsc stm32f2_gpio;
	enum stm32f2_gpio_role  role;	/* GPIO role					*/
};

static const struct stm32f2_gpio_dsc_ext ext_tft_gpio[] = {
	/* R */
	{{STM32F2_GPIO_PORT_B, STM32F2_GPIO_PIN_0}, STM32F2_GPIO_ROLE_LTDC0},			// R3
	{{STM32F2_GPIO_PORT_B, STM32F2_GPIO_PIN_1}, STM32F2_GPIO_ROLE_LTDC0},			// R6	

	{{STM32F2_GPIO_PORT_H, STM32F2_GPIO_PIN_8}, STM32F2_GPIO_ROLE_LTDC1},			// R2
	{{STM32F2_GPIO_PORT_H, STM32F2_GPIO_PIN_10}, STM32F2_GPIO_ROLE_LTDC1},		// R4
	{{STM32F2_GPIO_PORT_H, STM32F2_GPIO_PIN_11}, STM32F2_GPIO_ROLE_LTDC1},		// R5
	{{STM32F2_GPIO_PORT_G, STM32F2_GPIO_PIN_6}, STM32F2_GPIO_ROLE_LTDC1},			// R7

	/* G */
	{{STM32F2_GPIO_PORT_H, STM32F2_GPIO_PIN_13}, STM32F2_GPIO_ROLE_LTDC1},
	{{STM32F2_GPIO_PORT_H, STM32F2_GPIO_PIN_14}, STM32F2_GPIO_ROLE_LTDC1},
	{{STM32F2_GPIO_PORT_B, STM32F2_GPIO_PIN_10}, STM32F2_GPIO_ROLE_LTDC1},
	{{STM32F2_GPIO_PORT_I, STM32F2_GPIO_PIN_0}, STM32F2_GPIO_ROLE_LTDC1},
	{{STM32F2_GPIO_PORT_I, STM32F2_GPIO_PIN_1}, STM32F2_GPIO_ROLE_LTDC1},
	{{STM32F2_GPIO_PORT_I, STM32F2_GPIO_PIN_2}, STM32F2_GPIO_ROLE_LTDC1},

	/* B */
	{{STM32F2_GPIO_PORT_D, STM32F2_GPIO_PIN_6}, STM32F2_GPIO_ROLE_LTDC1},
	{{STM32F2_GPIO_PORT_G, STM32F2_GPIO_PIN_11}, STM32F2_GPIO_ROLE_LTDC1},
	{{STM32F2_GPIO_PORT_I, STM32F2_GPIO_PIN_4}, STM32F2_GPIO_ROLE_LTDC1},
	{{STM32F2_GPIO_PORT_A, STM32F2_GPIO_PIN_3}, STM32F2_GPIO_ROLE_LTDC1},
	{{STM32F2_GPIO_PORT_B, STM32F2_GPIO_PIN_8}, STM32F2_GPIO_ROLE_LTDC1}, //
	{{STM32F2_GPIO_PORT_B, STM32F2_GPIO_PIN_9}, STM32F2_GPIO_ROLE_LTDC1},

	/* CONTROL */
	{{STM32F2_GPIO_PORT_I, STM32F2_GPIO_PIN_9}, STM32F2_GPIO_ROLE_LTDC1},		// VSYNC
	{{STM32F2_GPIO_PORT_I, STM32F2_GPIO_PIN_10}, STM32F2_GPIO_ROLE_LTDC1}, 	// HSYNC
	{{STM32F2_GPIO_PORT_F, STM32F2_GPIO_PIN_10}, STM32F2_GPIO_ROLE_LTDC1},	// ENABLE
	{{STM32F2_GPIO_PORT_G, STM32F2_GPIO_PIN_7}, STM32F2_GPIO_ROLE_LTDC1},		// DOTCLK

	// Command port definitions
	{{STM32F2_GPIO_PORT_F, STM32F2_GPIO_PIN_7}, STM32F2_GPIO_ROLE_SPI5  },	// SCK
	{{STM32F2_GPIO_PORT_F, STM32F2_GPIO_PIN_8}, STM32F2_GPIO_ROLE_SPI5  },	// MISO
	{{STM32F2_GPIO_PORT_F, STM32F2_GPIO_PIN_9}, STM32F2_GPIO_ROLE_SPI5  },	// MOSI

	{{STM32F2_GPIO_PORT_F, STM32F2_GPIO_PIN_6}, STM32F2_GPIO_ROLE_GPOUT },	// 25 (L_CS)
	{{STM32F2_GPIO_PORT_I, STM32F2_GPIO_PIN_3}, STM32F2_GPIO_ROLE_GPOUT },	// 26 (F_CS)
	{{STM32F2_GPIO_PORT_H, STM32F2_GPIO_PIN_5}, STM32F2_GPIO_ROLE_GPOUT },	// 27 (T_CS)
//	{{STM32F2_GPIO_PORT_H, STM32F2_GPIO_PIN_4}, STM32F2_GPIO_ROLE_GPIN },	// 28 (T_IRQ)
};


#define LCD_SPI        			STM32_SPI5
#define LCD_SpiClkEnable()   	STM32_RCC->apb2enr |=  ((uint32_t)0x00100000)
#define LCD_SpiClkDisable()		STM32_RCC->apb2enr &= ~((uint32_t)0x00100000)
#define LCD_SpiPeripReset()		do { STM32_RCC->apb2rstr |=  ((uint32_t)0x00100000);\
									 STM32_RCC->apb2rstr &= ~((uint32_t)0x00100000); } while (0)

//
// H/V front/backporch and synchronization width/height
//
#define HSYNC		16 			
#define HBP			(52) 	
#define LCD_W		320 	
#define HFP			(20) 	

#define VSYNC		2 	
#define VBP			(16) // 30 	
#define LCD_H		240 
#define VFP			(4) 	

#define LCD_DISP_W		320
#define LCD_DISP_H		240 

//Calculator
#define AccumulatedHBP (HSYNC + HBP)
#define AccumulatedVBP (VSYNC + VBP)
#define AccumulatedActiveW (HSYNC + HBP + LCD_DISP_W)
#define AccumulatedActiveH (VSYNC + VBP + LCD_DISP_H)
#define TotalWidth	(HSYNC + HBP + LCD_W + HFP)
#define TotalHeigh (VSYNC + VBP + LCD_H + VFP)	

/*
*********************************************************************************************************
*                                             LOCAL MACROS
*********************************************************************************************************
*/

#define LCS_LO()	stm32f2_gpout_set(&ext_tft_gpio[25].stm32f2_gpio, 0)		// chip selected
#define LCS_HI()	stm32f2_gpout_set(&ext_tft_gpio[25].stm32f2_gpio, 1)		// chip de-selected
#define FCS_HI()	stm32f2_gpout_set(&ext_tft_gpio[26].stm32f2_gpio, 1)		// chip de-selected
#define TCS_HI()	stm32f2_gpout_set(&ext_tft_gpio[27].stm32f2_gpio, 1)		// chip de-selected

#ifndef NOP
#define NOP()	asm("nop")
#endif

#define CMD_REG()	\
					NOP();		\
					NOP();

#define DAT_REG()	\
					NOP();		\
					NOP();

#define CHIP_ENB()	LCS_LO();	\
					NOP();		\
					NOP();		\
					NOP();

#define CHIP_DSB()	udelay(500);\
					LCS_HI();	\
					NOP();		\
					NOP();		\
					NOP();		\
					NOP();		\
					NOP();		\
					NOP();		\
					NOP();		\
					NOP();		\
					NOP();		\
					NOP();


/*******************************************************************************
* Function Name  : spiDataWrite
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
static void spiDataWrite(uint16_t ulTxData)
{
	volatile uint16_t Tmp;

	// Set the Tx only mode
	LCD_SPI->cr1 |= 0x4000;

	// Enable SPI
	LCD_SPI->cr1 |= 0x0040;
	
	// Send byte through the SPI peripheral
	LCD_SPI->dr = ulTxData;

	// Loop while DR register in not emplty
	while (!((Tmp=LCD_SPI->sr) & 0x0002));

	// Loop while bus is busy
	while ((Tmp=LCD_SPI->sr) & 0x0080);
	
	// clear the Rx buffer
	Tmp = LCD_SPI->dr;

	// Disable SPI
	LCD_SPI->cr1 &= 0xFFBF;
}//spiDataWrite


/*******************************************************************************
* Function Name  : spiDataRead
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
static uint16_t spiDataRead(void)
{
	volatile uint16_t Tmp;

	// Set the Rx only mode
	LCD_SPI->cr1 &= 0xBFFF;
	
	// Enable the SPI
	LCD_SPI->cr1 |= 0x0040;

	// Loop while DR register in not emplty
	while (!((Tmp=LCD_SPI->sr) & 0x0001));
	
	// get the received data
	Tmp = LCD_SPI->dr;

	// Disable SPI
	LCD_SPI->cr1 &= 0xFFBF;

	// return the received data
	return Tmp;
}//spiDataRead


/*******************************************************************************
* Function Name  : LCD_WriteIndex
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
static void LCD_WriteIndex(uint16_t index)
{
	// select the chip
	CHIP_ENB();
	
	// send command
	spiDataWrite(0x70); // select command register
	spiDataWrite((index>>8) & 0xFF );
	spiDataWrite(index & 0xFF);
	
	// de-select the chip
	CHIP_DSB();
}//LCD_WriteIndex


/*******************************************************************************
* Function Name  : LCD_WriteData
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
static void LCD_WriteData(uint16_t Data)
{
	// select the chip
	CHIP_ENB();
	
	// send command
	spiDataWrite(0x72); // select command register
	spiDataWrite((Data>>8) & 0xFF );
	spiDataWrite(Data & 0xFF);
	
	// de-select the chip
	CHIP_DSB();
}//LCD_WriteData


/*******************************************************************************
* Function Name  : ReadData
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
static uint8_t ReadData(void)
{
	// select data register

	// read the data
	return spiDataRead();
}//ReadData


/*******************************************************************************
* Function Name  : lcd_init
* Description	 : None
* Input 		 : None
* Output		 : None
* Return		 : None
*******************************************************************************/
static void lcd_init(void)
{
	LCD_WriteIndex(0x01);
	LCD_WriteData(0x7380);
	
	LCD_WriteIndex(0x01);
	LCD_WriteData(0x7380);
	//nOTP=1,VCM=1010000b	
	LCD_WriteIndex(0x1E);
	LCD_WriteData(0x00d0);	
	//nOTP=1,VCM=1010000b
	LCD_WriteIndex(0x05);	//REG[1Eh] power control 4
	LCD_WriteData(0xbcc4);	//REG[05h] function control
	//DEP=1
}//lcd_init


/*******************************************************************************
* Function Name  : disp_close
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void disp_close(void)
{

}//disp_close

void initPort(void)
{
	disp_open(0xC1E0000);	
	disp_on();
}
/*******************************************************************************
* Function Name  : disp_open
* Description    : Initializes and configures the Display
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int disp_open(uint32_t FBAddr)
{
	int i, rv = 0;

	//-------------------------------------------------------------------------
	// Initialize the SDRAM
	//-------------------------------------------------------------------------
	//fmc_dram_init();
	
	//-------------------------------------------------------------------------
	// Connect GPIOs to FMC controller
	//-------------------------------------------------------------------------
	for (i = 0; i < ARRAY_SIZE(ext_tft_gpio); i++)
	{
		rv = stm32f2_gpio_config(&ext_tft_gpio[i].stm32f2_gpio, ext_tft_gpio[i].role);
		if (rv != 0)
			return -1;
	}//for
	FCS_HI();	
	TCS_HI();	
	
	//-------------------------------------------------------------------------
	// Configure the LCD_SPI interface
	//-------------------------------------------------------------------------

	// Enable SPI clock
	LCD_SpiClkEnable();

	// Reset SPI peripheral
	LCD_SpiPeripReset();

	// SPI Config
	LCD_SPI->cr1 = 0x033F;
	LCD_SPI->i2scfgr &= ~((uint16_t)0x0800);
	LCD_SPI->crcpr = 7;

	// SPI enable
	LCD_SPI->cr1 |= 0x0040;
	//-------------------------------------------------------------------------

	// LCD low level initializing
	lcd_init();
	
	// SPI disable
	LCD_SPI->cr1 &= (uint16_t)~((uint16_t)0x0040);
	
	// SPI Config for Touch
	LCD_SPI->cr1 = 0x033C;
	LCD_SPI->i2scfgr &= ~((uint16_t)0x0800);
	LCD_SPI->crcpr = 7;	
	
	// SPI enable
	LCD_SPI->cr1 |= 0x0040;		
	//-------------------------------------------------------------------------
	
	// Enable the LTDC Clock
	STM32_RCC->apb2enr |= ((uint32_t)0x04000000);

	// Enable the DMA2D Clock
	STM32_RCC->ahb1enr |= ((uint32_t)0x00800000);

	// Configure PLLSAI prescalers for LCD
	// Enable Pixel Clock
    /* PLLSAI_VCO Input = HSE_VALUE/PLL_M = 1 Mhz */
    /* PLLSAI_VCO Output = PLLSAI_VCO Input * PLLSAI_N = 192 Mhz */
    /* PLLLCDCLK = PLLSAI_VCO Output/PLLSAI_R = 192/3 = 64 Mhz */
    /* LTDC clock frequency = PLLLCDCLK / RCC_PLLSAIDivR = 64/8 = 8 Mhz */
	STM32_RCC->pllsaicfgr = (192 << 6) | (7 << 24) | (3 << 28);

	STM32_RCC->dckcfgr &= ~0x00030000;
	STM32_RCC->dckcfgr |=  0x00020000;

	// Enable PLLSAI Clock
	*((volatile uint32_t *)CR_PLLSAION_BB) = 1;

	// Wait for PLLSAI activation
	while ((STM32_RCC->cr & 0x20000000) == 0);

	//-------------------------------------------------------------------------
	// LTDC Configuration
	//-------------------------------------------------------------------------
	STM32_LTDC->sscr &= ~(LTDC_SSCR_VSH | LTDC_SSCR_HSW);
	STM32_LTDC->sscr |= ((HSYNC-1)<<16 | (VSYNC-1));

	STM32_LTDC->bpcr &= ~(LTDC_BPCR_AVBP | LTDC_BPCR_AHBP);
	STM32_LTDC->bpcr |= (((AccumulatedHBP-1)<<16) | (AccumulatedVBP-1));

	STM32_LTDC->awcr &= ~(LTDC_AWCR_AAH | LTDC_AWCR_AAW);
	STM32_LTDC->awcr |= ((AccumulatedActiveW-1)<<16 | (AccumulatedActiveH-1));

	STM32_LTDC->twcr &= ~(LTDC_TWCR_TOTALH | LTDC_TWCR_TOTALW);
	STM32_LTDC->twcr |= ((TotalWidth-1)<<16 | (TotalHeigh-1));

	STM32_LTDC->gcr &= ((uint32_t)0x0FFE888F);

	STM32_LTDC->bccr &= ~(LTDC_BCCR_BCBLUE | LTDC_BCCR_BCGREEN | LTDC_BCCR_BCRED);

	//-------------------------------------------------------------------------
	// Layer configuration
	//-------------------------------------------------------------------------
	STM32_LTDC_LAYER1->whpcr &= ~(LTDC_LxWHPCR_WHSTPOS | LTDC_LxWHPCR_WHSPPOS);
	STM32_LTDC_LAYER1->whpcr  = ((LCD_DISP_W + HSYNC + HBP - 1)<<16 | (HSYNC + HBP));

	STM32_LTDC_LAYER1->wvpcr &= ~(LTDC_LxWVPCR_WVSTPOS | LTDC_LxWVPCR_WVSPPOS);
	STM32_LTDC_LAYER1->wvpcr  = ((LCD_DISP_H + VSYNC + VBP -1)<<16 | (VSYNC + VBP));
/* Set pixel format to ARGB8888 */
	STM32_LTDC_LAYER1->pfcr  &= ~(LTDC_LxPFCR_PF);
	STM32_LTDC_LAYER1->pfcr   = 2;

	STM32_LTDC_LAYER1->dccr  &=  ~(LTDC_LxDCCR_DCBLUE | LTDC_LxDCCR_DCGREEN | LTDC_LxDCCR_DCRED | LTDC_LxDCCR_DCALPHA);
	STM32_LTDC_LAYER1->dccr   = 0x00000000;

	STM32_LTDC_LAYER1->cacr  &= ~(LTDC_LxCACR_CONSTA);
	STM32_LTDC_LAYER1->cacr   = 255;

	STM32_LTDC_LAYER1->bfcr  &= ~(LTDC_LxBFCR_BF2 | LTDC_LxBFCR_BF1);
	STM32_LTDC_LAYER1->bfcr   = (0x00000600 | 0x00000007); //0x00000400 | 0x00000005 //(1024 | 5);

	STM32_LTDC_LAYER1->cfbar &= ~(LTDC_LxCFBAR_CFBADD);
	STM32_LTDC_LAYER1->cfbar  = FBAddr;

	STM32_LTDC_LAYER1->cfblr &= ~(LTDC_LxCFBLR_CFBLL | LTDC_LxCFBLR_CFBP);
	STM32_LTDC_LAYER1->cfblr  = ((LCD_DISP_W*2)<<16 | (LCD_DISP_W*2 + 3 ));

	STM32_LTDC_LAYER1->cfblnr &= ~(LTDC_LxCFBLNR_CFBLNBR);
	STM32_LTDC_LAYER1->cfblnr  = LCD_DISP_H;
	
	STM32_LTDC->gcr |= ((uint32_t)LTDC_GCR_DTEN);
	STM32_LTDC_LAYER1->cr |= ((uint32_t)LTDC_LxCR_LEN);
	STM32_LTDC->srcr = (uint32_t)LTDC_SRCR_IMR;

	//-------------------------------------------------------------------------
	// Enable The LCD
	//-------------------------------------------------------------------------
	STM32_LTDC->gcr |= ((uint32_t)LTDC_GCR_LTDCEN);
	
  	// enable the TFT/LCD controller
	STM32_LTDC->gcr |= LTDC_GCR_LTDCEN;
	return 0;
}//disp_open


/*******************************************************************************
* Function Name  : disp_on
* Description	 : Enables the Display
* Input 		 : None
* Output		 : None
* Return		 : None
*******************************************************************************/
void disp_on(void)
{
  	// enable the TFT/LCD controller
	STM32_LTDC->gcr |= LTDC_GCR_LTDCEN;
}//disp_on


/*******************************************************************************
* Function Name  : disp_off
* Description	 : Disables the Display
* Input 		 : None
* Output		 : None
* Return		 : None
*******************************************************************************/
void disp_off(void)
{
	// disable the TFT/LCD controller
	STM32_LTDC->gcr &= ~LTDC_GCR_LTDCEN;
}//disp_off


/*******************************************************************************
* Function Name  : disp_setbuf
* Description	 : Set the Display frame buffer
* Input 		 : None
* Output		 : None
* Return		 : None
*******************************************************************************/
void disp_setbuf(void *FrameBuf)
{
	// Configures the color frame buffer start address
	STM32_LTDC_LAYER1->cfbar = (uint32_t)FrameBuf;

	// Sets the Reload type
	STM32_LTDC->srcr = LTDC_SRCR_IMR;
}//disp_setbuf


/*******************************************************************************
* Function Name  : disp_fill
* Description	 : Fill the Display with a specified color
* Input 		 : None
* Output		 : None
* Return		 : None
*******************************************************************************/
void disp_fill(uint32_t FBAddr, uint16_t col)
{
	uint16_t *p = (uint16_t*)FBAddr;
	uint16_t x, y;

	for (y=0; y<DISP_YRES; y++)
		for (x=0; x<DISP_XRES; x++)
			p[y*DISP_XRES+x] = col;
}//disp_fill

#ifdef USE_STDPERIPH_DRIVER
void udelay(unsigned long usec)
{
  __IO uint32_t index = 0; 
  for(index = (8 * usec); index != 0; index--)
  {
  }
}
#endif
