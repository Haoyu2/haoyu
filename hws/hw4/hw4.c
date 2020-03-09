/*
 * 
 *
 * project: hw4
 * name: 
 * user??
 * date: 
 * file: hw4.c
 * notes:
 */
#include <stdio.h>


// 25 points
// Write the function any(s1,s2) , which
// returns the first location in a string s1 where any
// character from the
// string s2 occurs, or -1 if s1 contains no characters
// from s2 . (The standard library function strpbrk does 
// the same job but  returns a pointer to the location.)

int any(char s1[], char s2[]){
	int j;
	for (int i = 0; s1[i] != '\0'; i++){
		for (j=0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				break;
		if (s2[j] != '\0')
			return i;
	}
	return -1;
}







// 25 points

// Write squeeze(s1,s2)
// that deletes each character in s1 that matches any character 
// in the string s2 .

void squeeze(char s1[], char s2[]){
	int i, j, k;

	for (i=j=0; s1[i] != '\0'; i++){
		for (k=0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k]) 
				break;
		if (s2[k] == '\0')
			s1[j++] = s1[i];
		k = 0;
	}
	s1[j] = '\0';
}





// 30 points

// Write a function rightrot(x,n) that returns the 
// value of the integer x rotated to the right by n positions.


unsigned rightrot(unsigned x, int n){
	int l = (sizeof(x)*8 );
	n = n % l;
	if (n == 0) return x;
	unsigned y = (x & ~(~0 << n)) <<(l -n);

	x >>= n;
	return y | x;
}


// 30 points

// Write a function invert(x,p,n) that returns x with 
// the n bits that begin at position p inverted (i.e., 1 changed
// into 0 and vice versa), leaving the others unchanged.

//  XOR operator ^:  x ^  0  keeps x intact
// 				  :  x ^ ~0  equivalent to ~x  filps all bits of x

unsigned invert(unsigned x, int p, int n){
	unsigned mask_x = ~(~0 << n) << (p+1-n);
	return x ^ mask_x;

}


// 30 points

// Write a program to remove all comments from a proper C program.
// Don't forget to handle quoted strings and it's escape character properly. 

void echo_quotes(char c)
{
    char d;
    putchar(c);
    
    while((d=getchar())!=c && d!=EOF)
    {
        putchar(d);
        
        if(d = '\\')
            putchar(getchar());
    }
    putchar(d);
}

void remove_comment()
{
    int c,d;
     
    c = getchar();
    d = getchar();

    while(c!='*' || d !='/')
    {
        c = d;
        d = getchar();
    }
}




void remove_comments(){

   	char c,d;
    while ((c=getchar())!=EOF){
    	if (c=='"') echo_quotes(c);
 
    	else if (c == '/'){
    		
    		if ((d=getchar())=='*') remove_comment();
    		else if( d == '/'){
		            putchar(c);
		            remove_comments(d);
		        }
		        else{
		            putchar(c);
		            putchar(d);
		        } 

    	}else putchar(c);
    }


}