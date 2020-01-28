/* 
* Author : Haoyu Wang
* Description:
*
*
*/
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floatinq-point, for loop version */

#include <stdio.h>
int main(int argc, char *argv[])
{
	int fahr;
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	return 0;
}