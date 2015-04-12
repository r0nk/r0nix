/* Block Group Descriptor */
#define BGDT_OFFSET 2048
#include <block.h>
#include <kprint.h>
#include "ext2.h"

#if 0
void ext2_trace_group_desc(struct ext2_group_desc d){
	kprintf(" ext2 group_desc trace \n");
	kprintf("bg_block_bitmap:       %x\n",d.bg_block_bitmap);
	kprintf("bg_inode_bitmap;       %x\n",d.bg_inode_bitmap);
	kprintf("bg_inode_table;        %x\n",d.bg_inode_table);
	kprintf("bg_free_blocks_count;  %x\n",d.bg_free_blocks_count);
	kprintf("bg_free_inodes_count;  %x\n",d.bg_free_inodes_count);
	kprintf("bg_used_dirs_count;    %x\n",d.bg_used_dirs_count);
}
#endif

struct ext2_group_desc ext2_get_group_desc(){
	struct ext2_group_desc desc;
	char * p = (char *)&desc;
	int i;
	for(i=0;i<(24);i++)
		p[i]=read_from_block_device(i+BGDT_OFFSET);
	return desc;
}
