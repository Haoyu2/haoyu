/* 
* Author : Haoyu Wang
* Description:
*
*
*/



#include<stdio.h>
#define MAXLINE 100
#define LIMIT_LINE 70



int mygetLine(char line[]);

int main(void){

    int len;
    char line[1000];
    long num=0;

    while((len=mygetLine(line)) > 0){
        num++;
        if( len > LIMIT_LINE && len < MAXLINE + 1 )
        printf("%lu: %d: %s",num, len,line);
    }

    return 0;
}


int mygetLine(char s[]){
    
    int i,c;

    for(i=0;(c=getchar())!=EOF && c!='\n';++i)
        s[i]=c;

    if(c == '\n') s[i++] = c;
    s[i] = '\0';

    return i;
}

