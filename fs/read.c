#include <fs.h>
#include <kprint.h>
#include "ext2/ext2.h"

int read(int fildes,char * buf, int nbyte)
{
	struct ext2_inode inode;
	int i,c=0;
	if(fildes==0){/* Then they're reading from standard input */
	//	read_stdin(buf,nbyte);
		kprintf("nyi standard input\n");
		return -1;
	}
	inode = ext2_get_inode(fdt[fildes].inode_index);

	for(i=0;i<nbyte;i++){
		c=ext2_read(inode,fdt[fildes].head);
		fdt[fildes].head++;
		if(c<0){
			kprintf("read err:c<0, c=%x\n",c);
			return -1;
		}
		buf[i]=c;
	}
	return i;
}
