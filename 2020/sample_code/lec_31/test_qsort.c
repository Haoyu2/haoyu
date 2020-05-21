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

typedef struct 
{
	int i;
	char name[20];
} Student;

int com(const void *a,  const void *b){

	Student *stu1 = (Student *) a;
	Student *stu2 = (Student *) b;

	return stu1->i - stu2->i;
}

int com_pointer(const void *a,  const void *b){

	Student **stu1 = (Student **) a;
	Student **stu2 = (Student **) b;

	return stu1[0]->i - stu2[0]->i;
}

int main(int argc, char const *argv[])
{
	Student stu1[5] = {
			{4,"John 5Doe"},	
			{3,"John 3Ham"},
			{2,"Mike 4Ros"},
			{1,"Tuck 1Bee"},
			{5,"Havy 2Abe"}
	};

	Student *stu2[5] = {
		stu1,stu1+1,stu1+2,stu1+3,stu1+4
	}; 

	printf("%d\n", stu1[0].i);
	printf("%d\n", stu2[0]->i);
	qsort(stu1,5,sizeof(Student),com);
	qsort(stu2,5,sizeof(Student *),com_pointer);



	int i=1;
	if ((char) i) 
		printf("Little Endianess\n");
	return 0;
}