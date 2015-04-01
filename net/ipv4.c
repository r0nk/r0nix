#include "ipv4.h"

/* this function was taken from thePowersGang's acess2 project */
uint16_t ipv4_checksum(void * buf, int length)
{
	uint16_t *words = buf;
	uint32_t sum = 0;
	int i;

	for(i=0;i<length/2;i++)
		sum+=__builtin_bswap16(words[i]);
	if(length&1)
		sum+=__builtin_bswap16(words[i]&0xFF);
	while(sum>>16)
		sum = (sum & 0xFFFF) + (sum >> 16);
	return ~sum;
}

struct ipv4_datagram create_ipv4_datagram(char * data, int length, 
			char protocol, uint32_t source, uint32_t destination)
{
	int i;
	struct ipv4_datagram gram;
	struct ipv4_header hdr;
	hdr.version_ihl = (0x4<<4) + 5;
		       /*version^    ^IHL*/
	hdr.tos=0;
	hdr.length = __builtin_bswap16(length + sizeof(hdr));
	hdr.id	= 0;/*this has to do with fragments, which is nyi*/
	hdr.ttl = 255;
	hdr.protocol = protocol;
	hdr.source = source;
	hdr.dest = destination;
	hdr.checksum = 0;/*make sure its zero-ed first*/
	hdr.checksum = __builtin_bswap16(ipv4_checksum(&hdr,sizeof(hdr)));
	gram.hdr = hdr;
	for(i=0;i<length;i++)
		gram.data[i]=data[i];
	return gram;
}
