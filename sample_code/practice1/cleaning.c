/* 
* Author : Haoyu Wang
* Description:
* 
*   This code reads each line and substitute every 
*   non-letter char, expect '\n', into a space char.
*   And delete extra space char and all the trailing char.   
* 
*
*
*/



#include<stdio.h>

int main(void){

    char c, line[1000];
    int i=0, num=0, flag=0;

    while((c=getchar())!=EOF){

        if ((c>='a' && c<='z') || (c>='A' && c<='Z') ){
            flag = 1; 
            line[i++] = c;
        }else if (flag==1 && c!='\n'){
            flag = 0;
            line[i++] = ' ';
        }else if (c == '\n'){
            if (flag == 0) i--;
            if (i>0){
                line[i++] = '\n';
                line[i] = '\0';
                printf("%d: %s",num, line);
            }
            flag = i = 0;
            num++;
        }

    }

    if (flag == 0) i--;
    if (i>0){
        line[i++] = '\n';
        line[i] = '\0';
        printf("%d: %s",num, line);
        i = 0;
    }


    return 0;
}



