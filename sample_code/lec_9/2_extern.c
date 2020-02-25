/* 
* Author : Haoyu Wang
* Description:
*
* local variable if not defined locally then goes to the external variable
*
*/
#include <stdio.h>

float pi;

float area(float radius);



int main(int argc, char *argv[])
{
	

	// Can we print pi here ?
	printf("'%-10.3f'\n", pi);

	area(1);

	printf("'%-10.3f'\n", pi);

	// can we redefine pi here ?
	float pi;
	pi = 3.1;
	printf("'%-10.3f'\n", pi);	

	
	return 0;
}

float area(float radius){
	// Can we redefine radius here ?
	// float radius;
	float pi = 3.1415926;
	return radius*radius*pi;
}