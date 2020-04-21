/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>
#include <stdint.h>

// uint8_t  uint16_t uint32_t uint64_t which are equivalent to
// unsigned char unsigned short ...

typedef union {

	unsigned short i;
	struct 
	{
		unsigned char second;
		unsigned char first;
	} chars;          // The char order of course is determined by endianess
 
} S_C;


//actually we can use uint8_t for unsigned char instead
typedef union {
	unsigned ip;
	struct 
	{	
		uint8_t four;
		uint8_t three;
		uint8_t second;
		uint8_t first;
		
	}ip_chars;
} IP;




int main(int argc, char *argv[])
{	
	
	S_C sc;
// A's hex is 0x41  B's hex is 0x42
	sc.i = 0x4142;

	printf("%c\n", sc.chars.first);
	printf("%c\n", sc.chars.second);


	IP ip;
	ip.ip_chars.first = 172; // 172 == 0xac
	ip.ip_chars.second = 0;
	ip.ip_chars.three = 0;
	ip.ip_chars.four = 1;

	printf("%x\n", ip.ip);

	uint8_t *p = (uint8_t *) &ip.ip; // Pointer typecasting 
	printf("%u.%u.%u.%u\n",p[3],p[2],p[1],p[0] );

	// * p +1, *p...  p[1],p[0..]


}