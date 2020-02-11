/*
 *
 * project: hw2
 * name:
 * account: 
 * date: 
 * file: itox.c
 * notes:
 */

#include <stdio.h>
#include <string.h>
#include <math.h>


/* this function can print out an q_string s[]*/
void print(char s[], int q){

    printf(" %2d-string: ", q);
    for (int i=0;s[i]; i++){
        if (!((i)%4)&&i!=0) printf("|");
        printf("%c", s[i]);
    }
    printf("\n");
}



/* this function converts the integer num into a q_based string */
void num2q(int num, char num_q[], int q){ }

/* this function converts a q_based string into an integer */
int q2num(char num_q[], int q){ }


/* this function converts the float f into a binary string fb[]*/
void f2b(float f, char fb[]){}

/* this function converts the binary string fb[] into a float */
float b2f(char fb[]){ }



int main(void)
{
    char num_q[100];
    int  num = 2020;
    /* this loop converts num into string num_q and print out */  
    for (int i=2; i<16; i++){
        num2q(num, num_q, i);
        print(num_q, i);
        printf("       num: %d\n\n", q2num(num_q,i));
    }



    char fb[32];
    /* this loop converts f into binary string fb[] */      
    for (int i=-10;i<4;i++){
        float f = (float) pow(2,i); 
        f2b(f,fb);
        printf("pow(2,%2d)f: %g\n",i, f);
        print(fb,2);
        printf("pow(2,%2d)f: %g\n\n",i, b2f(fb));
    }

    float f = 127 + 0.1; 
    f2b(f,fb);
    printf("        f: %g\n", f);
    print(fb,2);
    printf("        f: %g\n\n", b2f(fb));
}
