#!/bin/bash
qemu-system-i386 -s -S -kernel r0nix -no-reboot -initrd misc/initrd -netdev user,id=network0 -device rtl8139,netdev=network0 -redir tcp:5555::80 &
gdb -s r0nix -ex "target remote localhost:1234"
pkill qemu
