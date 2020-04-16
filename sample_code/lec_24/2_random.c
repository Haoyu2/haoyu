/*
 * 
 *
 * project: hw4
 * name: 
 * user??
 * date: 
 * file: test.c
 * notes:
 */


#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){

	long seed = 2021;
	srand48(seed);

	for (int i=0;i<10;i++)
		printf("%g\t", drand48());

	printf("\n");
	for (int i=0;i<10;i++)
		printf("%ld\t", lrand48());

	return 0;
}

