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

extern int printf (const char *__restrict __format, ...);


int main(int agrc, char *argv[]){

	#ifdef DEBUG
	printf("Compiling time macro DEBUG is being defined");
	printf("%d\n", DEBUG);
	#endif


	#ifdef TESTING
	printf("Compiling time macro TESTING is being defined");
	printf("%d\n", TESTING);
	#endif


	#if defined(DEBUG) && defined(TESTING)
	printf("DEBUG and TESTING are both defined\n"); 
	#endif


}

