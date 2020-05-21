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


int area(Point x1, Point x2){
	return abs((x2.y-x1.y)*(x2.x-x1.x));
}


int main(int argc, char * argv[]){   

	Point x1 = {0 ,0 },
		  x2 = {10,10};
	printf("%d\n", area(x1,x2));

	// structure pointer
	Point *p = &x1;
	printf("%d\n", p->y);	
	printf("%d\n", (*p).y);

	// printf("%d\n", *p.y);






  return 0;
}
