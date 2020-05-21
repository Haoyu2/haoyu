/* 
* Author : Haoyu Wang
* Descrption:
*
*
*/
#include <stdio.h>




int main(int argc, char *argv[])
{
	
	int a[]= {1,2,3,4}, *p = a;
	
	// How to store the address of p in a variable?

	int **pp = &p;

	printf("%d\n",p[1] );
	printf("%d\n",*(*pp+2) );



	return 0;
}