/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>
#include <float.h>


int main(void)
{

    float n=0.1f;
    double a = 0.1;

    if (n == 0.1) 
        printf("it's all right\n");
    else 
        printf("Wierd\n");

    if (a + a + a + a + a + a + a + a + a + a == 1.0) 
        printf("10 * 0.1 is indeed 1.0. \n");
    else 
        printf("Wierd, This is not guaranteed in the general case.\n");

    double b = a + a + a + a + a + a + a + a + a + a;
    double c = a * 10;
    printf("\na: %1.56f\n", a);
    printf("b: %1.56f\n", b);
    printf("c: %1.56f\n", c);

  return 0;
}