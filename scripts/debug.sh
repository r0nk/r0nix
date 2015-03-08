#!/bin/bash
cd ..
qemu-system-i386 -s -S -kernel r0nix -initrd misc/initrd &
gdb -s r0nix -ex "target remote localhost:1234"
pkill qemu
