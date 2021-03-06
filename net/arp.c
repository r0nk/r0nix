#include <drivers/RTL8139.h>
#include "mac.h"
#include "arp.h"

void send_arp_request()
{
	struct arp_packet apkt;
	apkt.hrd = __builtin_bswap16(ARP_HRD_ETHERNET);
	apkt.pro = __builtin_bswap16(ETHRTYPE_IPV4);
	apkt.hln = 6;
	apkt.pln = 4;
	apkt.op  = __builtin_bswap16(ARP_OP_REQUEST);
	/* TODO the rest of these still need to be swapped */
	apkt.sha = our_mac;
	apkt.spa = 0xabcdefab;/*constant because we dont have proto yet*/
	apkt.tpa = 0x08080808;/*yay google!*/
	int i;
	for(i=0;i<200;i++)
		apkt.padding[i]=0;

	struct mac_packet mpkt;
	mpkt=mac_create_pkt((void*)&apkt, sizeof(apkt)+200, ETHRTYPE_ARP);
	rtl_transmit((void*)&mpkt,
			sizeof(apkt)+200 + (sizeof(mpkt)-MAX_MAC_LENGTH));
}
