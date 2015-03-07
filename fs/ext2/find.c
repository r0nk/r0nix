#include "ext2.h"

/* get rid of all the slashy things */
static char ** split_path(char * path){/*TODO*/}

static int num_dirs(char * path){/*TODO*/}

/*TODO next_inode(){ */

struct inode find_by_path(char * path){
	int dirs_left = num_dirs(path);
	char ** dirs = split_path(path);
	struct inode cur_inode=ext2_get_root_inode(0);
	while(dirs_left){
		if(!(cur_inode=next_inode()))
			return null;
		dirs_left--;
	}
	return cur_inode;
}
