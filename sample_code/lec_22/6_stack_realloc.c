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
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>


#define TEST_NULL(p,s) \
		if (p == NULL){ \
			printf("Pointer %s is NULL\n",s); \
			exit(1); }
		


typedef struct 
{
	int *stack,top,max;
} Stack;


Stack* newStack(int max){
	if (max <=0 ){
		printf("Length of stack should bigger than 0\n");
		exit(1);
	}

	Stack *stack = malloc(sizeof(*stack));
	TEST_NULL(stack,"newStack:stack")
	stack->max = max;
	stack->top = -1;
	stack->stack = malloc(max*sizeof(int));
	TEST_NULL(stack->stack,"newStack:stack.stack")
	return stack;
}




// Here to return a pointer so that we can check
// if the stack is empty or not
// Otherwise no way to check
int *pop(Stack *stack){
	if (stack->top >= 0) return stack->stack + stack->top--;
	return NULL;
}

void push(Stack *stack, int num){

	++stack->top;
	if (stack->top >= stack->max) {
		stack->max *= 2;
		int *p = realloc(stack->stack, stack->max*sizeof(int));
		TEST_NULL(p,"push:realloc")
		free(stack->stack);
		stack->stack = p;
	}

	stack->stack[stack->top] = num;
}



Stack* newStackFA(int a[], int index, int max){

	Stack *stack = newStack(max);

	for (int i=0;i<index;i++) push(stack,a[i]);
	return stack;
}


int main(int argc, char * argv[]){   


	int max = 5;
	Stack *stack = newStack(max);
	printf("stack's max is %d\n", stack->max);


	for (int i=0;i<6;i++) push(stack,i);
	printf("stack's max is %d\n", stack->max);

	
	return 0;

}
