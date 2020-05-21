
/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int a,arr[3];

	printf("%p\n", &a);
	printf("%d\n", a);
	printf("%p\n", arr);
	printf("%p\n", &arr);
	printf("%d\n", arr[0]);


	printf("%d\n", arr[4]);




	return 0;
}