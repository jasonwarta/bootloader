#!/bin/bash

as $1 -o temp.o
ld -Ttext 0x7c00 --oformat=binary temp.o -o temp.bin
dd if=/dev/zero of=floppy.img bs=512 count=2880
dd if=temp.bin of=floppy.img
