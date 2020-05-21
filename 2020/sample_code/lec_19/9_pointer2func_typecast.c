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
#include <string.h>

// The key here is to use void pointer as arguments and return type
// since it can be cast back and forth without loss of information 
void *getMax(void *s[],  int n ,int (*com)(void*,void*)){
	void *m;
	m = s[0];
	for (int i=1;i<n;i++){
		if (com(s[i],m) > 0)   m=s[i];
	}
	return m;
}





int num_com(int *a, int*b){
	return *a>*b;
}

int main(int agrc, char *argv[]){


	// char *s[] = {"how","you","doing"};

	// char *s1[] = {"a","b","c"};

	// // printf("%d\n", strcmp("how","you") );

	// getMax((void *) s, 3, (int (*)(void *, void *)) strcmp  );


	// printf("%s\n", (char *) getMax((void *) s1, 3, (int (*)(void *, void *)) strcmp  ) );


	int a[] = {1,2,3,4,10}, *p;
	int *b[] = {a,a+1,a+2,a+3,a+4};

	printf("%d\n", *b[0]);

	printf("%d\n", * (int *) getMax((void *) b,5, (int (*)(void *, void *)) num_com));



	
}





