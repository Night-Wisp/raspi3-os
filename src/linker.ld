SECTIONS
{
	. = 0x80000
	.text.boot : { *(.text.boot) }
	.text : { *(.text .text.* .gnu.linkonce.t*) }
	.rodata : { *(.rodata .rodata.* .gnu.linkonce.r*) }
	.data : { *(.data .data.* .gnu.linkonce.d*) }
	. = ALIGN(0x8);
	bss_begin = .;
	.bss : { *(.bss*) *(COMMON) }
	bss_end = .;
	
	/DISCARD/ : { *(.comment) *(.gnu*) *(.note*) *(.eh_frame*) }
}
