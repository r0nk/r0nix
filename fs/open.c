#include "ext2/ext2.h"
#include <kprint.h>
#include <fs.h>

int open(char *path/*, int oflag*/)
{
	struct ext2_inode inode;
	int i;
	for(i=0;i<256;i++){
		if(fdt[i].inode_index==0)
			goto cont;/* then we found a place to put ourselves */
	}
	return -1;/* we didn't find it */
cont:
	fdt[i].inode_index = inode_by_path(path,&inode);
	fdt[i].head = 0;
	return i;
}
