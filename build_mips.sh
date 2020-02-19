#!/bin/bash
#
# Compiles a hello world bios for MIPS
#
export ARCH=mips
export CROSS_COMPILE=mips-mti-linux-gnu-
make mrproper
make qemu-malta-chad_defconfig
make
