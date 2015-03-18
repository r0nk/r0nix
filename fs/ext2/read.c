#include <block.h>
#include <kprint.h>
#include "ext2.h"

/* returns the actual location on the the disk for a given read head */
static int head_location(struct ext2_inode inode,int head)
{
	/* TODO this should take into account indirect block pointers, etc.*/
	int block_i = head/ext2_block_size;
	return (inode.i_block[block_i]*ext2_block_size)+(head%ext2_block_size);
}

int ext2_read(struct ext2_inode inode, unsigned int head)
{
	if(head>inode.i_size){
		kprintf("head>inode.i_size, head:%x, inode.i_size:%x\n",
				head,inode.i_size);
		return -1;
	}
	int hloc = head_location(inode,head);
	int ret = read_from_block_device(hloc);
	return ret;
}
