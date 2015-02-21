/* Much of this is taken from linux source */

struct desc_ptr {
	unsigned short size;
	unsigned long address;
} __attribute__((packed));

struct gate_desc {
	unsigned int a;
	unsigned int b;
} __attribute__((packed));

struct desc_ptr idt_descr;
struct gate_desc idt_table[256];

static inline void native_load_idt(const struct desc_ptr *dtr)
{
	asm volatile("lidt %0"::"m" (*dtr));
}
