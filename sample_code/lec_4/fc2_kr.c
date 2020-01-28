/* 
* Author : Haoyu Wang
* Description:
*
*
*/
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floatinq-point version */

#include <stdio.h>
int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0; /* lower limit of temperature table */
	upper = 300; /* upper limit */
	step = 20; 	/* step size */

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr-32) / 9;
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}