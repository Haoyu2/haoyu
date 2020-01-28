#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("Total %d arguments passed in.\n ", argc);
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
    putchar(c);
    printf("\n%d\n", c);
    return 0;
}
