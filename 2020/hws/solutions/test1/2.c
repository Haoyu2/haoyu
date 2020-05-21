/* 
* Author : Haoyu Wang
* Description:
* 
*  
* 
*
*
*/


#include <stdio.h>
#include <string.h>


// Rotate 1 bit each time, then rotate n times
void rightrot(char s[],int n){

	int l= strlen(s);
	while ( n > 0){
		
		int i = l - 1; // The last element is at l-1
		char temp = s[l-1]; //  Get the last element
	
		for( ;i > 0 ;i--){
			s[i] = s[i - 1];
		}			// Right shift every element by 1 position 
		// Set the first element with the saved last element
		s[0] = temp;
		n--; // Goes on with this while loop
	}

}


void rightrot_1(char s[],int n){

	int l= strlen(s);
	char temp[n];

	memcpy(temp, s+l-n, n);
	memcpy(s+n,  s, l-n);
	memcpy(s, temp, n);


}


void main( void){
	
	char s[] = {"12345"};
	int n = 2; // Times to rotate
	printf("                 %s\n", s);
	rightrot(s, n);

	
	printf("Rotated %d times: %s\n",n, s);

	char s1[] = {"12345"};
	printf("                 %s\n", s1);
	rightrot(s1, n);
	printf("Rotated %d times: %s\n",n, s1);



}