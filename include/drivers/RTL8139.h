#ifndef RTL8139
#define RTL8139
#include <stdint.h>

char rx_buffer[8192+16];
void init_RTL8139(int devnum);
void rtl_acknowledge_interrupt();
void rtl_transmit(char * data,int size);

#endif
