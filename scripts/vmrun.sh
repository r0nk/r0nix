#!/bin/bash
qemu-system-i386 -monitor stdio -kernel r0nix -no-reboot -initrd misc/initrd 
# -netdev bridge,br=br0,id=network0 -device rtl8139,netdev=network0 \
# -redir tcp:5555::80 -no-kvm-irqchip
