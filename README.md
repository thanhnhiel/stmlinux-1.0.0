# stmlinux-1.0.0

### How to build
#### Create workspace
```bash
mkdir qtdemo
cd qtdemo
```
#### Download compiler <br>
```bash
wget http://www.codesourcery.com/sgpp/lite/arm/portal/package6503/public/arm-uclinuxeabi/arm-2010q1-189-arm-uclinuxeabi-i686-pc-linux-gnu.tar.bz2
```
#### Extract compiler to workspace<br>
```bash
tar xvf arm-2010q1-189-arm-uclinuxeabi-i686-pc-linux-gnu.tar.bz2
```
#### Download source code<br>
```bash
git clone https://github.com/thanhnhiel/stmlinux-1.0.0.git
```
#### Setting environment<br>
```bash
# Path to cross-tools
export ROOT=`pwd`
export INSTALL_ROOT=$ROOT/stmlinux-1.0.0
export PATH=$INSTALL_ROOT/tools/bin:$ROOT/arm-2010q1/bin:$PATH
export CROSS_COMPILE=arm-uclinuxeabi-
export CROSS_COMPILE_APPS=arm-uclinuxeabi-
# Define the MCU architecture
export MCU=STM32F4X9
```
#### Build u-boot
cd stmlinux-1.0.0
cd u-boot
rm -rf obj
make diskclean
make stm32f429-discovery O=obj

#### Config kernel & busybox<br>
```bash
cd stmlinux-1.0.0/projects/qtdemo2
make kmenuconfig
make bmenuconfig
```
#### build kernel<br>
```bash
make
```

#### Programing by st-link tools on the window.
Output files:<br>

<table>
<tr>
<th>File name</th><th>Offset</th><th>Path</th>
</tr>
<tr>
<td>u-boot.bin</td><td>0x08000000</td><td>stmlinux-1.0.0/u-boot/obj</td>
</tr>
<tr>
<td>qtdemo2.uImage.bin</td><td>0x08020000</td><td>stmlinux-1.0.0/projects/qtdemo2</td>
</tr>
</table>


#### Output Log
```bash
U-Boot 2010.03 (Dec 17 2015 - 19:59:08)

CPU  : STM32F4 (Cortex-M4)
Freqs: SYSCLK=180MHz,HCLK=180MHz,PCLK1=45MHz,PCLK2=90MHz
Board: STM32F429-DISCOVERY Rev 1.A
DRAM:  32 MB
*** Warning - bad CRC, using default environment

In:    serial
Out:   serial
Err:   serial
Net:   eth_register
ENC28J60_ETH
Hit any key to stop autoboot:  0
enc28j60_eth_init
Wait for CLKRDY ...
enc28j60_eth_init...ok
Using ENC28J60_ETH device
TFTP from server 192.168.1.10; our IP address is 192.168.1.15
Filename 'qtdemo2.uImage.bin'.
Load address: 0xc0007fc0
Loading: T #################################################################
         #################################################################
         #################################################################
         #################################################################
         #################################################################
         #################################################################
         #################################################################
         #################################################################
         ########################
done
Bytes transferred = 7983296 (79d0c0 hex)
## Booting kernel from Legacy Image at c0007fc0 ...
   Image Name:   Linux-2.6.33-arm1
   Image Type:   ARM Linux Kernel Image (uncompressed)
   Data Size:    7983232 Bytes =  7.6 MB
   Load Address: c0008000
   Entry Point:  c0008001
   Verifying Checksum ... OK
   Loading Kernel Image ... OK
OK

Starting kernel ...

Linux version 2.6.33-arm1 (root@linux) (gcc version 4.4.1 (Sourcery G++ Lite 2010q1-189) ) #7 Fri Dec 18 01:27:11 ICT 2015
CPU: ARMv7-M Processor [410fc241] revision 1 (ARMv7M)
CPU: NO data cache, NO instruction cache
Machine: STMicro STM32
Built 1 zonelists in Zone order, mobility grouping off.  Total pages: 7620
Kernel command line: stm32_platform=stm-disco mem=30M console=tty0,115200 console=ttyS0,115200 panic=10 video=vfb:enable,fbmem:0xC1E00000,fbsize:0x100000 ip=192.168.1.15:192.168.1.10:::stm-disco:eth0:off ethaddr=C0:B1:3C:88:88:85
PID hash table entries: 128 (order: -3, 512 bytes)
Dentry cache hash table entries: 4096 (order: 2, 16384 bytes)
Inode-cache hash table entries: 2048 (order: 1, 8192 bytes)
Memory: 30MB = 30MB total
Memory: 22592k/22592k available, 8128k reserved, 0K highmem
Virtual kernel memory layout:
    vector  : 0x00000000 - 0x00001000   (   4 kB)
    fixmap  : 0xfff00000 - 0xfffe0000   ( 896 kB)
    vmalloc : 0x00000000 - 0xffffffff   (4095 MB)
    lowmem  : 0xc0000000 - 0xc1e00000   (  30 MB)
    modules : 0xc0000000 - 0xc2000000   (  32 MB)
      .init : 0xc0008000 - 0xc06ba000   (6856 kB)
      .text : 0xc06ba000 - 0xc0791000   ( 860 kB)
      .data : 0xc0792000 - 0xc07a5080   (  77 kB)
Hierarchical RCU implementation.
NR_IRQS:259
Console: colour dummy device 80x30
console [tty0] enabled
Calibrating delay loop... 34.20 BogoMIPS (lpj=171008)
Mount-cache hash table entries: 512
NET: Registered protocol family 16
stm32_gpio_direction_output:131[8,3]=1
stm32_gpio_direction_output:117[7,5]=1
stm32_gpio_direction_output:86[5,6]=1
spi_info 0 irq=116
stm32_gpio_to_irq:116=207
Switching to clocksource cm3-systick
NET: Registered protocol family 2
IP route cache hash table entries: 1024 (order: 0, 4096 bytes)
TCP established hash table entries: 1024 (order: 1, 8192 bytes)
TCP bind hash table entries: 1024 (order: 0, 4096 bytes)
TCP: Hash tables configured (established 1024 bind 1024)
TCP reno registered
fb0: Virtual frame buffer device, using 1024K of video memory
Serial: STM32 USART driver
stm32serial.0: ttyS0 at MMIO 0x40011000 (irq = 37) is a STM32 USART Port
console [ttyS0] enabled
spi_stm32 spi_stm32.4: SPI Controller 4 at 40015000,hz=90000000
ads7846: ads7846_probe start
ads7846: IRQ = 207
stm32_gpio_irq_set_type:116[4,7]=20
stm32_gpio_irq_enable:116[4,7]=207
ads7846 spi4.0: touchscreen, irq 207
input: ADS7846 Touchscreen as /devices/platform/spi_stm32.4/spi4.0/input/input0
TCP cubic registered
NET: Registered protocol family 17
ARMv7-M VFP Extension supported
IP-Config: Device `eth0' not found.
Freeing init memory: 6856K
init started: BusyBox v1.17.0 (2015-12-16 00:09:15 ICT)
route: SIOCADDRT: Network is unreachable
~ # ./start_qt
Could not read calibration: "/etc/pointercal"
>
```
