/*
 * 
 *
 * project: cs240.h
 * name: 
 * user??
 * date: 
 * file: test.c
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>

void func(int *a[],int n){

	for (int i=0;i<n;i++)
		printf("%d\n", *a[i]);

}

int main(int agrc, char *argv[]){

	
	int arr[] = {1,2,3,4};
	int *a[3], *b[2];


	// a = b;
	int **p = a;

	int x=0;


	// how do we initialize a or b?
	a[0] = &arr[0]; a[1] = arr + 1; a[2] = &arr[1];
	// printf("%p\n", a[0]);
	// printf("%d\n", *p[0]);

	printf("%p\n", a[1]);
	printf("%p\n", a[2]);

	// how do we pass a or b into a function?
	func(a,sizeof(a)/sizeof(int*));


}

