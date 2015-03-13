#include <block.h>
#include "ext2.h"

/*TODO not right way to get block size */
#define BLOCK_SIZE 1024

/* returns the actual location on the the disk for a given read head */
static int head_location(struct ext2_inode inode,int head)
{
	int block_i = head/BLOCK_SIZE;
	return (inode.i_block[block_i]*BLOCK_SIZE) + (head%BLOCK_SIZE);
}

int ext2_read(struct ext2_inode inode, unsigned int head)
{
	if(head>inode.i_size)
		return -1;
	int hloc = head_location(inode,head);
	return read_from_block_device(hloc);
}
