#include <stdint.h>
#include "../include/multiboot.h"
#include "../include/block.h"
#include "ramdisk.h"

void * ramdisk1_addr; /*TODO FIXME this is a horrible ugly way of doing it*/

uint8_t ramdisk_read(unsigned long location)
{
	uint8_t * r = (ramdisk1_addr + location);
	return (uint8_t)(*r);
}

void ramdisk_write(unsigned long location,uint8_t value)
{
	uint8_t * r = (ramdisk1_addr + location);
	(*r) = value;
}

void init_ramdisk(void * mp)
{
	struct Multiboot_Module * mm = mp;
	struct Block_Device bd;
	ramdisk1_addr = (void *) mm->mod_start;
	bd.size = mm->mod_start - mm->mod_end;
	bd._read = ramdisk_read;
	bd._write = ramdisk_write;
	gbda[0]=bd;/* FIXME you never saw me doing this horrible hack, k? */
}
