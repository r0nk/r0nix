#ifndef PAGING
#define PAGING

/* NOTE with 4mb pages, bits 21 through 12 are reversed! 
 * (we use 4mb pages)
 */

struct pde { /*page directory entry*/
	unsigned int present: 1;/*must be 1 to map*/
	unsigned int read_write: 1;/*if 0, writes not allowed*/
	unsigned int super: 1;/*if 0, user not allowed to access*/
	unsigned int write_through: 1;
	unsigned int cache_disable: 1;
	unsigned int accessed: 1;/*whether or not this page has been accessed*/
	unsigned int dirty: 1;/*whether or not this page has been written to*/
	unsigned int page_size: 1;/*must be 1*/
	unsigned int global: 1;
	unsigned int ignored: 3;
	unsigned int pat: 1; /* indirectly determines memory type */
				/*(also reboots the flux capacitor)*/
	unsigned int addr_bits: 4;
	unsigned int reserved: 5;
	unsigned int frame_addr: 10;
}__attribute__((packed));

#define PAGE_DIRECTORY_LENGTH 1024 /* = (4gb / 4mb) */

void init_paging();

#endif
