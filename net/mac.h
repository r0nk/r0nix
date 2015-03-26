#ifndef MAC
#define MAC

struct mac_address{
	uint8_t o[6];
};

struct mac_packet{
	uint64_t preamble_sfd;
	struct mac_address destination;
	struct mac_address source;
	uint16_t length;
};

#endif
