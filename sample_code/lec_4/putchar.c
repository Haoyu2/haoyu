/* 
* Author : Haoyu Wang
* Description:
* 0, ASCII encoding
*
* play of ASCII and putchar()
*		 
*
*/


#include <stdio.h>
int main(void)
{
    
    // putchar(127);
    // // putchar('字');
    // // putchar("字");
    // putchar(128);

    for (int i=-1;  i<=256; i++){
    	printf("the c of %d is ", (char) i);
    	putchar((char) i);
    	putchar('\n');
    }

    return 0;
}
