/* 
* Author : Haoyu Wang
* Descrption:
*
*
*/
#include <stdio.h>




int main(int argc, char *argv[])
{
	
	int a[]= {1,2,3,4}, *p[4] ;
	
	for (int i=0;i<4;i++){
		p[i] = &a[i];
		printf("%d\n", *p[i]);
	}

	char *s[] = {"Hello", "world"};

	printf("%s\t%s\n", s[0],s[1]);


	return 0;
}