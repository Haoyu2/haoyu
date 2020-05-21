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
#include "ArrayList.h"
#include "ArrayList_Test.h"


int main(int argc, char * argv[]){ 

	ArrayList * al = newArrayList(10, 4, NULL);
	ArrayList al1 = *al;
	al1.info(&al1);
	newArrayList_test();  

	appendArrayList_test();

	mix_test();
}