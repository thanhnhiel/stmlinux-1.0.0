#include <common.h>
#include <clock.h>
#include <malloc.h>
#include <spi.h>

#include <common.h>
#include <asm/arch/stm32.h>
#include <asm/arch/stm32f2_gpio.h>
#include <asm/arch/disp.h>



#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

/*
 * Private data structure for an SPI slave
 */
 
struct stm_spi_slave {
	struct spi_slave	slave;		/* Generic slave */
	u32			hz;		/* SPI bus rate */
	u32			mode;		/* SPI bus mode */
};

struct stm32f2_gpio_dsc_ext {
	struct stm32f2_gpio_dsc stm32f2_gpio;
	enum stm32f2_gpio_role  role;	/* GPIO role					*/
};


/* Control Register bits definition */
#define SPI_I2S_FLAG_RXNE               ((u16)0x0001)
#define SPI_I2S_FLAG_TXE                ((u16)0x0002)
#define I2S_FLAG_CHSIDE                 ((u16)0x0004)
#define I2S_FLAG_UDR                    ((u16)0x0008)
#define SPI_FLAG_CRCERR                 ((u16)0x0010)
#define SPI_FLAG_MODF                   ((u16)0x0020)
#define SPI_I2S_FLAG_OVR                ((u16)0x0040)
#define SPI_I2S_FLAG_BSY                ((u16)0x0080)
#define SPI_I2S_FLAG_TIFRFE             ((u16)0x0100)

#define CR1_CLEAR_MASK            ((u16)0x3040)
#define SPI_I2SCFGR_I2SMOD       ((u16)0x0800)  /*!<I2S mode selection */
#define SPI_Direction_2Lines_FullDuplex ((u16)0x0000)
#define SPI_Mode_Master                 ((u16)0x0104)
#define SPI_DataSize_8b                 ((u16)0x0000)
#define SPI_CPOL_Low                    ((u16)0x0000)
#define SPI_CPOL_High                   ((u16)0x0002)
#define SPI_CPHA_1Edge                  ((u16)0x0000)
#define SPI_CPHA_2Edge                  ((u16)0x0001)
#define SPI_NSS_Soft                    ((u16)0x0200)
#define SPI_NSS_Hard                    ((u16)0x0000)
#define SPI_FirstBit_MSB                ((u16)0x0000)
#define SPI_FirstBit_LSB                ((u16)0x0080)
#define SPI_BaudRatePrescaler_2         ((u16)0x0000)
#define SPI_BaudRatePrescaler_4         ((u16)0x0008)
#define SPI_BaudRatePrescaler_8         ((u16)0x0010)
#define SPI_BaudRatePrescaler_16        ((u16)0x0018)
#define SPI_BaudRatePrescaler_32        ((u16)0x0020)
#define SPI_BaudRatePrescaler_64        ((u16)0x0028)
#define SPI_BaudRatePrescaler_128       ((u16)0x0030)
#define SPI_BaudRatePrescaler_256       ((u16)0x0038)


/* SPI Clock Counter Register */
//#define SPI_CCR_COUNTER(x)	((x) << 0)
#define RCC_APB2Periph_SPI1              ((u32)0x00001000)

/*
 * SPI registers
 */
struct stm_spi {
  volatile u16 cr1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
  u16      reserved0;  /*!< reserved, 0x02                                                           */
  volatile u16 cr2;        /*!< SPI control register 2,                             Address offset: 0x04 */
  u16      reserved1;  /*!< reserved, 0x06                                                           */
  volatile u16 sr;         /*!< SPI status register,                                Address offset: 0x08 */
  u16      reserved2;  /*!< reserved, 0x0A                                                           */
  volatile u16 dr;         /*!< SPI data register,                                  Address offset: 0x0C */
  u16      reserved3;  /*!< reserved, 0x0E                                                           */
  volatile u16 crcpr;      /*!< SPI crC polynomial register (not used in I2S mode), Address offset: 0x10 */
  u16      reserved4;  /*!< reserved, 0x12                                                           */
  volatile u16 rxcrcr;     /*!< SPI RX crC register (not used in I2S mode),         Address offset: 0x14 */
  u16      reserved5;  /*!< reserved, 0x16                                                           */
  volatile u16 txcrcr;     /*!< SPI TX crC register (not used in I2S mode),         Address offset: 0x18 */
  u16      reserved6;  /*!< reserved, 0x1A                                                           */
  volatile u16 i2scfgr;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  u16      reserved7;  /*!< reserved, 0x1E                                                           */
  volatile u16 i2spr;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
  u16      reserved8;  /*!< reserved, 0x22 */
};

