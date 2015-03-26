#ifndef MAC
#define MAC
#include <stdint.h>

struct mac_address{
	uint8_t o[6];
}__attribute__((packed));

struct mac_packet{
	uint64_t preamble_sfd;
	struct mac_address destination;
	struct mac_address source;
	uint16_t length;
}__attribute__((packed));

char * mac_encap(char * packet,int size,struct mac_address destination);

#endif
