#include "io.h"

// Read a byte from the specified port
unsigned char port_byte_in(unsigned short port)
{
    unsigned char result;
    /* Inline assembler syntax
     * The source and destination registers are switched from NASM
     * '"=a" (result)'; set '=' the C variable '(result)' to the value of register e'a'x
     * '"d" (port)': map the C variable '(port)' into e'd'x register
     * Inputs and outputs are separated by colons
     */
    __asm__("in %%dx, %%al" : "=a"(result) : "d"(port));
    return result;
}

// Set a byte on the specified port
void port_byte_out(unsigned short port, unsigned char data)
{
    __asm__("out %%al, %%dx" : : "a"(data), "d"(port));
}

unsigned short port_word_in(unsigned short port)
{
    unsigned short result;
    __asm__("in %%dx, %%ax" : "=a"(result) : "d"(port));
    return result;
}

void port_word_out(unsigned short port, unsigned short data)
{
    __asm__("out %%ax, %%dx" : : "a"(data), "d"(port));
}

// Waits a very small amount of time by doing an IO operation on unused port
void io_wait(void)
{
    port_byte_out(0x80, 0);
}
