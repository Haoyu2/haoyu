
/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>    

int add_two(int c[]){
    printf("function   c_value : %p\n", c);

    printf("function c_address : %p\n", &c);

}

int add(int a, int b){
    printf("function a : %p\n\n", &a);
    return a+b;
}

int main(void){
    int a=0,b=1, c[] = {1,2};
    printf("    main a : %p\n", &a);
    add(a,b);


    printf("      main c_value : %p\n", c);
    add_two(c);
    printf("    main c_address : %p\n", &c);


    return 0;
}