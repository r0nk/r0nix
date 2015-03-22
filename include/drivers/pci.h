#ifndef PCI
#define PCI
#include <stdint.h>

#define CONFIG_ADDRESS 0xCF8
#define CONFIG_DATA    0xCFC

int pci_device[20];/* contents are device ids */

uint16_t pci_config_read_word(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset);
void pci_config_write_dword(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset,uint32_t dword);

void init_pci();

#endif
