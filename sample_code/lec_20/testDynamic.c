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

	char *lib = argv[1];
	void *lib_D = dlopen(lib, RTLD_LAZY);

	if (lib_D == NULL) { 
		printf("dlopen failed  %s\n", dlerror());
		exit(1);
	}


	int a=2, b=1;
 
	char s[100];
	printf("Input a func name (p1 or p2): ");
	fgets(s, 100, stdin);
	s[strlen(s)-1] = 0;
	void (*func)(void) = dlsym(lib_D,s);
	func();

	printf("Input a func1 name (add, sub or mul): ");
	fgets(s, 100, stdin);
	s[strlen(s)-1] = 0;
	int (*func1)(int, int) = dlsym(lib_D,s);
	printf("%d %s %d is : %d\n", a,s,b,func1(a,b) );

	dlclose(lib_D);


  return 0;
}
