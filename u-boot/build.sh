#!/bin/bash
rm -rf obj
make diskclean
make stm32f429-discovery O=obj 
#> log.txt 2>&1
#cp obj/u-boot.bin /media/sf_uCLinux/workspace/