/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>
#include <stdint.h>


typedef struct {
    uint8_t is_keyword;
    uint8_t is_extern;
    uint8_t is_static;
} Flags;


typedef struct {
    uint8_t is_keyword : 1;
    uint8_t is_extern  : 1;
    uint8_t is_static  : 1;
} Flags_b;

int main(int argc, char *argv[])
{	
	printf("%ld\n", sizeof(Flags));
	printf("%ld\n", sizeof(Flags_b));



	Flags f = {1,1,1};
	Flags_b	f_b = {1,1,1};

	if (f_b.is_static == f.is_static && f.is_static == 1)
		printf("All right\n");




}