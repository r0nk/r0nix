#ifndef RTL8139
#define RTL8139
#include <stdint.h>

void init_RTL8139(int devnum);
void rtl_acknowledge_interrupt();

#endif
