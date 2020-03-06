#include <string.h>

void reverse(char s[]){
    int i=0, j, temp;
    j = strlen(s) - 1;

    while (i < j)
    {   
        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }  
}