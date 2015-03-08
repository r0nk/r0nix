#include "ext2/ext2.h"
#include <fs.h>

int read(int fildes,char * buf, int nbyte)
{
	int i;
	int c=0;
	for(i=0;i<nbyte;i++){
		c=ext2_read(ext2_get_inode(fildes),i);
		if(c<0)
			return -1;
		buf[i]=c;
	}
	return i;
}
