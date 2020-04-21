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



typedef struct {
	char *p;  /* 8 bytes */
	char c;   /* 1 byte */ // here the c ompiler padded extra 7 bytes 
	long x;   /* 8 bytes */
} foo;


typedef struct __attribute__((__packed__))  {
	char *p;  /* 8 bytes */
	char c;   /* 1 byte */ // for packed structure there is no padding
	long x;   /* 8 bytes */
}foo1;



typedef struct {
	int i;  //4
	short j; //2  2 padded
	int k;  // 4
} Foo2;

typedef struct {
	int i; //4
	short j;  // 2 2 padded
	long k; // 8 
} foo3;

int main(int argc, char *argv[]){

	
	printf("%ld\n", sizeof(foo));
	printf("%ld\n", sizeof(foo1));
	printf("%ld\n", sizeof(Foo2));
	printf("%ld\n", sizeof(foo3));


}