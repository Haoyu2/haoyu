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

#ifndef GET2D
#define GET2D(a,type, m,n) \
	type **a = malloc(sizeof(**a) * m); \
	for (int i=0;i<m;i++)				\
		a[i] = malloc(sizeof(*a) * n);
#endif

#ifndef FREE2D
#define FREE2D(a,m,n) \
	for (int i=0;i<m;i++) free(a[i]);free(a);
#endif



#define THREE 3
#define TWO 2







int main(int agrc, char *argv[]){



	GET2D(a,int,THREE,TWO)
	int k = 0;
	for (int i=0;i<THREE;i++){
		for (int j=0;j<TWO;j++)
			a[i][j] = k++;	
	}


	for (int i=0;i<THREE;i++){
		for (int j=0;j<TWO;j++)
			printf("%d,\t", a[i][j]);
		printf("\n");
	}	


	FREE2D(a,THREE,TWO)


	GET2D(b,int,6,6)
	k = 0;
	for (int i=0;i<6;i++){
		for (int j=0;j<6;j++)
			b[i][j] = k++;	
	}


	for (int i=0;i<6;i++){
		for (int j=0;j<6;j++)
			printf("%d,\t", b[i][j]);
		printf("\n");
	}	


	FREE2D(b,6,6)



	return 0;
}

