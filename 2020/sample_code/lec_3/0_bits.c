/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>
#include <float.h>
#include <limits.h>

void bin_char(unsigned char n) 
{ 
    printf("%11d\t:\t",(signed char) n );
    unsigned i, j=0; 
    for (i = 1 << 7; i > 0; i = i / 2) {
        (n & i)? printf("1"): printf("0"); 

    }
    printf("\n");
}

void bin(unsigned n) 
{ 
    printf("%11d\t:\t",n );
    unsigned i, j=0; 
    for (i = 1 << 31; i > 0; i = i / 2) {
        (n & i)? printf("1"): printf("0"); 
        if( (j+1) % 8==0) printf(" ");
        j++;
    }
    printf("\n");
}

int main(void)
{


    bin(INT_MIN);
    bin_char(CHAR_MIN);
    

  return 0;
}