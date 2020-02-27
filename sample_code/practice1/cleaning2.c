/* 
* Author : Haoyu Wang
* Description:
* 
*   This code reads each line and substitute every 
*   non-letter char, expect '\n', into a space char.
*   And delete extra space char and the trailing char.   
* 
*
*
*/



#include<stdio.h>

int isLetter(char c){
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

int mygetLine(char s[]){

    int i,c;

    for(i=0;(c=getchar())!=EOF && c!='\n';++i)
        s[i]=c;

    if(c == '\n') s[i++] = c;
    s[i] = '\0';

    return i;
}

int cleanLine(char s[]){
    int i=0, j=0, flag=0;
    while (s[i]){

        if (isLetter(s[i])){
            s[j++] = s[i++];
            flag = 1;
        } else {
            if (flag==1) s[j++] = ' ';
            flag = 0;
            i++;
        }
    }
    s[j++] = '\n';
    s[j] = '\0';
    return j;
}



int main(void){

    char line[1000];
    int len, j, num=0;
    while((len=mygetLine(line)) > 0){
        num++;
        j = cleanLine(line);

        if (j>1)    
            printf("%d: %s", num, line);
    }

    return 0;
}



