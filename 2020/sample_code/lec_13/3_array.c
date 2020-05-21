/* 
* Author : Haoyu Wang
* Description:
* 
* Remedy:
	
		void *malloc(size_t n)
		void *calloc(size_t n, size_t size)

		free(p)

		
*
*/
#include <stdio.h>


int * int_gen(){

	int a[] = {1,2,3};
	return a;
}


int main(int argc, char *argv[])
{
	
	int *p = int_gen();

	printf("%d\n", p[1]);


	return 0;
}