.global reload_segments
reload_segments:
	mov $0x10,%ax
	mov %ax,%ds
	mov %ax,%es
	mov %ax,%fs
	mov %ax,%gs
	mov %ax,%ss
	ljmp $0x08, $fake_label
	fake_label:
		ret

