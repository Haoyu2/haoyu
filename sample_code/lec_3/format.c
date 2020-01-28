#include <stdio.h>

int main(void)
{
    printf("%5d\n", 0);
    printf("%5d\n", 125456789);
    printf("%5d\n", -10);
    printf("%5d\n", -125456789);
    printf("--------------\n");
    printf("%-5d\n", 0);
    printf("%-5d\n", 125456789);
    printf("%-5d\n", -10);
    printf("%-5d\n", -125456789);
    return 0;
}
