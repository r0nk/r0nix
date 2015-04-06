#!/bin/bash
qemu-system-i386 -s -S -kernel r0nix -no-reboot -initrd misc/initrd &
gdb -s r0nix -ex "target remote localhost:1234"
pkill qemu
