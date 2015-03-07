#include <block.h>
#include <init_fs.h>
#include <kprint.h>

#include "ext2/ext2.h"

void init_fs(){
	struct ext2_super_block sb=ext2_get_super_block();
	ext2_trace_super_block(sb);
	struct ext2_group_desc desc = ext2_get_bgdt();
	ext2_trace_group_desc(desc);
	struct ext2_inode root_inode = ext2_get_inode(2);
	ext2_trace_inode(root_inode);
	struct ext2_dir_entry_2 dir = ext2_get_dir_entry(root_inode,0);
	ext2_trace_dir(dir);
	dir = ext2_get_dir_entry(root_inode,1);
	ext2_trace_dir(dir);
	dir = ext2_get_dir_entry(root_inode,2);
	ext2_trace_dir(dir);
	dir = ext2_get_dir_entry(root_inode,3);
	ext2_trace_dir(dir);
}
