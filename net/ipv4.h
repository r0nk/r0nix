#ifndef IPV4
#define IPV4
#include <stdint.h>

uint32_t our_ip_addr;/*TODO*/

struct ipv4_header {
	uint8_t  version_ihl;
	uint8_t  tos;    /*type of service*/
	uint16_t length;
	uint16_t id;
	uint16_t flags_fragoff;
	uint8_t  ttl;
	uint8_t  protocol;
	uint16_t checksum;
	uint32_t source;
	uint32_t dest;
}__attribute__((packed));

#define IPV4_DATAGRAM_DATA_SIZE 1300

struct ipv4_datagram {
	struct ipv4_header hdr;
	uint8_t data[IPV4_DATAGRAM_DATA_SIZE];
}__attribute__((packed));

struct ipv4_datagram create_ipv4_datagram(char * data, int length, 
			char protocol, uint32_t source, uint32_t destination);

uint16_t ipv4_checksum(void * buf, int length);

#endif
