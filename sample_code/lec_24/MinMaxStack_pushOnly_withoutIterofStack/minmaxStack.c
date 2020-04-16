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

#include "minmaxStack.h"


Stack* newStack(int len){
	if (len <=0 ){
		printf("Length of stack should bigger than 0\n");
		exit(1);
	}

	Stack *stack = malloc(sizeof(*stack));
	TEST_NULL(stack,"newStack:stack")
	stack->len = len;
	stack->top = -1;
	stack->stack = malloc(len*sizeof(int));
	TEST_NULL(stack->stack,"newStack:stack.stack")
	return stack;
}




// Here to return a pointer so that we can check
// if the stack is empty or not
// Otherwise no way to check
int *pop(Stack *stack){
	if (stack->top >= 0) {
		stack->top--;
		setMin(stack);
		setMax(stack);

		return stack->stack + stack->top + 1;
	}
	return NULL;
}

void push(Stack *stack, int num){

	++stack->top;
	if (stack->top >= stack->len) {
		stack->len *= 2;
		int *p = realloc(stack->stack, stack->len*sizeof(int));
		TEST_NULL(p,"push:realloc")
		free(stack->stack);
		stack->stack = p;
	}

	stack->stack[stack->top] = num;

	if (stack->top == 0) {
		stack->min = num;
		stack->max = num;
	}else{
		if (stack->min > num) stack->min =num;
		else if (stack->max < num)
			stack->max = num;
	}
}



Stack* newStackFA(int a[], int index, int len){

	Stack *stack = newStack(len);

	for (int i=0;i<index;i++) push(stack,a[i]);
	return stack;
}


int setMin(Stack *stack){
	int min=stack->stack[0];
	for (int i=0;i<stack->top+1;i++){
		if (stack->stack[i] < min)
			min = stack->stack[i];
	}
	return stack->min = min;
}

int setMax(Stack *stack){
	int max=stack->stack[0];
	for (int i=0;i<stack->top+1;i++){
		if (stack->stack[i] > max)
			max = stack->stack[i];
	}
	return stack->max = max;
}

void printStack(Stack *stack){
	for (int i=0;i<stack->top+1;i++){
		printf("%d\t", stack->stack[i]);
	}
	printf("\n");
}
