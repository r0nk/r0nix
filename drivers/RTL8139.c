#include <drivers/RTL8139.h>
#include <drivers/pci.h>
#include <pic.h>
#include <kprint.h>
#include <stdint.h>
#include <panic.h>
#include <io.h>

#include "../net/mac.h"

/* much of this comes from wiki.osdev.org/RTL8139 */
/* TODO: lots and lots of magic numbers that should be replaced here.*/

uint32_t rtl_base_address;

int read_ptr;

#define CAPR 0x38
#define RX_READ_PONTER_MASK (~3)
#define ROK     (1<<0)
#define RER	(1<<1)
#define TOK     (1<<2)
#define TER	(1<<3)
#define TX_TOK  (1<<15)

/* transmission requires us to use each descriptor in round robin,
 * transmit_desc is the current descriptor for us to use 
 */
char transmit_desc;

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
	outw(rtl_base_address+0x3C,0xFFFF);
}

inline void configure_rcr()
{
	uint32_t a = 0;
	a = 0xf|(1<<7);
	a = a^(1<<5);
	outl(rtl_base_address + 0x44,a);
}

inline void enable_rx_tx()
{
	outb(rtl_base_address + 0x37,0xC);
}

inline void rtl_enable_config_write()
{
	int a = inb(rtl_base_address + 0x50);
	outb(rtl_base_address + 0x50,(a|0xC0));
}

inline void enable_bus_mastering(int devnum)
{
	uint32_t a =(uint32_t) pci_config_read_word(0,devnum,0,0x4);
	rtl_enable_config_write();
	pci_config_write_dword(0,devnum,0,0x4,(a|0x4));
}

inline void enable_crc()
{
	uint32_t a = inl(rtl_base_address+0x40);
	a|=(1<<16);
	outl(rtl_base_address+0x40,a);
}

inline void enable_loopback()
{
	uint32_t a = inl(rtl_base_address+0x40);
	a|=(1<<17);
	a|=(1<<18);
	outl(rtl_base_address+0x40,a);
}

inline void configure_mac_addr()
{
	our_mac.o[0]=inb(rtl_base_address+0x0);
	our_mac.o[1]=inb(rtl_base_address+0x1);
	our_mac.o[2]=inb(rtl_base_address+0x2);
	our_mac.o[3]=inb(rtl_base_address+0x3);
	our_mac.o[4]=inb(rtl_base_address+0x4);
	our_mac.o[5]=inb(rtl_base_address+0x5);
	kprintf("[0]:%x\n",our_mac.o[0]);
	kprintf("[1]:%x\n",our_mac.o[1]);
	kprintf("[2]:%x\n",our_mac.o[2]);
	kprintf("[3]:%x\n",our_mac.o[3]);
	kprintf("[4]:%x\n",our_mac.o[4]);
	kprintf("[5]:%x\n",our_mac.o[5]);
}

void rtl_receive_packet()
{
	uint16_t pkt_length=*(uint16_t*) (rx_buffer + read_ptr + 2);

	/*TODO add something to handle the packet here*/

	/*update read pointer*/
	read_ptr = (read_ptr + pkt_length + 7) & RX_READ_PONTER_MASK;

	/*(its a circular buffer)*/
	if(read_ptr > RX_BUF_SIZE)
		read_ptr-=RX_BUF_SIZE;

	outw(rtl_base_address+CAPR, read_ptr-0x10);
}

void rtl_handle_interrupt()
{
	int offset=(transmit_desc-1)*4;
	uint16_t status;
	uint32_t tx_status;

	status = inw(rtl_base_address+0x3E);

	kprintf("interrupt rtl status: %x\n",status);

	if(status&TER){
		panic("RTL TER set");
	}
	if (status&RER){
		panic("RTL RER set");
	}

	if(status&TOK){
		tx_status = inl(rtl_base_address+0x10+offset);
		if(tx_status&TX_TOK)
			outl(rtl_base_address+0x10+offset,0);
	}
	if(status&ROK){
		rtl_receive_packet();
	}

	/*reset the status register*/
	outw(rtl_base_address+0x3E,status);
}

inline void inc_transmit_desc()
{
	transmit_desc++;
	if(transmit_desc>3)
		transmit_desc=0;
}

void rtl_transmit(char * data,int size)
{
	int offset=transmit_desc*4;

	if(size > (size&0x9ff)){
		kprintf("RTL8139 TX ERR: packet size too big \n");
		return;
	}
	char threshold = 0xff;
	uint32_t status = (size&0x9ff) | (threshold<<16);
	/* fill in the start address */
	outl(rtl_base_address+0x20+offset,(uint32_t)data);
	/* fill in transmit status; this causes rtl to transmit the packet */
	outl(rtl_base_address+0x10+offset,status);

	inc_transmit_desc();
}

void init_RTL8139(int devnum)
{
	rtl_base_address=pci_config_read_word(0,devnum,0,0x10)-1;
	unsigned char irqline = (unsigned char) 
		pci_config_read_word(0,devnum,0,0x3c);
	transmit_desc=0;
	read_ptr=0;

	enable_bus_mastering(devnum);
	power_on_rtl();
	software_reset();
	init_receive_buffer(rx_buffer);
	set_imr_isr();
	configure_rcr();
	configure_mac_addr();
	enable_rx_tx();
//	enable_loopback();
//	enable_crc();
	clear_mask(irqline);
}
