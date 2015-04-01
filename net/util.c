#include <stdint.h>
#include <drivers/RTL8139.h>
#include <kprint.h>

#include "util.h"
#include "mac.h"
#include "icmp.h"
#include "ipv4.h"

/* send echo mesg to address, similar to ping terminal utility */
void ping(uint32_t addr)
{
	/* create the icmp packet*/
	struct icmp_echo_msg iem = create_echo();
	/* wrap that in ipv4 */
	struct ipv4_datagram gram = create_ipv4_datagram(&iem,sizeof(iem),
		       	IPV4_PROTO_ICMP,our_ip_addr,addr);
	/* wrap that in link layer */
	struct mac_packet mcpkt = mac_create_pkt( (void *)&gram, 
					__builtin_bswap16(gram.hdr.length),
			       		ETHRTYPE_IPV4);
	/* transmit it. */
	rtl_transmit((void *)&mcpkt,
				(__builtin_bswap16(gram.hdr.length)
		 		+ sizeof(mcpkt.hdr)) );
}
