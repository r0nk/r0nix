#ifndef BLOCK
#define BLOCK 1
#include <stdint.h>
/* This is for those good ol' unix block devices */

struct Block_Device{
	unsigned long size;
	uint8_t (*_read)(unsigned long location);
	void (*_write)(unsigned long location,uint8_t value);
};

struct Block_Device root_block;

void write_to_block_device( unsigned long location, uint8_t value);
uint8_t read_from_block_device( unsigned long location);

#endif
