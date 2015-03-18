/* FIXME TODO most of this file has obvious issues (no protection, etc) */

#include <fs.h>
#include <exec.h>
#include <kprint.h>
#include <panic.h>
#include <time_stamp.h>

#include "elf/elf.h"

void exec(char * path){
	void (*program)(void);
	int fd  = open(path);
	if(fd<1){
		kprintf("fd:%x",fd);
		panic("Couldn't exec, fd<1");
		return;/* should never occur */
	}
	unsigned int read_bytes=0;
	struct elf32_hdr hdr = get_elf_hdr(fd);
	struct elf32_phdr phdr = get_elf_phdr(fd);
	program = (void *)hdr.e_entry;

	/*set the fd to zero*/
	close(fd);
	fd = open(path);


	read_bytes=read(fd,(void *)phdr.p_paddr,phdr.p_filesz);

	if(read_bytes==phdr.p_memsz){
		program();
	}else{
		kprintf("bytes read:%x",read_bytes);
		panic("Unable to exec(), not enough bytes read");
	}

}
