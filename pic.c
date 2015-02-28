#include "include/io.h"

#define PIC1			0x20
#define PIC2			0xA0
#define PIC1_COMMAND		PIC1
#define PIC1_DATA		(PIC1+1)
#define PIC2_COMMAND		PIC2
#define PIC2_DATA		(PIC2+1)

#define ICW1_ICW4 		0x01
#define ICW1_SINGLE 		0x02
#define ICW1_INTERVAL4 		0x04
#define ICW1_LEVEL 		0x08
#define ICW1_INIT 		0x10

#define ICW4_8086 		0x01
#define ICW4_AUTO 		0x02
#define ICW4_BUF_SLAVE 		0x08
#define ICW4_BUF_MASTER 	0x08
#define ICW4_BUF_SFNM	 	0x10

void acknowledge_interrupt(int vector)
{
	if (vector >= 20)
		outb(PIC2_COMMAND,0x20);
	outb(PIC1_COMMAND,0x20);
}

void initalize_pic(int master_vector_offset,int slave_vector_offset)
{
	unsigned char mask1,mask2;

	mask1 = inb(PIC1_DATA);
	mask2 = inb(PIC2_DATA);
 	// starts the initialization sequence (in cascade mode)
	outb(PIC1_COMMAND, ICW1_INIT+ICW1_ICW4);  
	outb(PIC2_COMMAND, ICW1_INIT+ICW1_ICW4);

	outb(PIC1_DATA, master_vector_offset);
	outb(PIC2_DATA, slave_vector_offset);
	// ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
	outb(PIC1_DATA, 4);
	outb(PIC2_DATA, 2);           
        // ICW3: tell Slave PIC its cascade identity (0000 0010)

	outb(PIC1_DATA, ICW4_8086);
	outb(PIC2_DATA, ICW4_8086);

	outb(PIC1_DATA, mask1);
	outb(PIC2_DATA, mask2);
}
