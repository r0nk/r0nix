#!/bin/bash
qemu-system-i386 -monitor stdio -kernel r0nix -no-reboot -initrd misc/initrd \
 -netdev user,id=network0 -device rtl8139,netdev=network0 -redir tcp:5555::80 \
 -no-kvm-irqchip -d guest_errors -D misc/qemu.log
