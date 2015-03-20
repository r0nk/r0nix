# Declare constants used for creating a multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

#.section .heap, "aw", @nobits
heap_bottom:
.skip 16384 # 16 KiB
heap_top:

.section .text
.global _start
.type _start, @function
_start:
	movl $stack_top, %esp

	push %ebx /*Multi-boot header is stored in ebx, so we push it*/
	push $heap_bottom

	call kernel_main

	cli
.Lhang:
	hlt
	jmp .Lhang

.size _start, . - _start
