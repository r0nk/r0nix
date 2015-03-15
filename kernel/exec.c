/* FIXME TODO most of this file has obvious issues */

#include <fs.h>
#include <exec.h>
#include <panic.h>

#include "elf/elf.h"

void exec(char * path){
	void (*program)(void);
	int fd  = open(path);
	if(fd<1){
		panic("Couldn't exec, fd<1");
		return;/* should never occur */
	}
	unsigned int read_bytes=0;
	struct elf32_hdr hdr = get_elf_hdr(fd);
	struct elf32_phdr phdr = get_elf_phdr(fd);
	program = (void *)hdr.e_entry;

	read_bytes=read(fd,(void *)phdr.p_paddr,phdr.p_memsz);

	if(read_bytes==phdr.p_memsz){
		program();
	}else{
		panic("Unable to exec(), not enough bytes read");
	}

}
