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

double average(int count, ...) {
	va_list ap;
	int j;
	double sum = 0.0;
	va_start(ap, count);  //Last named argument, to get the address
	for (j = 0; j < count; j++) {
		sum += va_arg(ap, int); // Increments ap to the next argument
	}
	va_end(ap);
	return sum / count;
}

int main(int argc, char const *argv[]) {

	printf("%f\n", average(3, 1, 1, 1));

}