CFLAGS=-ffreestanding -fbuiltin -Wall -Wextra -g
LIBS=-Iinclude -nostdlib  -lgcc 
CC=i686-elf-gcc
AS=i686-elf-as

PROJDIR=drivers block lib init arch fs fs/ext2 kernel

SRCFILES:= $(shell find $(PROJDIRS) -type f -name "*.c")

OBJFILES:= $(patsubst %.c,%.o,$(SRCFILES))

.PHONY:all clean run

all: r0nix

r0nix: $(OBJFILES)
	$(AS) init/boot.s -o init/boot.o
	$(AS) arch/reload_segments.s -o arch/reload_segments.o
	$(AS) arch/interrupt_handler.s -o arch/interrupt_handler.o
	$(CC) -T misc/linker.ld -o r0nix $(CFLAGS) $(OBJFILES) init/boot.o arch/reload_segments.o arch/interrupt_handler.o $(LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(LIBS) $< -o $@
clean:
	rm $(OBJFILES)
	rm init/boot.o
	rm arch/reload_segments.o
	rm arch/interrupt_handler.o
	rm r0nix
run:
	./scripts/vmrun.sh

