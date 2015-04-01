#ifndef ICMP
#define ICMP

#define IPV4_PROTO_ICMP 1

#define ICMP_DATA_SIZE 6

#define ICMP_TYPE_ECHO 8
#define ICMP_TYPE_ECHO_REPLY 0

struct icmp_echo_msg {
	uint8_t type;
	uint8_t code;/* always 0 */
	uint16_t checksum;
	uint16_t id;
	uint16_t seq;
	uint8_t data[ICMP_DATA_SIZE];/*data that should be sent back to us.*/
}__attribute__((packed));

struct icmp_echo_msg create_echo();

#endif
