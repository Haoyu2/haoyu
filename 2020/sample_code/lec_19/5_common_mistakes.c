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

	int *a = malloc(sizeof(*a) * 4);
	a[0] = 1; a[1] =2;

	int *p =a;

	a = a + 1;
	printf("%d\n", *a);
	a = a - 1;
	free(a);

	// *a;

	// free(a);

}

