
CFLAGS=-ffreestanding -fbuiltin -Wall -Wextra
LIBS=-nostdlib  -lgcc

all:
	i686-elf-as boot.s -o boot.o
	i686-elf-gcc -c *.c  $(CFLAGS) $(LIBS)
	i686-elf-gcc -T linker.ld -o r0nix $(CFLAGS) *.o $(LIBS)

clean:
	rm *.o
	rm std/*.o
	rm r0nix
	rm *.bin
	rm *.iso	
run:
	qemu-system-i386 -kernel r0nix
