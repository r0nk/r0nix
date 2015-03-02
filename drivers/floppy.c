#include "include/floppy.c"

void initalize_floppy(){
/* 1. Send a Version command to the controller. */
	issue_floppy_command(version);
/*
 2. Verify that the result byte is 0x90 - if it is not, it might be a good idea
  to abort and not support the floppy subsystem. Almost all of the code based
  on this article will work, even on the oldest chipsets - but there are a 
  few commands that will not.
 3. If you don't want to bother having to send another Configure command after
  every Reset procedure, then:
    1. Send a better Configure command to the controller. A suggestion would be:
     drive polling mode off, FIFO on, threshold = 8, implied seek on, 
     precompensation 0.
    2. send a Lock command.
 4. Do a Controller Reset procedure.
 5. Send a Recalibrate command to each of the drives.
*/
	;
}
void reset_floopy(){
/*
 1. Bit 2 (value = 4) in the DOR: Save the current/"original" value of the 
 DOR, write a 0 to the DOR, wait 4 microseconds, then write the original
 value (bit 2 is always set) back to the DOR.
 */
	int original = inb(DIGITAL_OUTPUT_REGISTER);
	outb(DIGITAL_OUTPUT_REGISTER,0);
	//TODO wait 4 microseconds,
	outb(DIGITAL_OUTPUT_REGISTER,original);
 /*
 2. Wait for the resulting IRQ6 (unless you have IRQs turned off in the DOR)
 3. If (and only if) drive polling mode is turned on, send a 4 Sense Interrupt
 commands (required).
 4. If your OS/driver never sent a Lock command, then you probably need to send
 a new Configure command (the fifo settings were lost in the reset).
 5. Do a Drive Select procedure for the next drive to be accessed.
 */
	;
}

/* the comments are from osdev */

void issue_floppy_command(int command){
start:
/*
 1. Read MSR (port 0x3F4).
 2. Verify that RQM=1 and DIO=0((value & 0xc0)==0x80) -- if not,reset the 
 controller and start all over.
 */
	if(!((inb(0x3F4)&0xc0)==0x80)){
		reset_floppy();
		goto start;
	}

/* 3. Send your chosen command byte to the FIFO port (0x3F5). */
	outb(0x3F5,command);

/*
 4. In a loop: loop on reading MSR until RQM=1. Verify DIO=0, then send the next
 parameter byte for the command to the FIFO port.*/
	while(inb(0x3F4)&0x80!=1);
	//TODO send more parameter bytes
/*
 5. Either Execution or Result Phase begins when all parameter bytes have been
 sent, depending on whether you are in PIO mode, and the command has an 
 Execution phase. If using DMA, or the command does not perform read/write/head
 movement operations, skip to the Result Phase.
 6. (In PIO Mode Execution phase) read MSR, verify NDMA = 1 ((Value & 0x20)==
 0x20) -- if its not set, the command has no Execution phase, so skip to Result
 phase.
 7. begin a loop:
 8. Either poll MSR until RQM = 1, or wait for an IRQ6, using some waiting 
 method.
 9. In an inner loop: transfer a byte in or out of the FIFO port via a system
 buffer, then read MSR. Repeat while RQM=1 and NDMA=1 ((Value & 0xa0)== 0xa0).
 10. if NDMA = 1, loop back to the beginning of the outer loop, unless your
 data buffer ran out (detect underflow/overflow).
 */
result_phase:
/*
 11. Result phase begins. If the command does not have a Result phase, it 
 silently exits to waiting for the next command. 
 12. If using DMA on a read/write command, wait for a terminal IRQ6.
     1. Loop on reading MSR until RQM=1, verify that DIO=1.
     2. In a loop: read the next result byte from the FIFO, loop on reading MSR
     until RQM=1, verify CMD BSY=1 and DIO=1 ((Value & 0x50)==0x50);
 13. After reading all the expected result bytes: check them for error 
 conditions, verify that RQM=1, CMD BSY=0, and DIO=0. _if not_ retry the entire
 command again, several times, starting from step 2!
*/
	;
}

