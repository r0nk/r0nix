#ifndef MAC
#define MAC
#include <stdint.h>

#define MAX_MAC_LENGTH 1500

#define ETHRTYPE_IPV4 0x800
#define ETHRTYPE_ARP 0x806

struct mac_address {
	uint8_t o[6];
}__attribute__((packed));

struct mac_address our_mac;

struct mac_hdr {
	struct mac_address destination;
	struct mac_address source;
	uint16_t type;
}__attribute__((packed));

struct mac_packet {
	struct mac_hdr hdr;
	uint8_t data[MAX_MAC_LENGTH];
}__attribute__((packed));

struct mac_address our_mac;

struct mac_packet mac_create_pkt(char * packet, int size, int type);

#endif
