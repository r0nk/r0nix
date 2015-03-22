#include <net/init.h>
#include <drivers/pci.h>
#include <kprint.h>

void init_net()
{
	int i;
	for(i=0;i<20;i++)
		if(pci_device[i]==0x8139)
			kprintf("found a RTL!!!\n");
}
