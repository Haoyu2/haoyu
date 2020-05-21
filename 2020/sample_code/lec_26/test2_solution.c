/*
 * 
 *
 * project: test2
 * name: 
 * user??
 * date: 
 * file: test2.c
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>




// Question 1: Compute vector addition (20 Points)

void q1(){
    int A[8] = { 1, 1, 1, 1, 1, 1, 1, 1};
    int B[8] = { 2, 2, 2, 2, 2, 2, 2, 2};
    
    int C[8];

    for (int i=0;i<8;i++)
    	C[i] = A[i] + B[i];

}




// Question 2: Complicated declaration (25 Points)


void *getMax(void *s[], int n, int (*com)(void*,void*)){
	void *m = s[0];
	for (int i=1;i<n;i++) if (com(s[i],m) > 0)  m=s[i];
	return m;
}



void q2(){

	float *a1[5];
	float (*a2)[5];
	float (*a3)(int,int);
	float *(*(*a4[5])(int, int (*)(int)))(int);

	// a4p : *a4[5](int, int (*)(int))
	// float *(*a4p)(int)

	printf("a1: a1 [5] * float   				\n" );
	printf("a2: a2 * [5] float      			\n" );
	printf("a3: a3 * (int, int) float        	\n");
	printf("a4: a4 [5] * (int, int(*)(int)) * (int) * float        \n");

	//Write a pointer p which can point to hte function getMax
	void* (*p)(void **, int, int (*)(void *, void*)) = getMax;

}







// Question 3: Variadic function (20 Points)

typedef enum {ZERO_D,ONE_D,TWO_D} DIMENSION;

void *q3(DIMENSION dim, ...) {

	int m, n;
	va_list ap; va_start(ap,dim);


	//if int *arr return (void*) arr;
	//if int **arr return (void*) arr;

	//

	void *arr;

	switch (dim){
		
		case ZERO_D:

			arr = malloc(sizeof(int));
			((int*) arr)[0] = 1;
			return (void *) arr;


		case ONE_D:
			m = va_arg(ap, int);
			arr = malloc(sizeof(int)*m);
			for (int i=0;i<m;i++) 
				((int*) arr)[i] = 1;
			return (void *) arr;

		case TWO_D:
			m = va_arg(ap, int);
			n = va_arg(ap, int);
			arr = malloc(sizeof(int*)*m);

			for (int i=0;i<m;i++) {
				((int**) arr)[i] = malloc(sizeof(int)*n);
				for (int j=0;j<n;j++)
					((int**) arr)[i][j] = 1;
			}
			return arr;
	}	
	
}





// Question 4: Sturture (20 Points)

typedef struct { int x,y; } Point;

int q4(Point *p1, Point *p2, Point *p3) {

	int x_min = p1->x < p2->x ? p1->x : p2->x;
	int x_max = p1->x > p2->x ? p1->x : p2->x;

	int y_min = p1->y < p2->y ? p1->y : p2->y;
	int y_max = p1->y > p2->y ? p1->y : p2->y;


	if ((p3->x > x_min && p3->x < x_max)  && 
		 (p3->y > y_min && p3->y < y_max))
		return 1;
	if ((p3->x < x_min) || (p3->y > y_max) || 
		(p3->x > x_max) || (p3->y < y_min) )
		return -1;
	return 0;
	
}




// Question 5: Encription (20 Points)



char q5(char ch) {

	return (ch>'z' || ch<'a') ? ch :
			((3*(ch-'a') + 3) % 26) + 'a'; 
	
}


// Question 6: Valid Curly Parenthesis Pairs (20 Points)


int q6(char *s){


//"}{{"
	int i=0,j=0;
	while (s[i]){
		if (s[i]=='{') j++;
		if (s[i]=='}')
			if (0==j--) return -1;		
		i++;
	}

	if (j>0) return -1;
	return 1;
}


void test_q3(void);
void test_q4(void);
void test_q5(void);
void test_q6(void);


int main(void){



	test_q3();
	test_q4();
	test_q5();
	test_q6();





}




void test_q3(void){
	int m=5,n=5;

	int* arr = (int*) q3(0);
	printf("%d", *arr);

	printf("\n-----\n");

	int* arr1 = (int*) q3(1,m);
	for(int i=0;i<m;i++)
		printf("%d\t",arr1[i]);
	printf("\n-----\n");


	int** arr2 = (int**) q3(2,m,n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			printf("%d\t", arr2[i][j]);
		printf("\n");
	}

}


void test_q4(void){

	Point p1 = {0,0}, p2 = {10,10};

	Point ps[9] ={
				{-1, 5},
				{11, 5},
				{5, 11},
				{5, -1},

				{ 0,5},
				{10,5},
				{5,10},
				{5, 0},

				{5,5}
	};


	for(int i=0;i<9;i++)
		printf("%d\t", q4(&p1,&p2,ps+i));

	printf("\n");
}


void test_q5(void){
	printf("%c\n", q5('k'));
}


void test_q6(void){
	char s[] = "{{}}{{";
	printf("%d\n", q6(s));

	char s1[] = "}{";
	printf("%d\n", q6(s1));

	char s2[] = "{{}}";
	printf("%d\n", q6(s2));

}