/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>



int main(int argc, char *argv[])
{
	//  // this is illegal
	// int *ip;
	// *ip = 1;

	int i, *ip = &i;
	*ip = 1;



	return 0;
}