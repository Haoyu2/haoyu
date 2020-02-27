/* 
* Author : Haoyu Wang
* Description:
*
*
*/



#include<stdio.h>
#define MAXLINE 100
#define LIMIT_LINE 80




int main(void){

    printf("%x\n", -5);

    unsigned char beagle = 0xCC;
    unsigned char pug = 0x44;
    char puggle = beagle / 6 >= 32 || pug - 25 % 10 >> 4;
    printf("beagle = %u, pug = %u\n", beagle, pug);
    if (puggle)printf("result = puggle\n");


    return 0;
}


