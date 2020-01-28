/* 
* Author : Haoyu Wang
* Description:
*	word Counting 
*	
*
*
*/


#include <stdio.h>

#define IN 	1 	/* inside a word */
#define OUT 0	/* outside a word */

/* count lines, words, and characters in input */
int main(int argc, char *argv[]) 
{
	int c, numL = 0, numW = 0, numC = 0, state = OUT;
	
	while ((c = getchar()) != EOF) {
		numC++;
		if (c == '\n')
			numL++;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT){
			state = IN, numW++;
			}
		}
	printf("%d %d %d\n", numL, numW, numC);
	return 0;
}