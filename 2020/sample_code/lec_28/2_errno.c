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
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]){

	
	for(int i=0;i<10;i++,errno=i){
        // printf("Errno:%2u in ", errno);
    	fprintf(stderr,"Errno:%2u in ", errno);
	    perror("main:");
    }

    // printf("----------\n");

    // for(int i=0;i<10;i++,errno=i){
    //     fprintf(stderr,"In main: Strerror:%s\n", strerror(errno));
    // }

    return 0;
}

