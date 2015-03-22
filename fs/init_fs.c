#include <block.h>
#include <fs.h>
#include <kprint.h>

#include "ext2/ext2.h"

void init_fs()
{
	struct ext2_super_block sb=ext2_get_super_block();
	ext2_block_size = 1024<<sb.s_log_block_size;
	kprintf("inodes per group %x \n",sb.s_inodes_per_group);
}
