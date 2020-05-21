/* 
* Author : Haoyu Wang
* Description:

  
  int setvbuf(FILE *stream, char *buf, int mode, size_t size) 

*  1. _IOFBF(0)  full buffering  (being full cause action)
   2. _IOLBF(1)  line buffering of text files, (a new line character cause action)
   3. _IONBF(2)  no buffering  (every character cause action)
*

   4. If buf is not NULL,it will be used as the buffer; 
      otherwise a buffer will be allocated.

   5. size determines the buffer size.

   6. setvbuf returns non-zero for any error




*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void test_FullBuffering(void);
void test_LineBuffering(void);
void test_NoBuffering(void);



int main(int argc, char *argv[])
{	

	// These are two processes which are different with 
	// two threads. If you donot know, just let it be.

	int pid;
	if (pid=fork()){
    // This is parent process. print out each second
		for(int i=0;i<6;i++){
			fprintf(stderr,"Parent: %d\n", i);
			sleep(1);
		}
	
	}else{	
    // This is child process
		test_FullBuffering();
		// test_LineBuffering();
		// test_NoBuffering();        
    }

    if (pid)
    	fprintf(stderr,"Parent process exits\n");
    else{

        printf("Testing exited\n");
    	for(int i=0;i<3;i++){
            fprintf(stderr,"Child: %d\n", i);
            sleep(1);
        }

        printf("Function exits do not cause flushing\n");
    	printf("Child process exits\n");
    }
	return 0;
}


void test_FullBuffering(void){
	
	int buf_size = 1024;
	char buf[buf_size];
   	memset(buf, 0, buf_size);

    setvbuf(stdout, buf, 0, buf_size);

    printf("To be flushed\n");
    printf("To be flushed\n");
    printf("To be flushed\n");
    printf("To be flushed\n");

    fflush(stdout);
    printf("After flushing. Waiting on exit of process\n");
    sleep(3);
    printf("Testing exits\n");
}



void test_LineBuffering(void){
	
	int buf_size = 1024;
	char buf[buf_size];
   	memset(buf, 0, buf_size);

    setvbuf(stdout, buf, 1, buf_size);

    printf("Sting with new Line Char\n");

    printf("String with no new line");
    printf("again");
    sleep(3);
}


void test_NoBuffering(void){
	
	int buf_size = 1024;
	char buf[buf_size];
   	memset(buf, 0, buf_size);

    setvbuf(stdout, buf, 2, buf_size);

    printf("Just print out every thing immedately\n");

    printf("String with no new line\n");
    printf("again\n");
    sleep(3);
}
