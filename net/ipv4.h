#ifndef IPV4
#define IPV4
#include <stdint.h>

struct ipv4_header {
	uint8_t version_ihl;
	uint8_t tos;/*type of service*/
	uint16_t length;
	uint16_t id;
	uint16_t flags_fragoff;
	uint8_t ttl;
	uint8_t protocol;
	uint16_t checksum;
	uint32_t source;
	uint32_t dest;
};

#endif
