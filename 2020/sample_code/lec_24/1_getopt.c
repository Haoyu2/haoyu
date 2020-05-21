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
extern char *optarg; // points to the argument of each option 
extern int optind, opterr, optopt;


int main(int argc, char *argv[]){


	int n = 10, c;
	char optstring[] = "in:s::x::";
	




	char *s[] = {"program_name" ,
				  "no way",
				  "-i",
				  "-n","hello", // single colon
  				  "all right",
				  "-sworld",    // double colon
				  "ok?",
				  "-x",	};

	c = getopt(n,s,optstring);
	printf("option: %c\t%s\n", c,optarg);


	c = getopt(n,s,optstring);
	printf("option: %c\t%s\n", c,optarg);


	c = getopt(n,s,optstring);
	printf("option: %c\t%s\n",c, optarg);


	c = getopt(n,s,optstring);
	printf("option: %c\t%s\n", c,optarg);

	// Some compiler doesnot print out (null), be carefull
	// if (optarg == NULL) printf("option: %c\toptarg is NULL\n", c);







}