#include <mm.h>
#include <panic.h>

#include "mac.h"

struct mac_address our_mac = {{0x18,0xcf,0x58,0x4,0xee,0xaa}};

/* just broadcast to all for now */
struct mac_address dest_mac = {{0xff,0xff,0xff,0xff,0xff,0xff}};

struct mac_packet mac_create_pkt(char * packet, int size,int type)
{
	struct mac_packet mcpkt;
	mcpkt.preamble_sfd=0x555555555555d5;
	mcpkt.destination = dest_mac;
	mcpkt.source = our_mac;
	if(size>MAX_MAC_LENGTH)
		panic("mac packet too large");
	if(type)
		mcpkt.length=type;
	else
		mcpkt.length=size;
	int i;
	for(i=0;i<=size;i++)
		mcpkt.data[i]=packet[i];
	return mcpkt;
}
