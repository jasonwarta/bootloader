.code16
.text
	.globl _start;

_start:
	movb $'H' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'e' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'l' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'l' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'o' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $',' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $' ' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'w' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'o' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'r' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'l' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'d' , %al
	movb $0x0e, %ah
	int  $0x10
	movb $'!' , %al
	movb $0x0e, %ah
	int  $0x10

	. = _start + 510
	.byte 0x55
	.byte 0xaa
