SECTIONS
{
    kernel_load_address = ((0x100000) + 0xFFFFFFFFC0000000);
    .unmapped (0x100000 + SIZEOF_HEADERS) : AT(0x100000 + SIZEOF_HEADERS)
    {
        unmapped_start = .;
        *(MULTIBOOT_HEADER);
        *(KTEXT32);
        *(KDATA32);
        *(KBSS32);
        unmapped_end = .;
    }
    .mapped (((0x100000) + 0xFFFFFFFFC0000000) + SIZEOF_HEADERS + SIZEOF(.unmapped)) : AT(0x100000 + SIZEOF_HEADERS + SIZEOF(.unmapped))
    {
        . = ALIGN(4K);
        mapped_ro_lo = .;
        *(.text .text.*);
        *(.rodata .rodata.*);
        mapped_ro_hi = .;
        . = ALIGN(4K);
        mapped_rw_lo = .;
        *(.data .data.*);
        *(COMMON);
        *(.bss .bss.*);
        *(.heap);
        mapped_rw_hi = .;
        . = ALIGN(8);
  symbol_table = .;
  *(symtab.*);
    }
    kernel_end_address = .;
    /DISCARD/ : {
  *(*);
 }
}
