/* 
* Author : Haoyu Wang
* Description:
*		external static
*/
#include <stdio.h>


static float pi = 3.1415926;
float *p_pi = &pi;

float get_pi(){
	return pi;
}

float * get_pi_ref(){
	return &pi;
}

