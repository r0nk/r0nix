#!/bin/bash
#move the r0sh program into the initrd

cd ../misc
mkdir mnt
mount initrd mnt
mv r0sh mnt
umount mnt
rmdir mnt
