/* 
* Author : Haoyu Wang
* Description:
* 0, ASCII encoding
*       
*   Let's see an example putchar.c.
*
* 1, getchar() reads one character from user input, show it on the screen,
* 	 and return an integer of that character's ASCII code.
*	
*	(1), if there are more than one character input by user before pressing enter, 
		 getchar() will read the first character, and the rest of the characters 
		 will still be left in buffers waiting for the next invoking of getchar()
		 
         Let's see an example of gp_mine.c
	
    (2)  the key "ENTER" on keyboard acts on two roles for getchar()
         (a) the newline character i.e. '\n', 
         (b) pushing into buffer and getchar() invokes, and user can still 
             input character from keyboard
    (3)  the "CTR D" from keyboard has the similar roles of the "ENTER", pushes into 
         buffer and envokes getchar but the return value of getchar() is integer -1


*		 
*
*/


#include <stdio.h>
int main(void)
{
    int c;
    c = getchar();
    putchar(c);
    printf("\ngetchar() first invoking!\n");

    c = getchar();
    putchar(c);
    printf("\ngetchar() second invoking!\n");
    return 0;
}
