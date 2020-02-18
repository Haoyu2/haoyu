/*
 * Author: Haoyu Wang
 * Notes:
 */


#include <stdio.h>


int main(void)
{
	int c, nw, state;
	nw = state = 0;

	while ((c = getchar()) != EOF) {

		if (c == ' ' || c == '\n' || c == '\t')
			state = 0;
		else if (state == 0) {
			state = 1;
			++nw;
		}
	}
	printf("%d\n", nw);
}