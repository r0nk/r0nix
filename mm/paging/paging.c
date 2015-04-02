#include "paging.h"
 /* just one identity map for the whole kernel for now*/
struct pde kpd[PAGE_DIRECTORY_LENGTH];

static void init_kpd()
{
	/*we just identity-map everything for now. */
	struct pde def_pde;/* default options */
	def_pde.reserved = 0;
	def_pde.addr_bits = 0;
	def_pde.pat = 0;/*<-- this _might_ not be right...*/
	def_pde.ignored = 0;
	def_pde.global = 0;
	def_pde.page_size = 1;
	def_pde.dirty = 0;
	def_pde.accessed = 0;
	def_pde.cache_disable= 1;
	def_pde.write_through=0;
	def_pde.super=0;
	def_pde.read_write=1;
	def_pde.present=1;
	int i;
	for(i=0;i<PAGE_DIRECTORY_LENGTH;i++){
		def_pde.frame_addr=i;
		kpd[i]=def_pde;
	}
	/*TODO actually put &(kde) into the right register(CR3)*/
}

void init_paging()
{
	init_kpd();
}
