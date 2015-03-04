#include <multiboot.h>
#include <stdio.h>

/* [MM]TODO: this shouldn't be a global */
struct Multiboot_Information * global_mi = mp;

void trace_multiboot_info(void * mp){
	struct Multiboot_Information * mi = mp;
	kprint_string("\n MultiBoot info:\n");
	kprint_string("flags:");
	kprint_int((unsigned int) mi->flags);
	kprint_string("\n");
	kprint_string("mods_count:");
	kprint_int((unsigned int) mi->mods_count);
	kprint_string("\n");
	kprint_string("mods_addr:");
	kprint_int((unsigned int) mi->mods_addr);
	kprint_string("\n");
	struct Multiboot_Module * mm = (void *) mi->mods_addr;
	kprint_string("  mod.start:");
	kprint_int((unsigned int) mm->mod_start);
	kprint_string("\n");
	kprint_string("  mod.end:");
	kprint_int((unsigned int) mm->mod_end);
	kprint_string("\n");
	kprint_string("  mod.string:");
	kprint_string((char *) mm->string);
	kprint_string("\n");
}
	
void parse_multiboot(void * multiboot_data){
	struct Multiboot_Information * mi = multiboot_data;

	/* TODO we should check the right flag about here */

	/*trace_multiboot_info(mi);*/
}
