/*
 * Author: Haoyu Wang
 * Notes:
 */


#include <stdio.h>

/* copy input to output */
int main(void)
{
	int c, cn, l_count[26];
	for (int i =0; i< 26; i++) 
		l_count[i] = 0;

	while ((c=getchar()) != EOF){
		if (c >= 'a' && c <= 'z'){
			l_count[c-97]++;
		}
		cn++;
	}
	printf("The number of chars is:%d\n", cn);
	for (int i =0; i< 26; i++) {
		printf("The number of the %c is:%d",i+97 , l_count[i]);
		for (int j=0; j<l_count[i];j++){
			printf("*");
		}
		printf("\n");
	}

;

}