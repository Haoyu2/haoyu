/*
 * 
 *
 * project: hw5
 * name: 
 * user??
 * date: 
 * file: hw5.c
 * notes:
 */

#include "hw5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 30 points
int intff(const char *s, int *nums){

	FILE *f = fopen(s,"r");
	if (NULL==f){
		fprintf(stderr, "intff: can't open %s\n", s);
		exit(1);
	}

	char line[MAX_C];

	fgets(line,MAX_C,f);
	printf("%s\n", line);
	int i=0, j=0, k=0;
	for (i=0;line[i]!=0;i++){
		if (line[i] == ',' ){
			line[i] = 0;
			nums[j++] = atoi(line + k);
			k = i + 1;
		}
	}
	if (k != i)
		nums[j++] = atoi(line + k);

	fclose(f);

	return j;
}


// 30 points
int isPalindrome(int x){
	int i=0, j[30], k=0;


	while (j[i]=x % 10){
		x = x / 10; i++;
	}
	i--;
	while (k < i)
		if (j[k++] != j[i--]) 
			return 0;
	return 1;
}



// 40 points

void tail(const char *s, int n){

	FILE *f = fopen(s,"r");
	if (NULL==f){
		fprintf(stderr, "intff: can't open %s\n", s);
		exit(1);
	}

	printf("\n%s: last %d lines are :\n",s,n );

	int i,j=0;
	char *lines[n];
    for (i=0;i<n;i++) lines[i] = (char*) malloc(MAX_C);
    while (fgets(lines[i%n], MAX_C, f)) i++;
    while (j++ < n)	printf("%s", lines[i++%n]);
    for (i=0;i<n;i++) free(lines[i]);
    fclose(f);
}



// 30 points
void strip(char *s){

	int l = strlen(s) - 1;
	int i=0,j=0;
	while (s[i]==' ' || s[i]=='\t'|| s[i]=='\n') i++;
	
	if (s[i]==0){
		s[0] = 0;return ;
	}
	while (s[l]==' ' || s[l]=='\t' || s[l]=='\n') l--;
	int k = l-i;


	for (j=0; j<k+1;j++,i++)
		s[j] = s[i];
	s[j] = 0; 
}


// 30 points
int linesff(const char *s, char **lines){

	FILE *f = fopen(s,"r");
	if (NULL==f){
		fprintf(stderr, "intff: can't open %s\n", s);
		exit(1);
	}

	int i=0;
	while (fgets(lines[i],MAX_C,f) != NULL) {
		strip(lines[i]);
		if (lines[i][0]==0) continue;
		i++;
	}
	fclose(f);
	return i;
}





// 30 points
int wordsfs(const char *s, char **words){

	int i=0, j=0, m=0,lw;
	for (;s[i]!=0;i++){
		if (s[i] ==','){			
			lw = i-m;
			memcpy(words[j], s + m, lw);
			words[j][lw+1] = 0;
			m =  i + 1;
			strip(words[j]);
			j++;
		}
	}

	if (m < i){
		lw = i-m;
		memcpy(words[j], s+m, lw);
		words[j][lw+1] = 0;
		strip(words[j]);
		j++;
	}

	return	j;

}


// 30 points
char * longestCommonPrefix(char ** words, int wordsSize){

	char *s = malloc(MAX_C), flag=0;
	int k = 0; 
	for (int i=0; words[0][i]!=0;i++){

		for (int j=1; j< wordsSize;j++)
			if (words[j][i] != words[0][i]){ 
				flag=1;
				break;
			}
		if (flag) break;else
			s[k++] = words[0][i];
	}

	s[k] = 0;

	return s;

}


