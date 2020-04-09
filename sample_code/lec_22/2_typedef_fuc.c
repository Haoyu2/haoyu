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

typedef enum {X_AXIS, Y_AXIS} Axis;

typedef struct {int x,y;} Point;
//First two arguments are points to be compared, 
//the third  argument is an indicator for compare which member of point.
typedef int (*ComPoint)(void*,void*, Axis);
// the ComPoint becames a new function pointer data type

void *getMax(void *s[], int n, ComPoint com, Axis axis){
	void *m = s[0];
	for (int i=1;i<n;i++) if (com(s[i],m, axis) > 0)  m=s[i];
	return m;
}


int point_com(Point *x1, Point *x2, Axis axis){
	// if axis == 0 y_axis will be compared 
	return axis ?  (x1->y > x2->y) : (x1->x > x2->x);
}

typedef int (*ArithOP)(int,int);

int add(int a, int b){return a+b;}

int main(int argc, char * argv[]){  



	int (*myadd)(int,int)  = add;
	ArithOP myadd_agian =  add;
	printf("%d\n", myadd(1,1)); 
	printf("%d\n", myadd_agian(1,1)); 


	// Without the parenthesis, it will throw out incompatible pointer error.
	// because there is void * type cast
	ComPoint compoint = (ComPoint)  point_com;
	// ComPoint compoint =  point_com;



	Point x[10], *px[10];

	for (int i=0;i<10;i++){
		x[i].x = 0 + i;
		x[i].y = 9 - i;
		px[i]  = x + i;
		printf("x[%d] %d\t%d\n",i,x[i].x,x[i].y );
	} 


	Point *max = getMax((void*) px,10, (ComPoint) point_com, X_AXIS);
	Point *max_y = getMax((void*) px,10, (ComPoint) point_com, Y_AXIS);

	printf("%d\t%d\n",max->x,max->y );
	printf("%d\t%d\n",max_y->x,max_y->y);



  return 0;
}
