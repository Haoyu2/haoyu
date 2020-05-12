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




//10 points
// 2's complement

What is the memory layout for a short integer -2 in C, what mechanism is used?



// 10
// complicated pointer declaration

function pointer declaration  [datatype] (*[name])([arguments])
write the postfix formart in full expandsion. For nested function use curly brackets
int (*nice)(int, int (*)(int))

nice * (int, int (*)(int) {* (int) int} ) int
or
nice * (int, int (*)(int) ) int
{* (int) int} 

// commandline argument 

./driver -s 2020 -n 32
int main(int argc, char *argv[])

argc = ? 5
argv[0]  points to "./driver"
argv[0][0]  '.'
argv[1][0]

// 10
// bitwise operation

binary format
01 & 10  00
01 | 10  11
01 ~ 10  11

01 >> 1 (right shift for a signed is implementation-based)  00
01 << 1   10

// 10
// writing macros with argument

write a macro to calculate the square of a integer x correctly.

#define SQR(x) (x)*(x)

write a macro to calculate the area of a circul with a radius of double r  correctly.

#define AREA(x) 3.14*(r)*(r)


// (10-20) (Important)
// writing a comparator for sorting an array of structures.

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



//(10-20)
// char array manipulation

void rotate(char *s, int a);
void trim(char *s); (get rid of the white space int the beginning and end)
void flipcase(char *s);




// (10-20)
// two or multi-dimensional array (the column sum) (it may in the same question with structures)
// free() 
double **mat;



// (10-20)
// pointer and arrays

see the example in qsort

// (10-20)
// self-referential list. (append)

see linkedlist


// (10-20)
// Union Endianess


how to determine the Endianess on a machine


int i=1;
if ((char) i) 
printf("Little Endianess\n");




