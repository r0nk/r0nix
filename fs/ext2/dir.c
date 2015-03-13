/* directory based handlers */
#include <block.h>
#include <kprint.h>
#include "ext2.h"

/* Returns the size of the dir_entry that starts at the offset on the disk */
static int dir_size(int offset)
{
	int i;
	struct ext2_dir_entry_2 dir;
	char * p = (char *)&dir;
	for(i=0;i<6;i++)
		p[i]=read_from_block_device(offset+i);
	return dir.rec_len;
}

void ext2_trace_dir(struct ext2_dir_entry_2 dir)
{
	kprintf(" ---EXT2 DIR TRACE---\n");
	kprintf("inode: %x \n",dir.inode);
	kprintf("rec_len: %x \n",dir.rec_len);
	kprintf("name_len: %x \n",dir.name_len);
	kprintf("file_type: %x \n",dir.file_type);
	kprintf("name: \"%s\" \n",(dir.name));
}

struct ext2_dir_entry_2 ext2_get_dir_entry(struct ext2_inode inode,int index)
{
	struct ext2_super_block sb = ext2_get_super_block(0);
	int block_size = 1024<<sb.s_log_block_size;

	/* find the dir */
	int offset = inode.i_block[0]*block_size;/*TODO it might not be at 0*/
	int i;
	for(i=0;i<index;i++)
		offset+=dir_size(offset);

	/* get the dir */
	struct ext2_dir_entry_2 dir;
	char * p = (char *)&dir;
	int dir_length=dir_size(offset);
	/*read off the name as well*/
	for(i=0;i<dir_length;i++)
		p[i]=read_from_block_device(offset+i);
	p[++i]='\0';/*make sure the name is null terminated*/
	return dir;
}
