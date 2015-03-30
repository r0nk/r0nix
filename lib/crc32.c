#include <crc32.h>
#include <stdint.h>

/*'borrowed' from :
 * http://www.cl.cam.ac.uk/research/srg/bluebook/21/crc/node6.html 
 */

#define QUOTIENT 0X04C11DB7
uint32_t crc32(uint8_t * data, int len)
{
	uint32_t result;
	int 	 i,j;
	uint8_t  octet;

	result = -1;/*careful, its unsigned here */

	for(i=0;i<len;i++){
		data++;
		octet = *(data);
		for(j=0;j<8;j++){
			if((octet>>7)^(result>>31)){
				result = (result << 1)^QUOTIENT;
			}else{
				result = (result << 1);
			}
			octet<<=1;
		}
	}
	return ~result;
}

