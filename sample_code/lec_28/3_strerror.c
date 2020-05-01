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
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>





int main(int argc, char *argv[])
{
	FILE *fout;
	int last_error = 0;
	if ((fout = fopen(argv[1], "w")) == NULL) {
		last_error = errno;
		/* reset errno and continue */
		errno = 0;
	}
	/* do some processing and try opening the file differently, then */
	if (last_error) {
		fprintf(stderr, "fopen: Could not open %s for writing: %s",
		argv[1], strerror(last_error));
		fputs("Cross fingers and continue", stderr);
	}
	/* do some other processing */
	return EXIT_SUCCESS;
}