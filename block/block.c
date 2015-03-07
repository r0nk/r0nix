#include <block.h>
#include <kprint.h>

void write_to_block_device(unsigned long location, uint8_t value){
	if(location > gbda[0].size){
		kprintf("block device write overflow!\n");
		return;
	}
	gbda[0]._write(location,value);/* TODO shouldn't always be zero */
}

uint8_t read_from_block_device(unsigned long location){
	if(location > gbda[0].size){
		kprintf("block device read overflow!\n");
		return 0;
	}
	return gbda[0]._read(location);/* TODO shouldn't always be zero */
}
