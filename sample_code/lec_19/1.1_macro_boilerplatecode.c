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
#ifndef TEST_FILE
#define TEST_FILE(f,s,s1) 	\
		if (NULL==f){		\
			fprintf(stderr, "%s: can't open %s\n", s,s1);\
			exit(1);}
#endif

int main(int agrc, char *argv[]){

	char *s = "num.txt";
	FILE *f = fopen(s,"r");
	char *s1 = "nums1.txt";
	TEST_FILE(f,"main",s)

	FILE *f1 = fopen(s1,"r");
	TEST_FILE(f1,"main",s1)

}

