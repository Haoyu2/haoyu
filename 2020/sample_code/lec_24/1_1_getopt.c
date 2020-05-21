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
#include <unistd.h>

int getopt(int argc, char * const argv[], const char *optstring);
extern char *optarg;
extern int optind, opterr, optopt;

// opterr = 1;


int main(int argc, char *argv[]){
	int c;

	while ((c=getopt(argc,argv,"in:m::")) !=-1){

		switch (c) {
			case 'i':
				printf("Option: %c\n", c);
				break;
			case 'n':
				printf("Option: %c\tArgument: %s\n", c,optarg);
				break;
			case 'm':
				printf("Option: %c\tArgument: %s\n", c,optarg);
				break;
			default :
         		printf("Invalid option\n" );	

		}
	}

	printf("End of parsing argument\n");

	return 0;


}