#ifndef PCI
#define PCI
#include <stdint.h>

#define CONFIG_ADDRESS 0xCF8
#define CONFIG_DATA    0xCFC

uint16_t pci_config_read_word(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset);
void pci_config_write_word(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset,uint16_t word);

#endif