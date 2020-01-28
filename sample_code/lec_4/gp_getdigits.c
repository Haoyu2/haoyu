/* 
* Author : Haoyu Wang
* Description:
* 0, ASCII encoding
*
* Get all the digits from getchar()
*		 
*
*/


#include <stdio.h>
int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
    	if (c>='0' && c<='9')
        putchar(c);
    return 0;
}
