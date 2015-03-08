#include "ext2/ext2.h"

int open(const char *path/*, int oflag*/){
	struct ext2_inode inode	
	if(!inode_by_path(path,&inode))
		return 0;
	return get_fd(inode);
}
