/* File descriptor table */

#define MAX_FD 256

struct File_Descriptor { 
	int (*fd_read)(const void * buf, int nbyte);
}

struct File_Descriptor_Table {
	struct File_Descriptor fd[MAX_FD];
}

struct File_Descriptor_Table fdt;
