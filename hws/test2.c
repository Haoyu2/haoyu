/*
 * 
 *
 * project: test2
 * name: 
 * user??
 * date: 
 * file: test2.c
 * notes:  Complete the code stub for test2
 */



// Question 1: Compute vector addition (20 Points)

void q1(){
    int A[8] = { 1, 1, 1, 1, 1, 1, 1, 1};
    int B[8] = { 2, 2, 2, 2, 2, 2, 2, 2};
    
    int C[8];

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

	printf("a1:         \n" );
	printf("a2:         \n" );
	printf("a3:         \n");
	printf("a4:         \n");

	//Write a pointer p which can point to hte function getMax
	// [?] = getMax;

}







// Question 3: Variadic function (20 Points)

typedef enum {ZERO_D,ONE_D,TWO_D} DIMENSION;

void *q3(DIMENSION dim, ...) {
  
	
}





// Question 4: Variadic function (20 Points)

typedef struct { int x,y; } Point;

int q4(Point *p1, Point *p2, Point *p3) {
  
	
}




// Question 5: Encription (20 Points)



char q5(char ch) {

	
}




// Question 6: Valid Curly Parenthesis (20 Points)


int q6(char *s){

}




