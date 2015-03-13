#include <kprint.h>
#include <block.h>
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
		kprintf("in.i_block[%x]: %x\n",i,in.i_block[i]);
	kprintf("i_generation: %x\n",in.i_generation);
	kprintf("i_file_acl: %x\n",in.i_file_acl);
	kprintf("i_dir_acl: %x\n",in.i_dir_acl);
	kprintf("i_faddr: %x\n",in.i_faddr);
	/* theres more here, but we cheat */
};

struct ext2_inode ext2_get_inode(int inode_num)
{
	struct ext2_inode inode;
	struct ext2_super_block sb = ext2_get_super_block(0);
	int inodes_block_group = (inode_num-1) / sb.s_inodes_per_group;
	struct ext2_group_desc gd = ext2_get_group_desc(inodes_block_group);
	int inode_table_location = gd.bg_inode_table * ext2_block_size;
	int index = (inode_num-1)%sb.s_inodes_per_group;
	int inode_offset = inode_table_location + (index * sb.s_inode_size);
	/* Now that we know the offset, we finally read the inode */
	char * p = (char *)&inode;
	int i;
	for(i=0;i<sb.s_inode_size;i++)
		p[i]=read_from_block_device(i+inode_offset);
	return inode;
}

struct ext2_inode ext2_get_root_inode()
{
	return ext2_get_inode(2);/* root dir always 2 */
}
