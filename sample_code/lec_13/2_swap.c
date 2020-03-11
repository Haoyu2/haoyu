/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>

void swap(int *a, int *b  ){
	
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main(int argc, char *argv[])
{

	int a = -1 , b = 1;
	int *pa=&a, *pb = &b;
	swap(pa,pb);


	// int temp;
	// temp =a;
	// a = b;
	// b = temp;
	printf("%d\t%d\n", a,b);


	return 0;
}