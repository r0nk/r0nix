#include <elf.h>
#include <fs.h>

struct elf32_hdr get_elf_hdr(int fd)
{
	struct elf32_hdr hdr;
	char * p =(void *) &hdr;
	read(fd,p,sizeof(hdr));
	return hdr;
}
