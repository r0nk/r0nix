#include <string.h>
#include <kprint.h>
#include "ext2.h"

/*move path to next char, returning the characters moved over*/
static char * till_next_slash(char ** path)
{
	if(**path=='/')
		(*path)++;
	char *r = *path;
	while(**path!='/' && **path!='\0')
		(*path)++;
	**path='\0';
	(*path)++;
	return r;
}

/* return inode num if it's name is in dir */
int inode_in_dir(struct ext2_inode dir,char * name)
{
	int i;
	i=0;/* you should've been there when I caught this heisenburg man...*/
	struct ext2_dir_entry_2 entry;
	while(1){
		i++;
		entry = ext2_get_dir_entry(dir,i);
		if(!entry.inode)
			return 0;
		if(!strcmp(entry.name,name)){
			return entry.inode;
		}
	}
	return 0;
}

int inode_by_path(char * path,struct ext2_inode * inode)
{
	int i_inode=0;
	*inode=ext2_get_root_inode(0);
	char * next;
	while(1){
		next = till_next_slash(&path);
		kprintf("next: %s\n",next);
		if(!next)/* if no more places to look, then we found it */
			return i_inode;
		i_inode = inode_in_dir(*inode,next);
		if(!inode)/*then one of the elements in the path doesn't exist*/
			return 0;
		*inode = ext2_get_inode(i_inode);
	}
	return 0;
}
