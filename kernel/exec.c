/* FIXME TODO most of this file has obvious issues */

#include <fs.h>
#include <elf.h>

void exec_init_shell()
{
	void (*program)(void);
	int fd  = open("/bin/r0sh");
	struct elf32_hdr elf_hdr = get_elf_hdr(fd);
	struct elf32_phdr elf_phdr = get_elf_phdr(fd);
	program = (void *)elf_hdr.e_entry;
	program();
}
