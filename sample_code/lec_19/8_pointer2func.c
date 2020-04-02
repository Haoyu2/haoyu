/*
 * 
 *
 * project: cs240.h
 * name: 
 * user??
 * date: 
 * file: test.c
 * notes:
 */

#include <stdio.h>

int addition(int a,int b){return a+b;}
int subtruct(int a, int b){return a-b;}
int multi(int a, int b){return a*b;}

void print(int a){printf("a");}


int main(int agrc, char *argv[]){

	int (*operation)(int,int) = &addition;

	printf("%d\n", operation(1,2));
	printf("%d\n", addition(1,2));

	// operation1 is an array of function pointers of operation
	int (*operation1[])(int,int) = {&addition,&subtruct,&multi};

	printf("%d\n",operation1[2](2,3) );


	// int a=2,b=1;
	// for (int i=0;i<3;i++)
	// 	printf("%d and %d on operation %d : %d\n",a,b, i,operation1[i](a,b));


}

