#include <stdio.h>
int main(){
    struct bs{
        unsigned m: 6;
        unsigned n: 12;
        unsigned p: 4;
    };
    printf("%ld\n", sizeof(struct bs));
    return 0;
}