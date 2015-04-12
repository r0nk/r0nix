#include <fs.h>
#include <panic.h>
#include <kprint.h>

int close(int fildes)
{
	if(fildes>FDT_SIZE){
		kprintf("Tried to close file index out of bounds %x",fildes);
		panic("File close error;index out of bounds");
		return -1;
	}
	fdt[fildes].inode_index = 0;//We just mark this fd as overwritable
	return 0;
}
