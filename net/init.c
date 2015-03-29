#include <net/init.h>
#include <drivers/pci.h>
#include <drivers/RTL8139.h>
#include <kprint.h>
#include "arp.h"
#include "mac.h"

void init_net()
{
	int i;
	for(i=0;i<20;i++){
		if(pci_device[i]==0x8139){
			init_RTL8139(i);
			break;
		}
	}
	if(i==20){
		kprintf("net: No devices found.\n");
		return;
	}
	send_arp_request();
	char * hello = "hello world!";
	struct mac_packet mpkt=mac_create_pkt((void*)&hello, 12, 0x800);
	rtl_transmit((void*)&mpkt,12 + (sizeof(mpkt)-MAX_MAC_LENGTH));
}
