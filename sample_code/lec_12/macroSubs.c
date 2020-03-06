/* 
* Author : Haoyu Wang
* Description:
*	

__DATE__  : The current date as a character literal in "MMM DD YYYY" format.

	
__TIME__  : The current time as a character literal in "HH:MM:SS" format.

	
__FILE__  : This contains the current filename as a string literal.


__LINE__  : This contains the current line number as a decimal constant.

	
__STDC__  : Defined as 1 when the compiler complies with the ANSI standard.
	

__STDC_VERSION__: This macro holds the C Standard’s version number 
*/
#include <stdio.h>
#include <limits.h>
#include <assert.h>


int main(int argc, char *argv[])
{
	
   printf("INT_MAX :%d\n", INT_MAX);
   printf("File :%s\n", __FILE__ );
   printf("Date :%s\n", __DATE__ );
   printf("Time :%s\n", __TIME__ );
   printf("Line :%d\n", __LINE__ );
   printf("ANSI :%d\n", __STDC__ );
   printf("C Standard :%ld\n", __STDC_VERSION__);

   assert(1.5);
   // assert(0);

   assert(5*0);



	
	return 0;
}