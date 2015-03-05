/* directory based handlers */
#include <block.h>
#include "ext2.h"

/* Returns the size of the dir_entry that starts at the offset on the disk */
int dir_size(int disk_num,int offset){
	/* TODO */
	disk_num++;
	offset++;
	return 0;
}

struct ext2_dir_entry_2 ext2_get_dir_entry(int disk_num,int block_num,int index)
{
	int block_size = 1024;/* TODO FIXME shouldn't assume 1024*/

	/*find the dir*/

	/* the actual dir of the dir on the disk*/
	int offset = block_num*block_size;
	int i;
	for(i=0;i<index;i++);

	/*get the dir*/
	int dir_length= 0; /*TODO*/
	struct ext2_dir_entry_2 dir;
	char * p = (char *)&dir;
	for(i=0;i<dir_length;i++)
		p[i]=read_from_block_device(disk_num,offset);
	return dir;
}

/*
struct ext2_dir_entry_2 {
	uint32_t	inode;	
	uint16_t	rec_len;
	uint8_t	name_len;	
	uint8_t	file_type;
	char	name[];		
};
*/
