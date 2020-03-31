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


int main(int agrc, char *argv[]){



	int **a = malloc(sizeof(**a) * THREE);

	int k=0;
	for (int i=0;i<THREE;i++){
		a[i] = malloc(sizeof(*a) * TWO);
		for (int j=0;j<TWO;j++)
			a[i][j] = k++;	
	}

	int **b = malloc(sizeof(**b) * TWO);

	k=0;
	for (int i=0;i<TWO;i++){
		b[i] = malloc(sizeof(*b) * THREE);
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

