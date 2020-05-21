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



int main(int agrc, char *argv[]){

	int a[2][2][2] = {	
						{
							{1,2},
							{3,4}
						}, 
					    {
						  	{5,6},
						  	{7,8}
					    }
					};

	int (*a1)[2][2]; 
	// how to initialize a1?

	a1 = a; // is this correct? what does this mean?

	// printf("%d\n",a1[0][0][0] );

	int *a2[2][2];

	// what is a2? do is initialized, or how do we initialize it?
	// after a2's initilizing, how to assign values?

	
	a2[0][0] = &a[0][0][0];
	a2[0][0] = a[0][0] + 1;

	printf("%d\n", *a2[0][0]);

	// a2[1][1] = a[1][0] + 1; // is this correct? 


	int *(*a3)[2];

	//how about a3?

	a3 = a2;
	printf("%d\n", *a3[0][0]);

	



}

