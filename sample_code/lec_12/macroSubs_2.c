/* 
* Author : Haoyu Wang
* Description:
*	Macro Substitution

	2.  Define macros with arguments.
		Form:
			#define name(A,B) [replacement text with A and B]

	 a. Compare to equivalent function call, macro saves the overhead
	 	for creating and destroying the stack fame for the funct.
	 	.ion 
	 b. However you have to be careful about what happens for compound
	 	expressions. It may produce result that is not what you intended.

		(Cure: use () as many as possible to group together the arguments)

	 c. Macro name can be undefined with #undef	such that the name is free
	    to for other use
	
	3 # opereator
	 d. A parameter name of Macro is preceded by a # in the
		replacement text, the combination will be expanded 
		into a quoted string with the parameter replaced by the actual argument.
	4 ## operator
	  e. actucally concatenate two argumants 


*/
#include <stdio.h>


#define max(A, B) ((A) > (B) ? (A) : (B))
#define square_1(x)  x * x
#define square(x) (x) * (x)

// #undef square
// int square(int x){
// 	return x*x;
// }




int main(int argc, char *argv[])
{

// /************************************************/

// 	printf("max(1,2) is %d\n", max(1,2));
// 	// this is equivalent to 
// 	// printf("%d\n", ((1) > (2) ? (1) : (2)));
// 	// which is different from function call since 
// 	// there are no stack frame gets created and destroyed 
// 	//  this is just an statement
	
// **********************************************


// 	int i=1,j=2;
// 	// Be careful about what happens for compound expressions
// 	printf("max(i++,j++) is %d\n", max(i++,j++));
// 	printf("j is %d\n", j);

// 	printf("square(2)   is %d\n", square(2));
// 	printf("square_1(2) is %d\n", square_1(2));
	
// 	printf("square(1+1)   is %d\n", square(1+1));
// 	printf("square_1(1+1) is %d\n", square_1(1+1));




/************************************************/
	// # opereator
	#define dprint(expr) printf(#expr " = %g\n", expr)

	dprint(5.0/2);
	printf("5.0/2" " = %g\n", 5.0/2);
// 	// equivalent to printf("x/y" " = %g\n", x/y);
// 	// And the two strings get concatenated

// 	// or this way

	// #define dprint1(expr) printf( "%s = %g\n",#expr, expr)
	// dprint1(5.0/2);
/************************************************/

	// ## operator
	#define concat(front, second) front ## second
	char *concat(name,1) = "Yeah";
	printf("%s\n", name1);

// 	return 0;
}