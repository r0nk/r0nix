#include <stdint.h>
#include "ipv4.h"
#include "icmp.h"

struct icmp_echo_msg create_echo()
{
	struct icmp_echo_msg iem;
	iem.type= ICMP_TYPE_ECHO ;
	iem.code=0;
	iem.id=0;
	iem.seq=0;
	iem.checksum = 0;
	iem.data[0]='M';
	iem.data[1]='A';
	iem.data[2]='R';
	iem.data[3]='C';
	iem.data[4]='O';
	iem.data[5]='!';
	iem.checksum = __builtin_bswap16(ipv4_checksum(&iem,sizeof(iem)));
	return iem;
}
