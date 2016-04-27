.code16
.text
	.globl _start;
_start:
	. = _start + 510
	.short 0xaa55
