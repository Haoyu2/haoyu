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


#include "ArrayList.h"
#include "ArrayList_Test.h"
#include <assert.h>



int a[] = {1,2,-1}, len=5;
ArrayList *al;

int com_int(const void*a, const void*b){
	return *(int*)a - *(int*)b;
}




void newArrayList_test(void){
	printf("\nnewArrayList_test-----------\n");

	ArrayList *al_null = newArrayList(0, sizeof(int), com_int);

	assert(al_null==NULL);

	ArrayList *al = newArrayList(len, sizeof(int), com_int);
	al->info(al);
	assert(al->len==len);
	assert(al->end==-1);
	assert(al->min==NULL && al->max==NULL);
}




void appendArrayList_test(void){

	printf("\nappendArrayList_test---------\n");
	ArrayList *al = newArrayList(len, sizeof(int), com_int);
	al->append(al,a,sizeof(int));
	al->appends(al,a,sizeof(int),3);

	al->info(al);
	for (int i=0;i<al->end+1;i++)
		printf("%d\t", *(((int*) al->get(al,0)) + i));

}



void mix_test(void){

	al = newArrayList(len, sizeof(int), com_int);
	al->append(al,a,sizeof(int));
	al->appends(al,a,sizeof(int),3);
	al->get(al, 4);

	

	int x = 10;
	al->insert(al, 1, &x, sizeof(int));
	printf("\n\nEnding index is %d\n", al->end);
	for (int i=0;i<al->end+1;i++)
		printf("%d\t", *(((int*) al->get(al,0)) + i));	
	printf("min:%d\tmax:%d\n", *((int*)al->min),*((int*)al->max));


	al->remove(al, 1);
	printf("\n\nEnding index is %d\n", al->end);
	for (int i=0;i<al->end+1;i++)
		printf("%d\t", *(((int*) al->get(al,0)) + i));	
	printf("min:%d\tmax:%d\n", *((int*)al->min),*((int*)al->max));


	al->removes(al, 1, 2);
	printf("\n\nEnding index is %d\n", al->end);
	for (int i=0;i<al->end+1;i++)
		printf("%d\t", *(((int*) al->get(al,0)) + i));	
	printf("min:%d\tmax:%d\n", *((int*)al->min),*((int*)al->max));


	int aa=1,bb=3;
	if (al->in(al, &aa, sizeof(int)))
		printf("1 is in al\n");
	if (!al->in(al, &bb, sizeof(int)))
		printf("3 is not in al\n");


	ArrayList *al1 = al->copy(al);
	printf("\n\nEnding index is %d\n", al1->end);
	for (int i=0;i<al1->end+1;i++)
		printf("%d\t", *(((int*) al1->get(al,0)) + i));	
	printf("min:%d\tmax:%d\n", *((int*)al1->min),*((int*)al1->max));


	ArrayList *al3 = al->concat(al,al1);
	printf("\n\nEnding index is %d\n", al3->end);
	for (int i=0;i<al3->end+1;i++)
		printf("%d\t", *(((int*) al3->get(al,0)) + i));	
	printf("min:%d\tmax:%d\n", *((int*)al3->min),*((int*)al3->max));


}

