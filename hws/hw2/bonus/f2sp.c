#include "f2sp.h"


/* print out a char array of single-precision foramt of float*/
void print_sp(char s[]){
	int i=0;
	while(s[i]){
		if(1==i || 9==i)
			printf("%c",' ' );
		printf("%c", s[i++]);
	}
	printf("\n");
}

/* Read bits into a char array 
*  from memory of a 32-bit data type
*/
void bin_char(float f, char s[]) 
{ 
	unsigned n = *((unsigned *) &f);
    unsigned i, j=0; 
    for (i = 1 << 31; i > 0; i = i / 2) {
        s[j++] = (n & i)?  '1' : '0';
    }
    s[j] = 0;
}


/* Convert floats into binary char array
*  Uncomment this function and finish it 

void f2sp(float f, char f_sp[]){

}

*/