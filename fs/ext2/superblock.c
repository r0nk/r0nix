#include <block.h>
#include "ext2.h"

struct ext2_super_block ext2_get_super_block(int disk_num){
	struct ext2_super_block sb;
	void * p = &sb;
	int i;
	for(i=0;i<1024;i++)
		(*p+i)=read_from_block_device(disk_num,i+1024);
	return sb;
}
