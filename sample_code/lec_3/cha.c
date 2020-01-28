#include <stdio.h>
int main(void)
{
    printf("%c\n", 'x');
    printf("%c\n", '\t');
    printf("%c\n", '\n');
    printf("the size of a character is :%d Bytes\n", sizeof('x'));
    printf("the size of a character is :%d Bytes\n", sizeof('\n'));

    char i = 'c';
    printf("%c\n",i );
    printf("%d\n", i);
    if (i)
        printf("ok!\n"); /* Don not forget the () enclosing i */
    if (i == 'c')
        printf("Nice!\n" );
    if (i == 99)
        printf("Nice too!\n");
    return 0;

}
