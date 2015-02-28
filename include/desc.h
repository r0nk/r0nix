#ifndef DESC
#define DESC 1
#include <stdint.h>

struct desc_ptr {
	uint16_t size;
	uint32_t address;
} __attribute__((packed));

struct gate_desc {
	unsigned int a;
	unsigned int b;
} __attribute__((packed));

struct desc_ptr idt_descr;
struct gate_desc idt_table[256];

struct desc_ptr gdt_descr;
uint64_t gdt_table[256];//TODO this should be a desc_ptr

static inline void load_idt(const struct desc_ptr *dtr)
{
	asm volatile("lidt %0"::"m" (*dtr));
}

static inline void load_gdt(const struct desc_ptr *dtr)
{
	asm volatile("lgdt %0"::"m" (*dtr));
}

#endif
