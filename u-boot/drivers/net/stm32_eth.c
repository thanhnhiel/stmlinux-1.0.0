/*
 * (C) Copyright 2011
 *
 * Yuri Tikhonov, Emcraft Systems, yur@emcraft.com
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
 * STM32 F2 Ethernet driver
 */

#include <config.h>

/*
 * Define DEBUG to enable debug() messages in this module
 */
#undef DEBUG

#include <common.h>
#include <malloc.h>
#include <net.h>
//#include <miiphy.h>
#include <asm/errno.h>

#include <spi.h>

/*
 * Device name
 */
#define STM32_MAC_NAME			"ENC28J60_ETH"


/* maximum frame length */
#define ENC_MAX_FRM_LEN 1518


//static unsigned char buffer[ENC_MAX_FRM_LEN];
unsigned char *enc_buffer;
static int rxResetCounter = 0;

#define RX_RESET_COUNTER 1000;

/*
 * STM32 ETH device
 */
struct stm_eth_dev {
	/*
	 * Standard ethernet device
	 */
	struct eth_device		netdev;

	/*
	 * ETH DMAed buffers:
	 * - send requested buffers directly, i.e. have no local storage;
	 * - receive buffers have length of 1536B (> max eth frm len)
	 */
//	volatile u8			rx_buf[PKTBUFSRX][PKTSIZE_ALIGN];
	unsigned char buffer[ENC_MAX_FRM_LEN];
};

#define to_stm_eth(_nd)	container_of(_nd, struct stm_eth_dev, netdev)

/*
 * Prototypes
 */
//static  s32 stm_eth_init_(struct eth_device *dev, bd_t *bd) {};
static  s32 stm_eth_send_(struct eth_device *dev, volatile void *pkt, s32 len){};
static  s32 stm_eth_recv_(struct eth_device *dev){};
static void stm_eth_halt_(struct eth_device *dev){};

int eth_init_ (bd_t * bis);
int eth_send_ (volatile void *packet, int length);
int eth_rx_ (void);
void eth_halt_ (void);

//==============================================================
static struct spi_slave *spi1;

/*
 * Init STM32 MAC and DMA
 */
static s32 stm_eth_init(struct eth_device *dev, bd_t *bd)
{
	unsigned char estatVal;
	uchar enetaddr[6];

	//struct stm_eth_dev	*mac = to_stm_eth(dev);
	s32			rv;

	//printf("stm_eth_init\n");
	printf ("enc28j60_eth_init\n");
	//spi1 = spi_setup_slave(1, 0, 2000000, SPI_CPHA | SPI_CPOL);
	//spi_claim_bus(spi1);
	printf ("Wait for CLKRDY ...\n");
  rv = eth_init_(bd);
	printf ("enc28j60_eth_init...ok\n");

out:
	if (rv != 0)
		printf("%s: failed (%d).\n", __func__, rv);
	return rv;

}

/*
 * Send frame
 */
static s32 stm_eth_send(struct eth_device *dev, volatile void *pkt, s32 len)
{
	//struct stm_eth_dev	*mac = to_stm_eth(dev);
	s32			rv, tout;

	if (len > PKTSIZE_ALIGN) {
		printf("%s: frame too long (%d).\n", __func__, len);
		rv = -EINVAL;
		goto out;
	}
  
	rv = eth_send_(pkt, len);
out:
	return rv;
}

/*
 * Process received frames (if any)
 */
static s32 stm_eth_recv(struct eth_device *dev)
{
	//struct stm_eth_dev		*mac = to_stm_eth(dev);
  return eth_rx_();
}

/*
 * Halt MAC
 */
static void stm_eth_halt(struct eth_device *dev)
{
  //eth_halt_();
}

/*
 * Initialize driver
 */
s32 stm32_eth_init(bd_t *bd)
{
	struct stm_eth_dev	*mac;
	struct eth_device	*netdev;
	s32			rv;
	u32			val;

	mac = malloc(sizeof(struct stm_eth_dev));
	if (!mac) {
		printf("Error: failed to allocate %dB of memory for %s\n",
			sizeof(struct stm_eth_dev), STM32_MAC_NAME);
		rv = -ENOMEM;
		goto out;
	}
	memset(mac, 0, sizeof(struct stm_eth_dev));

	enc_buffer = &mac->buffer[0];
	netdev = &mac->netdev;

	sprintf(netdev->name, STM32_MAC_NAME);

	netdev->init = stm_eth_init;
	netdev->halt = stm_eth_halt;
	netdev->send = stm_eth_send;
	netdev->recv = stm_eth_recv;
  printf("eth_register\n");
	rv = eth_register(netdev);
out:
	if (rv != 0 && mac)
		free(mac);

	return rv;
}
