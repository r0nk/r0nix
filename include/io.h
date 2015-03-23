#ifndef IO
#define IO 1

#include <stdint.h>

void outb(uint16_t port,uint8_t value);
void outw(uint16_t port,uint16_t value);
void outl(uint16_t port,uint32_t value);
uint8_t inb(uint16_t port);
uint32_t inl(uint16_t port);

#endif
