#include <block.h>
#include <init_fs.h>
#include <kprint.h>

#include "ext2/ext2.h"

void init_fs(int which){
	ext2_trace_super_block(ext2_get_super_block(which));
}
