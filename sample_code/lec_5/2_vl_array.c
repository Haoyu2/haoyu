
/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>

void print(int n){
	int a[n];
	for (int i=0;i<n;i++)
		printf("%d\n", a[i]=i);
}


int main(int argc, char *argv[])
{
	print(10);
	print(20);
	return 0;
}