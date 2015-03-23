#include <drivers/RTL8139.h>
#include <drivers/pci.h>
#include <pic.h>
#include <kprint.h>
#include <stdint.h>
#include <io.h>

/* much of this comes from wiki.osdev.org/RTL8139 */
/* TODO: lots and lots of magic numbers that should be replaced here.*/

char rx_buffer[8192+16];
uint32_t rtl_base_address;

inline void power_on_rtl()
{
	outb(rtl_base_address+0x52,0x0);
}

inline void software_reset()
{
	outb(rtl_base_address+0x37,0x10);
	while( (inb(rtl_base_address + 0x37) & 0x10) != 0);
}

inline void init_receive_buffer(char * rx_buf)
{
	outl(rtl_base_address+0x30,(uint32_t)rx_buf);
}

inline void set_imr_isr()
{
	outw(rtl_base_address+0x3C,0xE07F);
}

inline void configure_rcr()
{
	outl(rtl_base_address + 0x44,0xf | (1<<7));
}

inline void enable_rx_tx()
{
	outb(rtl_base_address + 0x37,0xC);
}

inline void enable_bus_mastering(int devnum)
{
	uint32_t a =(uint32_t) pci_config_read_word(0,devnum,0,0x4);
	kprintf("rtl a:%x\n",a);
	a|=0x4;
	pci_config_write_word(0,devnum,11,0x4,a);
	kprintf("rtl a:%x\n",a);
}

void rtl_acknowledge_interrupt()
{
	outl(rtl_base_address+0x3E,0x1);
}

void init_RTL8139(int devnum)
{
	rtl_base_address=pci_config_read_word(0,devnum,0,0x10)-1;
	unsigned char irqline = (unsigned char) 
		pci_config_read_word(0,devnum,0,0x3c);
//	enable_bus_mastering(devnum);//bios already does this

	power_on_rtl();
	software_reset();
	init_receive_buffer(rx_buffer);
	set_imr_isr();
	configure_rcr();
	enable_rx_tx();
	clear_mask(irqline);
}