/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>
#include <float.h>
#include <math.h>

int main(void)
{
    float epsilon_f = 1.0/pow(10.0,(double) FLT_DIG);
    double epsilon_d = 1.0/pow(10.0,(double) DBL_DIG);

    printf("epsilon_f: %1.56f\n", epsilon_f);
    printf("epsilon_d: %1.56f\n", epsilon_d);
    float n=0.1;
    double a = 0.1;

    if ( fabs(n -0.1) < epsilon_f) 
        printf("it's all right\n");
    else 
        printf("Wierd\n");

    if (fabs(a + a + a + a + a + a + a + a + a + a -1.0)<epsilon_d) 
        printf("10 * 0.1 is indeed 1.0. \n");
    else 
        printf("Wierd, This is not guaranteed in the general case.\n");

    
  return 0;
}