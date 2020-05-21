#ifndef MINMAXSTACK_H
#define MINMAXSTACK_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>


#ifndef TEST_NULL
#define TEST_NULL(p,s) \
		if (p == NULL){ \
			printf("Pointer %s is NULL\n",s); \
			exit(1); }
#endif


typedef struct 
{
	int *stack,top,len,min,max;
} Stack;

void printStack(Stack *stack);
Stack* newStack(int len);
int* pop(Stack *stack);
void push(Stack *stack, int num);
Stack* newStackFA(int a[], int index, int len);

int setMin(Stack *stack);
int setMax(Stack *stack);


#endif