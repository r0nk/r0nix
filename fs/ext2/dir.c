/* directory based handlers */
#include <block.h>
#include <kprint.h>
#include "ext2.h"


/* Returns the size of the dir_entry that starts at the offset on the disk */
static int dir_size(int disk_num,int offset){
	int i;
	struct ext2_dir_entry_2 dir;
	char * p = (char *)&dir;
	for(i=0;i<6;i++)
		p[i]=read_from_block_device(disk_num,offset+i);
	return dir.rec_len;
}

void ext2_trace_dir(struct ext2_dir_entry_2 dir){
	kprintf("inode: %x \n",dir.inode);
	kprintf("rec_len: %x \n",dir.rec_len);
	kprintf("name_len: %x \n",dir.name_len);
	kprintf("file_type: %x \n",dir.file_type);
	kprintf("name: \"%s\" \n",&dir.name);
}

struct ext2_dir_entry_2 ext2_get_dir_entry(int disk_num,int block_num,int index)
{
	int block_size = 1024;/* TODO FIXME shouldn't assume 1024*/

	/*find the dir*/

	/* the actual dir of the dir on the disk*/
	int offset = block_num*block_size;
	int i;
	for(i=0;i<index;i++)
		offset+=dir_size(disk_num,offset);
	/*get the dir*/
	int dir_length=dir_size(disk_num,offset); /*TODO*/
	struct ext2_dir_entry_2 dir;
	char * p = (char *)&dir;
	for(i=0;i<dir_length;i++)
		p[i]=read_from_block_device(disk_num,offset+i);
	return dir;
}

