#!/bin/bash
FSL_TOOLCHAIN_DIR=~/Yocto/L3/fsl-linaro-toolchain/bin/
export ARCH=arm
export CROSS_COMPILE=$FSL_TOOLCHAIN_DIR/arm-none-linux-gnueabi-
export PATH="$PATH:$FSL_TOOLCHAIN_DIR"
export CC="$FSL_TOOLCHAIN_DIR/arm-none-linux-gnueabi-gcc"
export STRIP="$FSL_TOOLCHAIN_DIR/arm-none-linux-gnueabi-strip"
export __ARM_PCS_VFP=1

make distclean;
make mx6q_sabresd_config
make HOSTCC="$CC" HOSTSTRIP="$STRIP" CROSS_COMPILE="$CROSS_COMPILE" -j8

./mkimage_imx/mkimage -n ./mkimage_imx/mx6q_4x_mt41j128.cfg.cfgtmp \
	-T imximage -e 0x17800000 -d u-boot.bin u-boot.imx

#make "HOSTCC=ccache /usr/bin/gcc -B/usr/bin/ HOSTSTRIP=/usr/bin/strip CROSS_COMPILE=arm-none-linux-gnueabi- OPTFLAGS=-Os" all -j8
