/*
 * 
 *
 * project: hw4
 * name: 
 * user??
 * date: 
 * file: test.c
 * notes:
 */


//https://en.wikipedia.org/wiki/Variadic_function
#include <stdio.h>
#include <stdarg.h>

// The named arguments must contain the number and data type of
// all the unamed arguments.

// Unspecified behavior occurs if the type is incorrect or go to 
// next unnamed variable argument non-existing.

double average(int count,  ...) {
	va_list ap;// declaration the pointer points to unamed arguments
	int j;
	double sum = 0.0;
	va_start(ap, count);  //The seconde argument has to be the last named argument, to get the address
	//after this the ap will points to the first unamed arugment
	for (j = 0; j < count; j++) {
		sum += va_arg(ap, int); // Increments ap to the next argument
		// Unspecified behavior occurs if the type is incorrect or go to 
		// next unnamed variable argument non-existing.
	}
	va_end(ap);
	return sum / count;
}

int two(){return 2;}

int main(int argc, char const *argv[]) {

	printf("%f\n", average(6, two(), 3, 4,5,6,7));

}