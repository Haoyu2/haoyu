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
#include <dlfcn.h>



int main(int argc, char * argv[]){   

	const int a = 1;
	// int *p4 = &a;
	// read only variable
	// a = 2;
	
	// *p4 = 2;






	int const b=2;

	int c = 1;
	int const *p = &c;// this will make the *p ready-only

	// *p = 2;
	// c = 2;
	p = &b;

	// This statement is wrong because a is constant
	int *const p1 = &c;// this will make the p1 ready-only
	int d = -1;
	// p1 = &a;

	int *const p2;// This is a wild pointer which can not reassigned
	// p2 = &c;

	// p2 = &a;
	int const *const p3 = &c;

	c = 2; // this is ok

	// *p3 = 3; // Wekk this is not.
	// p3 = &d;



	char const s[] = "hello";
	// s[0] = 'c'; 
	char s1[] = "world";
	char const *cs1 = s1;

	// cs1[0] = 'c';
	char *const cs2 = s1;
	// cs2 = s;
    // char  *const 


	


  return 0;
}
