#include <drivers/RTL8139.h>
#include "mac.h"
#include "arp.h"

void send_arp_request()
{
	struct arp_packet apkt;
	apkt.hrd = ARP_HRD_ETHERNET;
	apkt.pro = ETHRTYPE_IPV4;
	apkt.hln = 6;
	apkt.pln = 4;
	apkt.op  = ARP_OP_REQUEST;
	apkt.sha = our_mac;
	apkt.spa = 0xabcdefab;/*constant because we dont have proto yet*/
	apkt.tpa = 0x08080808;/*yay google!*/

	struct mac_packet mpkt;
	mpkt=mac_create_pkt((void*)&apkt, sizeof(apkt), ETHRTYPE_ARP);
	rtl_transmit((void*)&mpkt,sizeof(apkt) + (sizeof(mpkt)-MAX_MAC_LENGTH));
}
