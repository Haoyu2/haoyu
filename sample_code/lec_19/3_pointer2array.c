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

//a[2][3] 
void func(int (*a)[3], int n){

	for (int i=0;i<n;i++)
		printf("%d\n", a[0][i]);
	//a[0] <==> *a
}


int main(int agrc, char *argv[]){

	int a[] = {1,2,3}, x=0;
	//a1 is wild
	int (*a1)[3]; int *a2[3];

	int b[2][3] = {{1,2,3},{4,5,6}};

	// how do we initialize a1?
	// how do we pass a1 into a function?
	a1 = b;
	printf("%d\n",a1[1][0]);


	func(a1,3);

}

