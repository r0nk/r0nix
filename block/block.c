#include <block.h>
#include <stdio.h>

void write_to_block_device(int which, unsigned long location, uint8_t value){
	if(location > gbda[which].size){
		kprint_string("block device write overflow!\n");
		return;
	}
	gbda[which]._write(location,value);
}

uint8_t read_from_block_device(int which, unsigned long location){
	if(location > gbda[which].size){
		kprint_string("block device read overflow!\n");
		return 0;
	}
	return gbda[which]._read(location);
}
