#include "ext2/ext2.h"
#include <kprint.h>
#include <fs.h>

/*TODO HACK this just returns the inode as the fd, which is bad mkay.*/
int open(char *path/*, int oflag*/)
{
	struct ext2_inode inode;
	return inode_by_path(path,&inode);
}
