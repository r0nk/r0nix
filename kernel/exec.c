#include <fs.h>
#include <exec.h>
#include <kprint.h>
#include <panic.h>
#include <time_stamp.h>

#include "elf/elf.h"

void exec(char * path)
{
	unsigned int read_bytes = 0;
	int fd  = open(path);
	if(fd<1)
		panic("exec:fd<1");
	struct elf32_hdr hdr = get_elf_hdr(fd);
	struct elf32_phdr phdr = get_elf_phdr(fd);

	if(hdr.e_phnum>1)
		panic("exec: multi-segment program header,nyi");

	/* set the fd read head to zero */
	close(fd);
	fd = open(path);

	/* TODO read in the whole file to its given page */
	panic("exec: read destination nyi");
	if(read_bytes!=phdr.p_memsz)
		panic("exec: not enough bytes read from file");
	
	/* TODO add it to the schedular and stuff */
}
