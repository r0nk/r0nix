#include <drivers/pci.h>
#include <stdint.h>
#include <kprint.h>
#include <io.h>

uint16_t pci_config_read_word(uint8_t bus,uint8_t slot,
		uint8_t func, uint8_t offset)/*(offset is basically register)*/
{
	uint32_t address;
	uint32_t lbus  = (uint32_t)bus;
	uint32_t lslot = (uint32_t)slot;
	uint32_t lfunc = (uint32_t)func;

	/* create configuration address */
	address = (uint32_t)((lbus << 16) | (lslot << 11) | 
		   (lfunc << 8) | (offset & 0xfc) | ((uint32_t)0x80000000));

	/* write out the address */
	outl(CONFIG_ADDRESS,address);
	/* read in the data */
	return (uint16_t)((inl(CONFIG_DATA) >> ((offset&2)*8))&0xffff);
}

void pci_config_write_dword(uint8_t bus,uint8_t slot,
		uint8_t func, uint8_t offset,uint32_t dword)
{
	uint32_t address;
	uint32_t lbus  = (uint32_t)bus;
	uint32_t lslot = (uint32_t)slot;
	uint32_t lfunc = (uint32_t)func;

	/* create configuration address */
	address = (uint32_t)((lbus << 16) | (lslot << 11) | 
		   (lfunc << 8) | (offset & 0xfc) | ((uint32_t)0x80000000));

	/* write out the address */
	outl(CONFIG_ADDRESS,address);
	/* write out the data */
	outl(CONFIG_DATA,dword);
}

void check_device(uint8_t bus, uint8_t device)
{
	int vendorID = pci_config_read_word(bus,device,0,0);
	int deviceID = pci_config_read_word(bus,device,0,2);
	if(vendorID == 0xFFFF) 
		return;
	pci_device[device]=deviceID;
}

void scan_for_devices()
{
	int bus,device;

	for(bus=0;bus<256;bus++)
		for(device=0;device<32;device++)
			check_device(bus,device);
}

void init_pci()
{
	scan_for_devices();
}
