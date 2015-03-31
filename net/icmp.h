#ifndef ICMP
#define ICMP

struct icmp_echo_msg {
	uint8_t type;
	uint8_t code;/* always 0 */
	uint16_t checksum;
	uint16_t id;
	uint16_t seq;
};

#endif
