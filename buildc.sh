#!/bin/bash
rm test.o test.elf test.bin floppy.img 2> /dev/null

gcc-4.4 -c -g -Os -m32 -ffreestanding -Wall -Werror $1 -o test.o &&
ld -static -melf_i386 -Ttest.ld -nostdlib --nmagic -o test.elf test.o &&
objcopy -O binary test.elf test.bin &&

dd if=/dev/zero of=floppy.img bs=512 count=2880 &&
dd if=test.bin of=floppy.img
