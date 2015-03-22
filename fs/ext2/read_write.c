#include <panic.h>
#include <block.h>
#include <kprint.h>
#include <stdint.h>
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

uint32_t ext2_new_block()
{
	/*
	struct ext2_group_desc gd = ext2_get_group_desc();
	int block_bitmap = gd.bg_block_bitmap*ext2_block_size;
	int i,j=0;
	for(i=0;i<ext2_block_size;i++){
		j=read_from_block_device(block_bitmap+i);
		if(j<0xff){
			//TODO find the right place
			break;
		}
	}
	ext2_write_group_desc(gd);
	*/
	panic("ext2_new_block nyi");
	return -1;
}

void increase_inode_size(struct ext2_inode * inode,int inode_index)
{
	int block_index;
	inode->i_size++;
	block_index = inode->i_size/ext2_block_size;
	if(block_index>11)
		panic("TODO indirect ext2 pointers nyi, i_i_s");
	if(inode->i_block[block_index]==0)
		inode->i_block[block_index]=ext2_new_block();
	ext2_write_inode(*inode,inode_index);
}

int ext2_read(struct ext2_inode inode, unsigned int head)
{
	if(head>inode.i_size){
		kprintf("read:head>inode.i_size, head:%x, inode.i_size:%x\n",
				head,inode.i_size);
		return -1;
	}
	int hloc = head_location(inode,head);
	int ret = read_from_block_device(hloc);
	return ret;
}

void ext2_write(int inode_index,struct ext2_inode inode, unsigned int head, 
		uint8_t value)
{
	int hloc;
	if(head>inode.i_size){
		increase_inode_size(&inode,inode_index);
	}
	hloc = head_location(inode,head);
	write_to_block_device(hloc,value);
}
