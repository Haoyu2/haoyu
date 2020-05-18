/*
 * driver for Graham's scan
 *
 * project: hw7
 * name: 
 * user??
 * date: 
 * file: hw7.c
 */


#include "hw8.h"


void readStudent(Student *stu, char *s){

	
	stu->firstname = malloc(NAME_LEN);
	TEST_NULL(stu->firstname,"stu->firstname")

	stu->lastname = malloc(NAME_LEN);
	TEST_NULL(stu->lastname,"stu->lastname")
	
	stu->id = malloc(ID_LEN);
	TEST_NULL(stu->id,"stu->id")

	stu->grades = malloc(sizeof(float)*NUM_GRADES);
	TEST_NULL(stu->grades,"stu->grades")

	stu->len = 12; stu->weighted = 1;

	for (int i=0;s[i];i++)
		if (s[i] == ',') s[i] = ' ';

	sscanf(s, "%s %s %s %g %g %g %g %g %g %g %g %g %g %g",
		stu->firstname,stu->lastname,stu->id, stu->grades,
		stu->grades+1,stu->grades+2,stu->grades+3,stu->grades+4, 
		stu->grades+5,stu->grades+6,stu->grades+7,stu->grades+8,
		stu->grades+9,stu->grades+10);;


	for (int i=0;i<8;i++){
		stu->grades[11] += (stu->grades[i] / 20.0);
	}
	
	float max_two = stu->grades[8] > stu->grades[9] ? stu->grades[8]:stu->grades[9];
	float max_three = stu->grades[10] > max_two ? stu->grades[10]:max_two;
	float min = stu->grades[10] > max_two ? max_two:stu->grades[10];
	stu->grades[11] += (max_three * 35 / 100 + min * 25 / 100);

}



Class * readClass(char *s){

	FILE *f = fopen(s,"r");
	TEST_FILE(f,"read",s)

	Class * class = malloc(sizeof(Class));
	TEST_NULL(class, "class")

	class->len = 100;
	class->num = 0;

	class->stus = malloc(sizeof(Student)*MAX_STUDENTS);
	TEST_NULL(class->stus, "class->stu")


	char line[MAX_LINE];
	while ((fgets(line,MAX_LINE,f))!=NULL)
		readStudent(class->stus + class->num++,line);	

	fclose(f);

	return class;
}



int com_stu(const void *s1, const void* s2){

	float g1 = ((Student*) s1)->grades[INDEX_SORT];
	float g2 = ((Student*) s2)->grades[INDEX_SORT];

	if (g1 > g2) return 1;
	if (g1 == g2) return 0;
	return -1;
}


void sortClass(Class * class){
	qsort(class->stus,class->num,sizeof(Student),com_stu);

	FILE *f = fopen("sorted.csv", "w");
	
	Student *stu = NULL;
	for(int i=0;i<class->num;i++){
		stu = class->stus + i;
		printf("%s,%s,%s,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g\n",
			stu->firstname,stu->lastname,stu->id, stu->grades[0],
			stu->grades[1],stu->grades[2],stu->grades[3],stu->grades[4], 
			stu->grades[5],stu->grades[6],stu->grades[7],stu->grades[8],
			stu->grades[9],stu->grades[10],stu->grades[11]);

		fprintf(f,"%s,%s,%s,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g\n",
			stu->firstname,stu->lastname,stu->id, stu->grades[0],
			stu->grades[1],stu->grades[2],stu->grades[3],stu->grades[4], 
			stu->grades[5],stu->grades[6],stu->grades[7],stu->grades[8],
			stu->grades[9],stu->grades[10],stu->grades[11]);

	}
 	
 	fclose(f);

}




void freeClass(Class * c){
	for(int i=0;i<c->num;i++) {
		Student *s = c->stus + i;
		free(s->firstname);
		free(s->lastname);
		free(s->id);
		free(s->grades);
	}
	free(c->stus);
	free(c);
}