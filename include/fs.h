#ifndef fs
#define fs

struct file_descriptor{
	int inode_index;
	int head;
};

#define FDT_SIZE 256
struct file_descriptor fdt[FDT_SIZE];

void init_fs();
int read(int fildes,char * buf, int nbyte);
int open(char *path/*, int oflag*/);

#endif

