TOOLCHAIN=arm-2010q1
export INSTALL_ROOT=`pwd`
TOOLS_PATH=$INSTALL_ROOT/tools
CROSS_PATH=/mnt/data1/workspace/compiler/arm-2010q1/bin
export PATH=$TOOLS_PATH/bin:$CROSS_PATH:$PATH

# Path to cross-tools
export CROSS_COMPILE=arm-uclinuxeabi-
export CROSS_COMPILE_APPS=arm-uclinuxeabi-

# Define the MCU architecture
export MCU=STM32F4X9

