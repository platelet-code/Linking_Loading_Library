ENTRY(nomain)

SECTIONS
{
    . = 0x08048000 + SIZEOF_HEADERS;

    tiny_text : { *(.text) *(.data) *(.rodata) }

    /DISCARD/ : { *(.comment) }
}

// gcc -c -m32 -fno-builtin TinyHelloWorld.c
// ld -m elf_i386 -static -T TinyHelloWorld.lds -o TinyHelloWorld TinyHelloWorld.o
