#include <kprint.h>
#include "ext2.h"

void ext2_trace_inode(struct ext2_inode in)
{
	int i;

	kprintf("i_mode: %x\n",in.i_mode);
	kprintf("i_uid: %x\n",in.i_uid);
	kprintf("i_size: %x\n",in.i_size);
	kprintf("i_atime: %x\n",in.i_atime);
	kprintf("i_ctime: %x\n",in.i_ctime);
	kprintf("i_mtime: %x\n",in.i_mtime);
	kprintf("i_dtime: %x\n",in.i_dtime);
	kprintf("i_gid: %x\n",in.i_gid);
	kprintf("i_links_count: %x\n",in.i_links_count);
	kprintf("i_blocks: %x\n",in.i_blocks);
	kprintf("i_flags: %x\n",in.i_flags);
	for(i=0;i<EXT2_N_BLOCKS;i++)
		kprintf("in.i_block[%x]: %x",i,in.i_block[i]);
	kprintf("i_generation: %x\n",in.i_generation);
	kprintf("i_file_acl: %x\n",in.i_file_acl);
	kprintf("i_dir_acl: %x\n",in.i_dir_acl);
	kprintf("i_faddr: %x\n",in.i_faddr);
	/* theres more here, but we cheat */
};

struct ext2_inode ext2_get_inode(int disk_num, int inode_num)
{
	struct ext2_inode inode;
/* TODO
 * OSDEVWIKI How to Read An Inode:
 * 1. Read the Superblock to find the size of each block, the number of blocks 
 *     per group, number Inodes per group, and the starting block of the first 
 *     group (Block Group Descriptor Table).
 * 2. Determine which block group the inode belongs to.
 * 3. Read the Block Group Descriptor corresponding to the Block Group which
 *     contains the inode to be looked up.
 * 4. From the Block Group Descriptor, extract the location of the block 
 *     group's inode table.
 * 5. Determine the index of the inode in the inode table.
 * 6. Index the inode table (taking into account non-standard inode size).
*/
}
