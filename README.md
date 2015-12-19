# stmlinux-1.0.0

How to build
1. Create workspace
mkdir qtdemo
cd qtdemo

2. Download compiler 
wget http://www.codesourcery.com/sgpp/lite/arm/portal/package6503/public/arm-uclinuxeabi/arm-2010q1-189-arm-uclinuxeabi-i686-pc-linux-gnu.tar.bz2

3. Extract compiler to workspace
tar xvf arm-2010q1-189-arm-uclinuxeabi-i686-pc-linux-gnu.tar.bz2

4. Download source code
git clone https://github.com/thanhnhiel/stmlinux-1.0.0.git

5. Setting environment
# Path to cross-tools
export ROOT=`pwd`
export INSTALL_ROOT=$ROOT/stmlinux-1.0.0
export PATH=$INSTALL_ROOT/tools/bin:$ROOT/arm-2010q1/bin:$PATH
export CROSS_COMPILE=arm-uclinuxeabi-
export CROSS_COMPILE_APPS=arm-uclinuxeabi-
# Define the MCU architecture
export MCU=STM32F4X9

6. Config kernel & busybox
cd stmlinux-1.0.0/projects/qtdemo2
make kmenuconfig
make bmenuconfig

7. build kernel
make

Output files:
File name	          Offset
u-boot.bin	        0x08000000
qtdemo2.uImage.bin	0x08020000

Program to kit by st-link tools on the window.
