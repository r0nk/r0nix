#include <net/init.h>
#include <drivers/pci.h>
#include <drivers/RTL8139.h>
#include <kprint.h>

void init_net()
{
	int i;
	for(i=0;i<20;i++){
		if(pci_device[i]==0x8139){
			init_RTL8139(i);
		}
	}
	if(i==19){
		kprintf("net: No devices found.\n");
		return;
	}

	char * hello="ABCDEFGHIJKLMNOPQRSTUVWXYZ nananananaslkdfjasldfjasldkfjasldkfjasdklf batman sldfja;lsdkjfalsdkjfal;skdjf;lakjsd;flkajsdf;laksdjfalsdkjfa;sldkfjasdlkfjasl;dfkjasdkflajsdfkajsdflkasdjfasldkfjasdlkfjasdlfkjasdlkfjasdlkfjasdlkfjasdlkfjasdlkfjasdlfkjasdflkjasdlfkjasdlfkjasdflkajsdflkjsadlfkjasdlkfj";
	rtl_transmit(hello,200);
}
