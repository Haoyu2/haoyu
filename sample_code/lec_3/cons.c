#include <stdio.h>

int main(void){
    printf("%5d\n", 0);
    printf("%5d\n", 125456789);
    printf("%5d\n", -10);
    printf("%5d\n", -125456789);

    printf("%-5d\n", 0);
    printf("%-5d\n", 125456789);
    printf("%-5d\n", -10);
    printf("%-5d\n", -125456789);

    printf("%05d\n", 0);
    printf("%05d\n", 125456789);
    printf("%05d\n", -10);
    printf("%05d\n", -125456789);
}
