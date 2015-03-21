#!/bin/bash
qemu-system-i386 -s -S -kernel r0nix -initrd misc/initrd -net nic,model=rtl8139 &
gdb -s r0nix -ex "target remote localhost:1234"
pkill qemu
