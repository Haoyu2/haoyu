/* 
* Author : Haoyu Wang
* Description:
*		

// standard library function exit ,
// which terminates program execution when it is called.
// 		a return value of 0 signals that all is well; non-zero
// values usually signal abnormal situations.
//feof returns non-zero if the end of file iicator for stream is set

*
*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	FILE *fp; 
	char *prog = argv[0];
	char *text = "text.txt";

	fp = fopen(text, "r");
	if (NULL==fp){
		fprintf(stderr, "%s: can't open %s\n",prog, text);
		exit(1);
	}

	char s[100];

	// char *ss;Wrong Segmentation fault (core dumped)

	char *ss = malloc(100);
	while (fgets(ss, 100, fp) !=NULL )
		printf("%s", ss);





	fclose(fp);

	return 0;
	
}



	// char c = fgetc(fp);
	// printf("%c\n", c);

	// long i = ftell(fp);

	// printf("position: %ld\n", i);

	// rewind(fp);

	// printf("position after rewind %ld\n", ftell(fp));

	// fseek(fp,0,SEEK_END);
	// printf("SEEK_END :%d\n", SEEK_END);
	// printf("SEEK_END char %d\n",fgetc(fp) );
	// printf("position after fseek %ld\n", ftell(fp));

	// printf("SEEK_END char %d\n",fgetc(fp) );
	// printf("SEEK_END char %d\n",fgetc(fp) );

	// printf("SEEK_END char %d\n",feof(fp) );


	// char c = fgetc(fp);
	// putchar(c);

	// printf("\n%ld\n", ftell(fp));

	// rewi(fp);
	// printf("%ld\n", ftell(fp));

	// fseek(fp,0,SEEK_END);
	// printf("feof:%d\n", feof(fp));


	// printf("%ld\n", ftell(fp));

	// printf("%d\n", fgetc(fp));

	// printf("feof:%d\n", feof(fp));



	// printf("%d\n", fgetc(fp));
	// printf("feof:%d\n", feof(fp));




	// fclose(fp);
	// char c;
	// while ( (c=fgetc(fp)) != EOF )
	// 	putchar(c);

 //    // !feof(fp) will get EOF once and feof will return 1.
	// // while (!feof(fp)){
	// // 	c = fgetc(fp);
	// // 	putchar(c);
	// // 	if (c==-1) printf("%d\n", c);
	// // }
	// 	