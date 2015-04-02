CFLAGS=-ffreestanding -fbuiltin -Wall -Wextra -g -fdiagnostics-color
LIBS=-Iinclude -nostdlib  -lgcc 
CC=i686-elf-gcc
AS=i686-elf-as

PROJDIR=drivers block lib init arch fs fs/ext2 kernel

SRCFILES:= $(shell find $(PROJDIRS) -type f -name "*.c")

OBJFILES:= $(patsubst %.c,%.o,$(SRCFILES)) init/boot.o arch/reload_segments.o arch/interrupt_handler.o arch/time_stamp.o

.PHONY:all clean run

all: r0nix

r0nix: $(OBJFILES)
	$(CC) -T misc/linker.ld -o r0nix $(CFLAGS) $(OBJFILES) $(LIBS)
%.o: %.c
	$(CC) -c $(CFLAGS) $(LIBS) $< -o $@

%.o: %.s
	$(AS) -c $< -o $@
clean:
	rm $(OBJFILES)
	rm r0nix
run: r0nix
	./scripts/vmrun.sh
