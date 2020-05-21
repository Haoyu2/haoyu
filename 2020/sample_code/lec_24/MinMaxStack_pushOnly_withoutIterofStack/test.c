/*
 * 
 *
 * project: hw4
 * name: 
 * user??
 * date: 
 * file: test.c
 * notes:
 */
#include <stdio.h>
#include "minmaxStack.h"


int main(int argc, char * argv[]){   

	int len = 5;
	Stack *stack = newStack(len);
	printf("stack's len is %d\n", stack->len);

	printf("\nAfter only Push---------------\n");


	for (int i=0;i<6;i++) push(stack,i);
	printf("stack's len is %d\n", stack->len);

	printf("Stack's top  is %d\n", stack->top);
	printf("Stack's max after push is %d\n", stack->max);
	printf("Stack's min after push is %d\n", stack->min);


	printf("\nPop and Push---------------\n");

	pop(stack);
	push(stack,10);
	push(stack,-1);
	push(stack,5);
	pop(stack);


	printStack(stack);
	printf("Stack's top  is %d\n", stack->top);
	printf("Stack's max  is %d\n", stack->max);
	printf("Stack's min  is %d\n", stack->min);

	//or if you want or robust getMin_Stack, getMax_Stack, try to write your own
	// Because the stack may be empty





  return 0;
}
