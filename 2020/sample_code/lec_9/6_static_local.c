/* 
* Author : Haoyu Wang
* Description:
*		external static
*/
#include <stdio.h>

void size(int a[]){
	printf("%lu\n", sizeof(a));
}


int counter(){
	int num = 0;
	// static int num;
	return num++;
}


int main(void){

	for (auto int i=0;i<5;i++) counter();
	printf("%d\n", counter());


	printf("%d\n",1.5 ? 0 : 1);
	printf("%d\n",0   ? 0 : 1);


	int c[5];
	printf("%lu\n", sizeof(c)/sizeof(int));
	sizeof(c);

}
