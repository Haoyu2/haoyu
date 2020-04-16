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


void qsort(void *base, size_t n, size_t size,int (*cmp)(const void *, const void *));

int cmp_id(const void *s1, const void *s2){
	return  ((Student*) s1)->id - ((Student*) s2)->id;
}

// strcmp(s1,s2);
int cmp_name(const void *s1, const void *s2){

	// Typecast the void pointser to Student structure pointer
	//  (Student *) s1;  s1->name, 

	// strcmp(s1->name + 2, s2->name + 2);

	return strcmp(((Student*) s1)->name, ((Student*) s2)->name);
}


int cmp_name_2(const void *s1, const void *s2){
	return strcmp(((Student*) s1)->name+5, ((Student*) s2)->name+5);
}

int main(int argc, char *argv[]){


// This is wrong, since the first line is definition. 
// After that is structure re-assign and it is incorrect way to change a 
// a structure. The only is to change every element.
	// Student students[5];
	// printf("%d\n", students[0].id);
	// // students[0] = {4,"John Doe"};// this is a wrong way of updating a struct variable
	// // students[1] = {3,"John Ham"};
	// // students[2] = {2,"Mike Ros"};
	// // students[3] = {1,"Tuck Bee"};
	// // students[4] = {5,"Havy Abe"};

	// students[0].id = 4; students[0].name = "John Doe"; //This is correct
	// printf("%d\n", students[0].id);

	Student students[5] = {
			{4,"John 5Doe"},	
			{3,"John 3Ham"},
			{2,"Mike 4Ros"},
			{1,"Tuck 1Bee"},
			{5,"Havy 2Abe"}
	};

	qsort(students, 5, sizeof(Student), cmp_id);

	for (int i=0;i<5;i++)
		printf("%d\t%s\n",students[i].id,students[i].name);



	printf("-------------------------\n" );
	qsort(students, 5, sizeof(Student), cmp_name);

	for (int i=0;i<5;i++)
		printf("%d\t%s\n",students[i].id,students[i].name);
	

	printf("-------------------------\n" );
	qsort(students, 5, sizeof(Student), cmp_name_2);

	for (int i=0;i<5;i++)
		printf("%d\t%s\n",students[i].id,students[i].name);




	return 0;
}

