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


// This is struture if Stack
typedef struct 
{
	int *stack,top,max;
} Stack;


Stack newStack(int max){

	if (max <=0 ){
		printf("Length of stack should bigger than 0\n");
		exit(1);
	}
	int st[max];
	// this is stack memory created in local function
	//after the exit of newStack, its address is supposed
	//to be released
	Stack stack = {st,-1,max};
	return stack;
}





// Here to return a pointer so that we can check
// if the stack is empty or not
// Otherwise no way to check
int *pop(Stack stack){
	if (stack.top >= 0) return stack.stack + stack.top--;
	return NULL;
}

void push(Stack stack, int num){
	stack.stack[++stack.top] = num;
}


int main(int argc, char * argv[]){   

	int a[] = {1,2,3};

	Stack stack = newStack(10);
	push(stack,10);

	printf("%d\n", stack.stack[0]);
	// Why after push() stack.top isnot added by 1?
	printf("%d\n", stack.top);
	++stack.top;
	printf("%d\n", stack.top);

	// printf("%d\n", *pop(stack));

	return 0;

}