#define stm_SPI1_BASE 0x40013000
static volatile struct stm_spi *stm_spi = (struct stm_spi *)stm_SPI1_BASE;

/* SPI pins configuration */
static const struct stm32f2_gpio_dsc_ext stm32f4_spi1_gpio[] = {

	{{STM32F2_GPIO_PORT_A, STM32F2_GPIO_PIN_5}, STM32F2_GPIO_ROLE_SPI5  },	// SCK
	{{STM32F2_GPIO_PORT_A, STM32F2_GPIO_PIN_6}, STM32F2_GPIO_ROLE_SPI5  },	// MISO
	{{STM32F2_GPIO_PORT_A, STM32F2_GPIO_PIN_7}, STM32F2_GPIO_ROLE_SPI5  },	// MOSI
	{{STM32F2_GPIO_PORT_A, STM32F2_GPIO_PIN_4}, STM32F2_GPIO_ROLE_GPOUT },	// CS
	{{STM32F2_GPIO_PORT_C, STM32F2_GPIO_PIN_5}, STM32F2_GPIO_ROLE_GPOUT },	// CS  
};

/*
 * Initialization of the entire driver
 */
void spi_init()
{
  u16 tmpreg = 0;  
  int i, rv = 0;

	for (i = 0; i < ARRAY_SIZE(stm32f4_spi1_gpio); i++)
	{
		rv = stm32f2_gpio_config(&stm32f4_spi1_gpio[i].stm32f2_gpio, 
                                stm32f4_spi1_gpio[i].role);
		if (rv != 0)
			return;
	}
  stm32f2_gpout_set(&stm32f4_spi1_gpio[4].stm32f2_gpio, 0);
  
  // Enable SPI clock
  STM32_RCC->apb2enr |=  RCC_APB2Periph_SPI1;
  
  // Reset SPI peripheral
  STM32_RCC->apb2rstr |=  RCC_APB2Periph_SPI1;
  STM32_RCC->apb2rstr &= ~(RCC_APB2Periph_SPI1);
  
	// SPI Config
  tmpreg = stm_spi->cr1;
  tmpreg &= CR1_CLEAR_MASK;
  tmpreg |= (u16)((u32)SPI_Direction_2Lines_FullDuplex | SPI_Mode_Master |
                  SPI_DataSize_8b | SPI_CPOL_Low |  
                  SPI_CPHA_1Edge | SPI_NSS_Soft |  
                  SPI_BaudRatePrescaler_8 | SPI_FirstBit_MSB);
  stm_spi->cr1 = tmpreg;
  stm_spi->i2scfgr &= (u16)~((u16)SPI_I2SCFGR_I2SMOD);
  stm_spi->crcpr = 7;

	// SPI enable
	stm_spi->cr1 |= 0x0040;  

}

/*
 * Prepare to use an SPI slave
 * @param b		SPI controller
 * @param cs		slave Chip Select
 * @param hz		max freq this slave can run at
 * @param m		slave access mode
 * @returns		driver specific slave
 */
struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
				  unsigned int hz, unsigned int mode)
{
  struct spi_slave *slave = NULL;
#if 0
	struct stm_spi_slave *s;

	//unsigned int spccr;

	if (bus != 0 || cs != 0) {
		goto done;
	}
	//spccr = (clock_get(CLOCK_SPI) / hz) & 0xfe;
	//if (spccr < 8) {
	//	goto done;
	//}

	s = malloc(sizeof(struct stm_spi_slave));
	if (!s) {
		goto done;
	}

	s->hz = hz;
	s->mode = mode;

	slave = &s->slave;

	slave->bus = bus;
	slave->cs = cs;
#endif
 done:
	return slave;
}

