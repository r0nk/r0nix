#ifndef PAGING
#define PAGING
#include <stdint.h>

/* with 4mb pages, bits 21 through 12 are reversed! (and we use 4mb pages) */

#define PAGE_DIRECTORY_LENGTH 1024 /* = (4gb / 4mb) */

/*we should probably try to use something different here */
#define PAGE_SIZE 4194304

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
	unsigned int addr_bits: 4;
	unsigned int reserved: 5;
	unsigned int frame_addr: 10;
}__attribute__((packed));

/* Just one identity map directory for the whole kernel for now,
 * to serve as the root paging directory.
 */
struct pde kpd[PAGE_DIRECTORY_LENGTH]__attribute__((aligned(4096)));

/*the page the kernel is stored in kpd*/
int k_page_index;

void init_paging(void * kernel_start, void * kernel_end);
void copy_page(uint8_t * source, uint8_t * destination);
void trace_kpd();

/*x86 specific stuff, should probably be moved*/
void flush_tlb_single(unsigned long addr);
void load_crx(struct pde * dir);
void enable_four_mb();

#endif
