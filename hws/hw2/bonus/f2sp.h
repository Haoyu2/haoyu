#ifndef F2SP_H
#define F2SP_H
/* Print out a char array of 
 * single-precision foramt of float
 */
void print_sp(char s[]);

/* Read bits into a char array 
*  from memory of a 32-bit data type
*/
void bin_char(float f, char s[]);



/* Convert floats into binary char array
*  
*/
void f2sp(float f, char f_sp[]);

#endif