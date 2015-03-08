#!/bin/bash
cd ..
qemu-system-i386 -monitor stdio -kernel r0nix -no-reboot -initrd misc/initrd 
