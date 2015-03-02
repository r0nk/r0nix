/* 
 * this handles the multiboot information data structure, as specified
 * in the multiboot specification.
 */
#ifndef MULTI_BOOT
#define MULTI_BOOT 1
#include <stddef.h>

struct Multiboot_Module{
	uint32_t mod_start;
	uint32_t mod_end;
	uint32_t string;
	uint32_t reserved;
};

struct Multiboot_Syms{
	uint32_t a;
	uint32_t b;
	uint32_t c;
};

struct Mutliboot_Information{
	uint32_t flags;
	uint32_t mem_lower;
	uint32_t mem_upper;
	uint32_t boot_device;
	uint32_t cmdline;
	uint32_t mods_count;
	uint32_t mods_addr;
	Multiboot_Syms syms;
	uint32_t mmap_length;
	uint32_t mmap_addr;
	uint32_t drives_length;
	uint32_t drives_addr;
	uint32_t config_table;
	uint32_t boot_loader_name;
	uint32_t apm_table;
	uint32_t vbe_control_info;
	uint32_t vbe_mode_info;
	uint32_t vbe_mode;
	uint32_t vbe_interface_seg;
	uint32_t vbe_interface_off;
	uint32_t vbe_interface_len;
};

void parse_multi_boot(void * multiboot_data);

#endif


