/* 
* Author : Haoyu Wang
* Description:
*

0 00000000 00000000000000000000001 2^-149 

0 00000001 00000000000000000000000 2^-126

0 01111111 00000000000000000000000 1

0 00000000 00000000000000000000000 0

1 10000000 00000000000000000000000 -2

*
*/
#include <stdio.h>
#include <math.h>
#include <stdint.h>


// On my little endian machine
typedef union {
  float f;
  struct {
    uint32_t mantisa : 23;
    uint32_t exponent : 8;
    uint32_t sign : 1;
  } layout;
} Float;



// 0 00000000 00000000000000000000001 2^-149 

// 0 0 1
// 0 00000001 00000000000000000000000 2^-126

// 0 1 0
// 0 01111111 00000000000000000000000 1

// 0 127 0
// 0 00000000 00000000000000000000000 0

// 0 0 0
// 1 10000000 00000000000000000000000 -2

// 1 128 0

int main(int argc, char *argv[])
{	
	
	Float f[5];
	f[0].f = pow(2,-149);
	f[1].f = pow(2,-126);
	f[2].f = 1.0;
	f[3].f = 0.0;
	f[4].f = -2.0;

	for (int i=0;i<5;i++)
		printf("For %g\t\t layout is: sign: %u\texponent: %3u\tmantisa: %u\n", f[i].f,
			f[i].layout.sign,f[i].layout.exponent,f[i].layout.mantisa );


}