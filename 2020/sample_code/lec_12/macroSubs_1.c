/* 
* Author : Haoyu Wang
* Description:
*	Macro Substitution
	
	1.  Simplest Form:
			# define name {replacement text}
*		
		a. Literally the token name will be replaced by the replacement text
		b. Substitutions are made only for tokens, and do not take place
			within quoted strings or substrings.
			For example, if YES is a defined name, 
			there would be no substitution in printf("YES") or in YESMAN.

	2.  
	
*/
#include <stdio.h>


#define YES right
#define PI 3.1415726
#define PRINTHELLO printf("HELLO\n");
#define PRINTRIGHT printf("%s\n", YES)

#define PRINTK for (int k=0;k<3;k++) printf("%d\n", k) 
int i = 3;
#define PRINT3 printf("%d\n", i) 
#define PRINT4 int j=4; printf("%d\n", j)

int main(int argc, char *argv[])
{
	char right[] ="hello";
	printf("%s\n", YES);
	printf("YES\n");
	printf("%f\n", PI);
	PRINTHELLO
	PRINTRIGHT;
	PRINT3;
	PRINT4;
	PRINTK;

	
	return 0;
}