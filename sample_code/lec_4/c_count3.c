/* 
* Author : Haoyu Wang
* Description:
*	Line Counting 
*
*/


#include <stdio.h>
int main(void)
{
    int c, n1;

    n1 = 0;

	while ((c = getchar())!= EOF)
		if (c == '\n')
			++n1;
	printf("%d\n", n1 );
	return 0;
}
