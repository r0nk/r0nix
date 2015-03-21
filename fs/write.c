#include <panic.h>
#include <kprint.h>
#include <fs.h>
#include "ext2/ext2.h"

int write(int fildes, char * buf, int nbyte)
{
	struct ext2_inode inode;
	int i;

	if(fildes==1){
		kprintf("%s",buf);
		return nbyte;
	}

	inode = ext2_get_inode(fdt[fildes].inode_index);

	for(i=0;i<nbyte;i++){
		ext2_write(fdt[fildes].inode_index,inode,
				fdt[fildes].head,buf[i]);
		fdt[fildes].head++;
	}
	return nbyte;
}
