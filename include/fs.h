#ifndef fs
#define fs

struct file_descriptor{
	int inode_index;
	int head;
};

#define FDT_SIZE 256
struct file_descriptor fdt[FDT_SIZE];

void init_fs();
int open(char *path/*, int oflag*/);
int close(int fildes/*, int oflag*/);
int read(int fildes,char * buf, int nbyte);
int write(int fildes, char * buf, int nbyte);

#endif
