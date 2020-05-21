#include <stdio.h>
#include "cal.h"
#include "str.h"


int main(void){
    char s[] = "1234";
    reverse(s);
    printf("%s\n", s);
    printf("%d\n", add(1,2));
}