
CFLAGS=-ffreestanding -fbuiltin -Wall -Wextra
LIBS=-nostdlib  -lgcc

all:
	i686-elf-as boot.s -o boot.o
	i686-elf-gcc -c kernel.c -o kernel.o $(CFLAGS) $(LIBS)
	i686-elf-gcc -c terminal.c -o terminal.o $(CFLAGS) $(LIBS)
	i686-elf-gcc -T linker.ld -o r0nix $(CFLAGS) boot.o kernel.o terminal.o  $(LIBS)

# re-enable this for iso
#	cp r0nix isodir/boot/r0nix
#	cp grub.cfg isodir/boot/grub/grub.cfg
#	grub-mkrescue -d /usr/lib/grub/i386-pc -o r0nix isodir
clean:
	rm *.o
	rm r0nix
	rm *.bin
	rm *.iso	
run:
	qemu-system-i386 -kernel r0nix
