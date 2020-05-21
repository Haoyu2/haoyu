/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>

int j = -2;

int main(int argc, char *argv[])
{
	
	// int i=-1;
	// for ( i ; i<5; i++){
	// 	int i =0;
	// 	printf("%d\n", i);
	// };
	// printf("%d\n", i);
	// extern int j;
	printf("%d\n", j);


	for (int i =0; i<5; i++){
		int j = 0;
		printf("%d\t%d\n", i,j);
		printf("%p\n", &j);
	};
	printf("%p\n", &j);

	return 0;
}