/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>


typedef union {
	int i;
	char f;
} Foo;


int main(int argc, char *argv[])
{	
	// This is the correct way of initializing a Union variable
	// We can not initialize a value when define it like structure does.
	// We have to do it separately
	Foo foo;
	// Foo foo.i = 1;// this is wrong
	// Foo foo = {1,1};// This is also wrong

	foo.i = 0x41;// 0x41 which is 'A'

	int a = 0x41;
	printf("%c\n",(char) a);
	printf("%c\n", foo.f);
}