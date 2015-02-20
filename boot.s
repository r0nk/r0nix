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

.section .text
.global _start
.type _start, @function
_start:
movl $stack_top, %esp

call kernel_main

# In case the function returns, we'll want to put the computer into an
# infinite loop. To do that, we use the clear interrupt ('cli') instruction
# to disable interrupts, the halt instruction ('hlt') to stop the CPU until
# the next interrupt arrives, and jumping to the halt instruction if it ever
# continues execution, just to be safe. We will create a local label rather
# than real symbol and jump to there endlessly.
cli
hlt
.Lhang:
jmp .Lhang

# Set the size of the _start symbol to the current location '.' minus its start.
# This is useful when debugging or when you implement call tracing.
.size _start, . - _start
