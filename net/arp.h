#ifndef ARP
#define ARP
#include <stdint.h>
#include "mac.h"

#define ARP_HRD_ETHERNET 1
#define ARP_OP_REQUEST 1
#define ARP_OP_REPLY 2
#define ETHRTYPE_IPV4 0x800
#define ETHRTYPE_ARP 0x806

struct arp_packet{
	uint16_t hrd;/*hardware field*/
	uint16_t pro;/*protocol field (uses ethrtypes)*/
	uint8_t  hln;/*byte length of each hardware address*/
	uint8_t  pln;/*byte length of each protocol address*/
	uint16_t op;/*opcode (REQUEST|REPLY)*/
	struct mac_address sha;/*sender hardware address*/
	uint32_t spa;/* sender protocol address */
	struct mac_address tha;/*target hardware address*/
	uint32_t tpa;/*target protocol address*/
}__attribute__((packed));

void send_arp_request();

#endif
