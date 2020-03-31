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


int main(int agrc, char *argv[]){

	int (*operation)(int,int) = &addition;

	int (*operation1[])(int,int) = {&addition,&subtruct,&multi};


	int a=2,b=1;
	for (int i=0;i<3;i++)
		printf("%d and %d on operation %d : %d\n",a,b, i,operation1[i](a,b));


}

