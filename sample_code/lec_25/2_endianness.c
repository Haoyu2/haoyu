/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>



int main(int argc, char *argv[])
{	
	printf("%ld\n", sizeof(short));

// A's hex is 0x41  B's hex is 0x42
	unsigned short i = 0x4142;  
// Question: there is a way to read each byte of i ?
//           if so, what would be the byte layout for i ?	

	// * (unsigned char*) &i: it takes pointers points to i
	// and typecast this pointer to a unsigned char pointer
	// then we can read the byte memory starting from &i;
	printf("%c\n",* (unsigned char*) &i );
	printf("%c\n",* ((unsigned char*) &i + 1));

	// why does this print out 'c'
	printf("%c\n",* (unsigned char*) &i + 1);
	// the '+' takes precedence of '*' operator





	// printf("%x\n",* (unsigned char*) &i );
	// printf("%x\n",* ((unsigned char*) &i + 1));


	// printf("%c\n",* ((unsigned char*) &i + 1));






	// unsigned endianness = 1; // 4 bytes
	// // 0x 00 00 00 01 big endinness     first byte: 0
	// // 0x 01 00 00 00 little endinness  first byte: 1
	// // * (unsigned char*) &endianness this will get the first byte

	// // &endinaness this will get the pointer of endinness
	// //

	// if (* (unsigned char*) &endianness)
	// 	printf(" Little endianness");
	// else
	// 	printf(" Big endianness\n");




}