
/* 
* Author : Haoyu Wang
* Description:


*	
*/
#include <stdio.h>



int main(int argc, char *argv[])
{
	for (int j=0;j<2;j++){
	for (int i=0;i<10;i++){

		if (i==1) break;
		printf("hey\n");

	}
	break;
}

	for (int i=0;i<10;i++){
		

		if (i>5) continue;
		printf("%d\t",i);

	}




	return 0;
}