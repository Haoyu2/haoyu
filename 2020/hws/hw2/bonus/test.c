/*
 *
 * project: hw2_bonus Question
 * name:
 * account: 
 * date: 
 * file: 
 * notes:

0 00000000 00000000000000000000001 2^-149 

0 00000001 00000000000000000000000 2^-126

0 01111111 00000000000000000000000 1

0 00000000 00000000000000000000000 0

1 10000000 00000000000000000000000 -2

    char sm[33], com;
    char sc[33] ={
    '0','0','0','0','0','0',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0'};
    float f=0.0f;
    bin_char(f, sm);
	print_sp(sm);
	com = !(strcmp(sm,sc));
	assert(com);

 */

#include "f2sp.h"
#include <math.h>
#include <string.h>
#include <assert.h>


int main(void)
{

	char sm[33], sc[33], com;
    for (int i=-149; i<128;i ++) {

    	float f = pow(2,i);
        bin_char(f, sm);
        // bin_char(f, sc);
		f2sp(f, sc);
		com = !(strcmp(sm,sc));
		assert(com);    
    }
}




 
