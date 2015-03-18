#include <panic.h>
#include <block.h>
#include <kprint.h>
#include "ext2.h"

/* returns the actual location on the the disk for a given read head */
static int head_location(struct ext2_inode inode,int head)
{
	int block_i = head/ext2_block_size;
	if(block_i>11)
		panic(" TODO indirect ext2 pointers nyi.");
	if(inode.i_block[block_i]==0)
		panic("ext2 null head location");

	int block_loc=inode.i_block[block_i] * ext2_block_size;
	return block_loc+(head%ext2_block_size);
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

/*TODO this has to change the size of the file.*/
void ext2_write(struct ext2_inode inode, unsigned int head, uint8_t value)
{
	if(head>inode.i_size){
		/*TODO this should first try to increase the size if possible */
		kprintf("head>inode.i_size, head:%x, inode.i_size:%x\n",
				head,inode.i_size);
		return;
	}
	int hloc = head_location(inode,head);
	write_to_block_device(hloc,value);
}
