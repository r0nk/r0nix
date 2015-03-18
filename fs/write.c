#include <panic.h>
#include <kprint.h>
#include <fs.h>

/*TODO as for right now, write only works with standard output */
int write(int fildes, const void * buf, int nbyte)
{
	if(fildes!=1)
		panic("Write attempt while fildes !=1, NYI");
	kprintf("%s",buf);
	return nbyte;
}
