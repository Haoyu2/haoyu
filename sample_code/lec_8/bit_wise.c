/*
 * Author: Haoyu Wang
 * Notes:
 */


#include <stdio.h>

void bin(unsigned n) 
{ 
    unsigned i, j=0; 
    for (i = 1 << 31; i > 0; i = i / 2) {
        (n & i)? printf("1"): printf("0"); 
        if(!((j+1)%8)) printf("  ");
        else if (!((j+1)%4))
        	printf("|");
        j++;
    }
    printf("\n");
}



unsigned getlower(unsigned x, int n)
{
	return (x  & ~(~0 << n));
}

unsigned gethigher(unsigned x, int n)
{
	return (x  & (~0 << (32 - n))) >> (32 - n);
}

/* getbits: get n bits from position p 
*  For example, getbits(x,4,3) returns 
*  the three bits in positions 4, 3 and 2, right-adjusted.
*/
unsigned getbits(unsigned x, int p, int n)
{

	return (x >> (p+1-n)) & ~(~0 << n);
}



int main(void)
{
	// printf("%d\n",getlower(15, 3) );
	bin(15);
	bin(getlower(15, 2));
    bin(15<<28);
	bin(gethigher(15<<28,4));
}