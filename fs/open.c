#include "ext2/ext2.h"
#include <kprint.h>
#include <fs.h>

int open(char *path/*, int oflag*/)
{
	struct ext2_inode inode;
	int i=3;//start at three to avoid std-in,out,err
	for(;i<256;i++){
		if(fdt[i].inode_index==0){
			/* then we found a place to put ourselves */
			fdt[i].inode_index = inode_by_path(path,&inode);
			fdt[i].head = 0;
			return i;
		}
	}
	kprintf("open:Couldn't find file to open, returning -1");
	return -1;/* we didn't find it */
}
