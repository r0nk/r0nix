#include <fs.h>
#include <kprint.h>
#include "elf.h"

void trace_elf_hdr(struct elf32_hdr hdr)
{
	kprintf("ELF_HDR TRACE:\n");
	kprintf("e_type:%x\n",hdr.e_type);
	kprintf("e_machine:%x\n",hdr.e_machine);
	kprintf("e_version:%x\n",hdr.e_version);
	kprintf("e_entry:%x\n",hdr.e_entry);     
	kprintf("e_phoff:%x\n",hdr.e_phoff);     
	kprintf("e_shoff:%x\n",hdr.e_shoff);
	kprintf("e_flags:%x\n",hdr.e_flags);
	kprintf("e_ehsize:%x\n",hdr.e_ehsize);    
	kprintf("e_phentsize:%x\n",hdr.e_phentsize);
	kprintf("e_phnum:%x\n",hdr.e_phnum);
	kprintf("e_shentsize:%x\n",hdr.e_shentsize);
	kprintf("e_shnum:%x\n",hdr.e_shnum);
	kprintf("e_shstrndx:%x\n",hdr.e_shstrndx);
}

void trace_elf_phdr(struct elf32_phdr hdr)
{
	kprintf("p_type:%x\n",hdr.p_type);
	kprintf("p_offset:%x\n",hdr.p_offset);
	kprintf("p_vaddr:%x\n",hdr.p_vaddr);
	kprintf("p_paddr:%x\n",hdr.p_paddr);
	kprintf("p_filesz:%x\n",hdr.p_filesz);
	kprintf("p_memsz:%x\n",hdr.p_memsz);
	kprintf("p_flags:%x\n",hdr.p_flags);
	kprintf("p_align:%x\n",hdr.p_align);
}

struct elf32_hdr get_elf_hdr(int fd)
{
	struct elf32_hdr hdr;
	char * p =(void *) &hdr;
	read(fd,p,sizeof(hdr));
//	trace_elf_hdr(hdr);
	return hdr;
}

struct elf32_phdr get_elf_phdr(int fd)
{
	struct elf32_phdr phdr;
	char * p =(void *) &phdr;
	read(fd,p,sizeof(phdr));
	return phdr;
}
