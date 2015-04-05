#include <fs.h>
#include <exec.h>
#include <kprint.h>
#include <panic.h>
#include <time_stamp.h>

#include "process.h"
#include "elf/elf.h"

/* parse the executable file and store it into the returned process */
struct process file_to_process(char * path)
{
	unsigned int read_bytes = 0;
	int fd  = open(path);
	if(fd<1)
		panic("file_to_process: fd<1");
	struct elf32_hdr hdr = get_elf_hdr(fd);
	struct elf32_phdr phdr = get_elf_phdr(fd);

	if(hdr.e_phnum>1)
		panic("file_to_process: multi-segment program header,nyi");

	/* set the fd read head to zero */
	close(fd);
	fd = open(path);

	/* TODO read in the whole file to its given page */
	panic("file_to_process: read destination nyi");
	if(read_bytes!=phdr.p_memsz)
		panic("file_to_process: not enough bytes read from file");
}

/* This creates the inital process (which always has pid 1) */
void exec_inital(char * path)
{
	struct process p1 = file_to_process(path);
	add_process(p1);
}

void exec(char * path)
{
	replace_current_process(file_to_process(path));
}
