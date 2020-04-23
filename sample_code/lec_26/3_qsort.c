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


typedef struct 
{
	int id;
	char *name;	
} Student;

// the size is the poiner length
void qsort(void *base, size_t n, size_t size,int (*cmp)(const void *, const void *));

int cmp_stu(const void * s1, const void * s2){

	return  ((Student*) s1)->id - ((Student*) s2)->id;
}

// For stu1 the base is stu1, stu1 is Student** 
int cmp_stu1(const void * s1, const void * s2){

	return  (*(Student**) s1)->id - (*(Student**) s2)->id;
}



int main(int argc, char *argv[]){




	Student students[5] = {
			{4,"John 5Doe"},	
			{3,"John 3Ham"},
			{2,"Mike 4Ros"},
			{1,"Tuck 1Bee"},
			{5,"Havy 2Abe"}
	};  // Lies in the stack

	// If you want to return a data holder in a local funcion 
	// you should use heap memory or static stack memory.
	Student *stu = malloc(sizeof(Student)*5);
	memcpy(stu,students,sizeof(Student)*5);

	for (int i=0;i<5;i++)
		printf("%d\t%s\n",stu[i].id,stu[i].name);

	printf("---------\n");
	Student **stu1 = malloc(sizeof(Student*) * 5);// stu1 is used for storing 5 student pointers
	for (int i=0;i<5;i++){

		// stu1[i]  equalent *(stu1 + i)
		stu1[i] = malloc(sizeof(Student));
		memcpy(stu1[i],students + i , sizeof(Student));
		printf("%d\t%s\n",stu1[i]->id,stu1[i]->name);

	}

	printf("---------\n");

	qsort(stu,5,sizeof(Student),cmp_stu);

	for (int i=0;i<5;i++)
			printf("%d\t%s\n",stu[i].id,stu[i].name);

	printf("---------\n");

	qsort(stu1,5,sizeof(Student*),cmp_stu1);

	for (int i=0;i<5;i++)
		printf("%d\t%s\n",stu1[i]->id,stu1[i]->name);


	return 0;
}

