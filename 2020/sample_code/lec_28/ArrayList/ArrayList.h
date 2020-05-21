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



#ifndef ARRAYLIST_H
#define ARRAYLIST_H 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef TEST_NULL
#define TEST_NULL(p,s) \
		if (p == NULL){ \
			printf("Pointer %s is NULL\n",s); \
			exit(EXIT_FAILURE); }
#endif

#ifndef COMPARATOR
#define COMPARATOR
typedef int (*Com)(const void*, const void*);
#endif


// Using void * here for min and max is because
// the minimum and maximum are dependent on how
// the comparation of data type to be defined for the
// the Array element 


/*

com will be referencing an existing comparator function

if com is null then min and max should always be null

if com is not null min max will be referencing to existing element


*/



typedef struct arrayList
{
	void *arr, *min, *max;
	int end, len, size;
	
	Com com;
	void (*info)(struct arrayList *);
	struct arrayList * (*copy)(struct arrayList *);
	void (*del)(struct arrayList *);
	void (*append)(struct arrayList *, void *, int);
	void (*appends)(struct arrayList *, void *, int, int);
	void *(*get)(struct arrayList *, int);

	void (*insert)(struct arrayList *, int, void *, int);
	void (*remove)(struct arrayList *, int);
	void (*removes)(struct arrayList *, int, int);
	int (*in)(struct arrayList *al, void *, int);

	struct arrayList * (*concat)(struct arrayList *, struct arrayList *);

} ArrayList;



// Create new ArrayList

ArrayList* newArrayList(int len, int size, Com com);

void infoArrayList(struct arrayList *al);

ArrayList* copyArrayList(ArrayList *al);

void deleteArrayList(ArrayList *al);

void appendArrayList(ArrayList *al, void *x, int size);

void appendsArrayList(ArrayList *al, void *x, int size, int num);

void* get_ArrayList(ArrayList *al, int i);

void insert_ArrayList(ArrayList *al, int i, void *x, int size);

void remove_ArrayList(ArrayList *al, int i);

void removes_ArrayList(ArrayList *al, int i, int j);

int in_ArrayList(ArrayList *al, void *x, int size);

ArrayList* concat_ArrayList(ArrayList *al1, ArrayList *al2);



#endif