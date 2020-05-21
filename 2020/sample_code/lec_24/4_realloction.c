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
#include <string.h>



int main(int argc, char *argv[]){

	char ss[5];
	char sss[] = "hello";
	char *s = malloc(10);

	// s = "hello";

	printf("ps: %p\n", s);
	//Be careful, bellow is not initialize the element of s
	//It is re asign s to points to a constant string.
	// s = "hello";
	printf("ps: %p\n", s);

	memcpy(s, "Hello", 6);//
	printf("ps: %p\n", s);
	printf("%s\n", s);


	// char *temp = realloc(s, 20);


	s = realloc(s,20);
	// printf("temp: %p\n", temp);
	// printf("%s\n", temp);

	// free(s);
	// // strangely enough the reallocated memory here is not new
	// if (s!=temp) free(s);
	// s = temp;
	printf("ps: %p\n", s);
	printf("%s\n", s);

	

	return 0;
}

