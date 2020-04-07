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



//http://en.cppreference.com/w/c/variadic
// The named arguments must contain the number and data type of
// all the unamed arguments.

// Unspecified behavior occurs if the type is incorrect or go to 
// next unnamed variable argument non-existing.


#include <stdio.h>
#include <stdarg.h>


void simple_printf(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	
	while (*fmt != '\0') {
		if (*fmt == 'd') {
			int i = va_arg(args, int);
			printf("%d\n", i);
		}else if (*fmt == 'c') {
			int c = va_arg(args, int);
			printf("%c\n", c);
		}else if (*fmt == 'f') {
			double d = va_arg(args, double);
			printf("%f\n", d);
		}else if (*fmt == 's') {
			char *s = va_arg(args, char*);
			printf("%s\n", s);
		}

		++fmt;
	}
	va_end(args);
}


int main(void) {

	simple_printf("dcffs", 3, 'a', 1.999, 42.5,"hello world");
}