/*
 * Handler to get access to the driver specific slave data structure
 * @param c		generic slave
 * @returns		driver specific slave
 */
static inline struct stm_spi_slave *to_stm_spi(struct spi_slave *slave)
{
	return container_of(slave, struct stm_spi_slave, slave);
}

/*
 * Done with an an SPI slave
 * @param slv		SPI slave
 */
void spi_free_slave(struct spi_slave *slv)
{
	//struct stm_spi_slave *s = to_stm_spi(slv);
	//free(s);
}

void spi_cs_activate(struct spi_slave *slave)
{
  stm32f2_gpout_set(&stm32f4_spi1_gpio[3].stm32f2_gpio, 0);
}

void spi_cs_deactivate(struct spi_slave *slave)
{
  stm32f2_gpout_set(&stm32f4_spi1_gpio[3].stm32f2_gpio, 0);
}


/*
 * Set up the SPI controller
 * @param slv		SPI slave
 * @returns		0->success; !0->failure
 */
int spi_claim_bus(struct spi_slave *slv)
{
  #if 0
	struct stm_spi_slave *s = to_stm_spi(slv);

	/* set speed */
	//stm_spi->ccr = s->spccr;
  	

	/* set mode */
	if (s->mode & SPI_CPHA) {
		//SPI_InitStructure._SPI_CPHA = SPI_CPHA_2Edge;
		//stm_spi->cr |= SPI_CR_CPHA;
	} else {
		//stm_spi->cr &= ~SPI_CR_CPHA;
		//SPI_InitStructure._SPI_CPHA = SPI_CPHA_1Edge;
	}
	if (s->mode & SPI_CPOL) {
		//stm_spi->cr |= SPI_CR_CPOL;
		//SPI_InitStructure._SPI_CPOL = SPI_CPOL_High;
	} else {
		//stm_spi->cr &= ~SPI_CR_CPOL;
		//SPI_InitStructure._SPI_CPOL = SPI_CPOL_Low;
	}
#endif

	return 0;
}

/*
 * Shut down the SPI controller
 * @param slv		SPI slave
 */
void spi_release_bus(struct spi_slave *slv)
{

}

/*
 * Perform an SPI transfer
 * @param slv		SPI slave
 * @param bl		transfer length (in bits)
 * @param dout		data out
 * @param din		data in
 * @param fl		transfer flags
 * @returns		0->success; !0->failure
 */
int spi_xfer(struct spi_slave *slv, unsigned int bl,
	     const void *dout, void *din, unsigned long fl)
{
	u8 dummy = 0xff;
	int i;
	//u32 sr;
	int ret = 0;
	const u8	*_dout = dout;
	u8		*_din = din;
	int len = bl >> 3;

	if (fl & SPI_XFER_BEGIN) {
		/* Enable chip select */
		//stm_gpio_clear(stm_cs_gpio);
    stm32f2_gpout_set(&stm32f4_spi1_gpio[3].stm32f2_gpio, 0);
	}

	for (i = 0; i < len; i++) {
 		while((stm_spi->sr & SPI_I2S_FLAG_TXE)==0);

		if (dout == NULL) {
			stm_spi->dr = dummy;
		} else {
			stm_spi->dr = _dout[i];
		}

//		do {
//			sr = stm_spi->sr;
//		}
//		while ((sr & SPI_SR_SPIF) == 0);
 		while((stm_spi->sr & SPI_I2S_FLAG_RXNE)==0);

		//sr = stm_spi->sr;
		if (din == NULL) {
			dummy = stm_spi->dr;
		} else {
			_din[i] = stm_spi->dr;
		}
		//sr = stm_spi->tsr;
	}

	if (fl & SPI_XFER_END) {
		/* Disable chip select */
		//stm_gpio_set(stm_cs_gpio);
    stm32f2_gpout_set(&stm32f4_spi1_gpio[3].stm32f2_gpio, 1);
	}

	return ret;
}
