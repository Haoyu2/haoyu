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
	
	printf("%d\n", *p);
	printf("%d\n", *(p++));
	printf("%d\n", p[1]);


	printf("%d\n", p < &a[3]);


	return 0;
}