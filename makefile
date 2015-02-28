CFLAGS=-ffreestanding -fbuiltin -Wall -Wextra -g
LIBS=-nostdlib  -lgcc
CC=i686-elf-gcc
AS=i686-elf-as

all:
	$(AS) boot.s -o boot.o
	$(AS) reload_segments.s -o reload_segments.o
	$(AS) interrupt_handler.s -o interrupt_handler.o
	$(CC) -c *.c  $(CFLAGS) $(LIBS)
	$(CC) -T linker.ld -o r0nix $(CFLAGS) *.o $(LIBS)

clean:
	rm *.o
	rm std/*.o
	rm r0nix
	rm *.bin
	rm *.iso	
r:
	qemu-system-i386 -curses -kernel r0nix -d int -D qemu.log -no-reboot 
run:
	qemu-system-i386 -monitor stdio -kernel r0nix -d int -D qemu.log -no-reboot 
debug:
	qemu-system-i386 -s -S -kernel r0nix &
	gdb -s r0nix -ex "target remote localhost:1234"
	pkill qemu
