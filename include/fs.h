#ifndef FS
#define FS

#include <stdint.h>

void init_fs();
int open(char *path/*, int oflag*/);
int close(int fildes/*, int oflag*/);
int read(int fildes,char * buf,int nbyte);
int write(int fildes,char * buf,int nbyte);
int lseek(int fildes,int offset,int whence);

/* None of the files functions have fildes, because we've already gone through
 * the fildes to access the struct.
 */
struct file{
	long long int head;
	int inode_index;/*TODO shouldn't be here*/
	int (*read)(void *buf, int nbyte);
	int (*write)(void *buf, int nbyte);
	int (*close)();
	int (*lseek)(int offset, int whence);
	uint8_t type;
#define FT_UNKNOWN 	0
#define FT_REG_FILE 	1
#define FT_DIR 		2
#define FT_CHRDEV 	3
#define FT_BLKDEV 	4
#define FT_FIFO 	5
#define FT_SOCK 	6
#define FT_SYMLINK 	7
};

#define FDT_SIZE 256
struct file fdt[FDT_SIZE];

#endif
