#include <block.h>
#include <kprint.h>

void write_to_block_device(unsigned long location, uint8_t value)
{
	if(location > root_block.size){
		kprintf("block device write overflow!\n");
		return;
	}
	root_block._write(location,value);
}

uint8_t read_from_block_device(unsigned long location)
{
	if(location > root_block.size){
		kprintf("block device read overflow!\n");
		return 0;
	}
	return root_block._read(location);
}
