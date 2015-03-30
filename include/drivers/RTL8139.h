#ifndef RTL8139
#define RTL8139
#include <stdint.h>

#define RX_BUF_SIZE 8192

char rx_buffer[RX_BUF_SIZE+16];
void init_RTL8139(int devnum);
void rtl_handle_interrupt();
void rtl_transmit(char * data,int size);

#endif
