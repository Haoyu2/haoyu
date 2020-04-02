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


#define THREE 3
#define TWO 2

// What is the total memory allocate for a?
// a is 8
// *a 8*3 24
// **a (4*2)*3 24
// 3 by 2
// in total is 56 bytes.

// 3 by 2
// pointer: 8+24  (1+3)
// integer: 24 (6)


// How about 2 by 3  for b

// b is 8  *b is 8*2 16  **b (4*3)*2=24
// in total 8+16+24 = 48

// a requires 8 more bytes 

//for 2 by 3
//pointer: 8+16 (1+2)
//integer: 24 (6)



int main(int agrc, char *argv[]){


	//arr[3][2] <==>(*arr)[2]
	int **a = malloc(sizeof(*a) * THREE); 
	// This statement is initializing a and the data type a points
	// to is data type of (*a) 

	// a[1],a[2],a[3], has a data type of pointer
	// each of this pointer will points to a one 
	// dimensional of two integers

	int k=0;
	for (int i=0;i<THREE;i++){
		a[i] = malloc(sizeof(**a) * TWO);
		//This is initializing a[i], and a[i] points to a "array" of
		// two integers and it is (**a)
		for (int j=0;j<TWO;j++)
			a[i][j] = k++;	
	}

	printf("sizeof(a)   : %ld\n", sizeof(a));
	// a is varable, and where is it located?
	// a is located in stack memory, and it has 8 bytes, 
	// becasue it is a pointer.
	printf("sizeof(*a)  : %ld\n", sizeof(*a));
	// *a, is located in heap which assigned by malloc
	// *a is also a pointer which has 8 byted for data type length
	printf("sizeof(**a) : %ld\n", sizeof(**a));
	// **a, is located in heap  which assigned by malloc
	// **a is an integer data type which has 4 bytes for data type length

	int **b = malloc(sizeof(*b) * TWO);

	k=0;
	for (int i=0;i<TWO;i++){
		b[i] = malloc(sizeof(**b) * THREE);
		for (int j=0;j<THREE;j++)
			b[i][j] = k++;
	}


	for (int i=0;i<THREE;i++){
		for (int j=0;j<TWO;j++)
			printf("%d,\t", a[i][j]);
		printf("\n");
	}	


	for (int i=0;i<TWO;i++){
		for (int j=0;j<THREE;j++)
			printf("%d,\t", b[i][j]);
		printf("\n");
	}

	for (int i=0;i<THREE;i++) free(a[i]); free(a);
	for (int i=0;i<TWO;i++) free(b[i]); free(b);



}

