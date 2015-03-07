#include "ext2.h"

/*move path to next char, returning the characters moved over*/
static char * till_next_slash(char ** path){
	char *r = *path;
	while(**path!='/' && **path!='\0')
		(*path)++;
	**path='\0';
	(*path)++;
	return r;
}

/* return inode if its path is in dir */
/*
struct ext2_inode inode_in_dir(struct ext2_dir_entry_2 dir,char * name){
	int i;
	struct ext2_inode inode;
	for(i=0;i<num_entries;i++)
		if(ext2_inode)
			return inode;
	return NULL;
}
*/

//struct ext2_dir_entry_2 dir_by_inode(struct ext2_inode inode);

/*
struct inode inode_by_path(char * path){
	struct ext2_inode inode=ext2_get_root_inode(0);
	struct ext2_dir_entry_2 dir=dir_by_inode(inode);
	char * next;
loop:
	next = till_next_slash(&path);
	if(!next)// if no more places to look, then we found it
		return inode;
	inode = inode_in_dir(dir,next);
	if(!inode)
		return NULL;
	dir = dir_by_inode(inode);
	if(!dir)
		return NULL;
	goto loop;
	return NULL;
}
*/
