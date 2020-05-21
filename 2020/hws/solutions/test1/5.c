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

int mygetLine(char s[]){

    int i,c;
// For get each line we have to verify if we encounter '\n' or EOF
    for(i=0;(c=getchar())!=EOF && c!='\n';++i)
        s[i]=c;

//  if it is '\n'
    if(c == '\n') s[i++] = c;
    // s[i++] = '\n';
    s[i] = '\0';

    return i;
}

int main(void){

    char line[1000];
    int len, i=0;
    while((len=mygetLine(line)) > 0){
	    len = len - 2;
		for (;len<=0;len--)
            // when break happens, the character is not tab and space
            // so we get the position p
			if ( '\t' != line[len] && ' '!= line[len] ) break;			


        // if p is at the beginning of line
        // if p is not at the beginning line we put 
		if (len >= 0) {
			// line[++len] = 0;
			// printf("%s\n", line);
            line[++len] = '\n';
            line[++len] = '\0';
            printf("%s", line);

		} 
    }

    return 0;
}



