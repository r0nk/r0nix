/* FIXME TODO most of this file has obvious issues */

#include <fs.h>
#include <exec.h>
#include <kprint.h>
#include <panic.h>

#include "elf/elf.h"

void exec(char * path){
	kprintf("exec called...\n");
	void (*program)(void);
	int fd  = open(path);
	if(fd<1){
		panic("Couldn't exec, fd<1");
		return;/* should never occur */
	}
	kprintf("after open\n");
	unsigned int read_bytes=0;
	struct elf32_hdr hdr = get_elf_hdr(fd);
	kprintf("after get_elf_hdr\n");
	struct elf32_phdr phdr = get_elf_phdr(fd);
	program = (void *)hdr.e_entry;

	kprintf("starting reading in program...\n");

	read_bytes=read(fd,(void *)phdr.p_paddr,phdr.p_memsz);
	
	kprintf("bytes read, launching program...\n");

	if(read_bytes==phdr.p_memsz){
		program();
	}else{
		panic("Unable to exec(), not enough bytes read");
	}

}
