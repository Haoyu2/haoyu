
/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[])
{
  printf("1e40: %f\n",1e40 );
  printf("2e50: %f\n",2e50 );

  printf("1e40 + 2e50: %f\n", 1e40 + 2e50 );
  printf("%g\n", 1e40 + 2e50 );
  printf("%g\n", 1e40 + 2e46 );
  printf("%g\n", 1e40 + 2e45 );
  printf("%f\n", 1e40 + 2e45 );
  // if not round up to the 6 decimal digit, it may also be wrong
  printf("%g\n", pow(2,-126));
}