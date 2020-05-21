/* 
* Author : Haoyu Wang
* Description:
*		external static
*/
#include <stdio.h>


extern float pi;
extern float *p_pi;

float * get_pi_ref();
float get_pi();

int main(int argc, char *argv[])
{
	// is this working ?
	printf("'%-10.3f'\n", pi);

	printf("%f\n", get_pi() );
	printf("%d\n", p_pi == get_pi_ref() );


	return 0;
}