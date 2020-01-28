/* 
* Author : Haoyu Wang
* Description:
*	Digits Counting 
*	
*
*
*/

#include <stdio.h>
int main(void) 
{
	int c, whiteCnt, otherCnt, i;
	int digitCnt[10];
	for (i = 0; i < 10; i++)
		digitCnt[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			digitCnt[c - '0'] ++;
		else if (c == ' ' || c == '\n' || c == '\t')
			whiteCnt++;
		else
			otherCnt++;
		}
	printf("digits =");
	for (i = 0; i < 10; i++)
		printf(" %d", digitCnt[i]);
	printf(", white space = %d, other = %d\n", whiteCnt, otherCnt);
	return 0;
}