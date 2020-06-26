OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS {
	. = 0x02021400;
    . = ALIGN(4);
	.text : {
        ailed.o (.text)
		*(.text)
	}

	.rodata ALIGN(4) : {
		*(.rodata*)
	}

	.data ALIGN(4) : {
		*(.data*)
	}

	.bss ALIGN(4) : {
		*(.bss)
		*(COMMON)
	}
}
