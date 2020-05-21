/*
 * 
 *
 * project: hw4
 * name: 
 * user??
 * date: 
 * file: test.c
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef struct point
{
	int x;
	int y;	
} Point;

void *getMax(void *s[],  int n ,int (*com)(void*,void*, int flag), int flag){
	void *m = s[0];
	for (int i=1;i<n;i++) if (com(s[i],m, flag) > 0)  m=s[i];
	return m;
}


int point_com(Point *x1, Point *x2, int flag){
	return flag ? (x1->x > x2->x) : (x1->y > x2->y);
}


int main(int argc, char * argv[]){   

	Point x[10], *px[10];

	for (int i=0;i<10;i++){
		x[i].x = 0 + i;
		x[i].y = 9 - i;
		px[i]  = x + i;
		printf("x[%d] %d\t%d\n",i,x[i].x,x[i].y );
	} 


	Point *max = getMax((void *) px,10, (int (*)(void *, void *, int)) point_com, 1);
	printf("%d\t%d\n",max->x,max->y );


	




  return 0;
}
