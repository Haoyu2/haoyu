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




ArrayList* newArrayList(int len, int size, Com com){

	#ifdef DEBUG
	printf("Debug: newArrayList with arguments: \
	 len:%d size:%d com:%d", len, size, com==NULL);
	#endif

	if (len<1) {
		printf("The length of a arrayList should be positive\n");
		return NULL;
	}
	ArrayList *al = malloc(sizeof(ArrayList));
	TEST_NULL(al,"al in newArrayList()")

	al->end = -1;
	al->len = len;
	al->size = size;

	al->min = NULL;
	al->max = NULL;

	al->arr = malloc(size*len);
	TEST_NULL(al->arr,"al->arr in newArrayList()")

	al->info = infoArrayList;
	al->copy = copyArrayList;
	al->com = com;
	al->del = deleteArrayList;
	al->append = appendArrayList;
	al->appends = appendsArrayList;
	al->get = get_ArrayList;
	al->insert = insert_ArrayList;
	al->remove = remove_ArrayList;
	al->removes = removes_ArrayList;
	al->in = in_ArrayList;

	al->concat = concat_ArrayList;

	#ifdef DEBUG
	printf("Debug: newArrayList return with : \
	 len:%d size:%d com:%d", len, size,! (com==NULL));
	#endif

	return al;
}


// [1,2,3,4]
// 

void infoArrayList(struct arrayList *al){

	int min = al->min == NULL ? -1 : (al->min-al->arr)/al->size;
	int max = al->max == NULL ? -1 : (al->max-al->arr)/al->size;
	printf("Length:%d\tDataSize:%d\tEnd_Index:%d\tMin_Index:%d\tMax_Index:%d\n",
		al->len,al->size,al->end,min,max);
}


ArrayList* copyArrayList(ArrayList *al){
	if (al==NULL) return NULL;
	ArrayList* al1 = newArrayList(al->len,al->size,al->com);
	

	// copy the data elelent in the arraylist
	memcpy(al1->arr,al->arr,al->size * (al->end + 1));

	// min, max are actullay harder
	// min_index first and then the address
	int min = al->min == NULL ? -1 : (al->min-al->arr)/al->size;
	int max = al->max == NULL ? -1 : (al->max-al->arr)/al->size;

	if (min!=-1)
		al1->min = al1->arr + min;
	if (max!=-1)
 		al1->max = al1->arr + max;

	return al1;
}



void deleteArrayList(ArrayList *al){
	if (al==NULL) {
		printf("ArrayList is NULL\n");
		return;
	}
	for(int i=0;i<al->end;i++)
		if (al->arr + i!=NULL)
			free(al->arr+i);
	free(al);
}



void extendArrayList(ArrayList *al){

	al->len *=2;
	al->arr = realloc(al->arr,al->len * al->size);
	TEST_NULL(al->arr,"al->arr in extendArrayList")
}



void appendArrayList(ArrayList *al, void *x, int size){
	if (al==NULL) {
		printf("ArrayList is NULL\n");
		return;
	}
	if (size != al->size) {
		printf("Data type is not Consistent in appendArrayList\n");
		return;
	}
	al->end++;
	if (al->end >= al->len)
		extendArrayList(al);
	memcpy(al->arr+(al->end*size),x,size);

	if (al->com==NULL) return;
	if (al->min==NULL) {
		al->min = al->arr;
		al->max = al->arr;
	}
	else if ((al->com(al->min,x))>0)
		al->min = al->arr+(al->end*size);
	else if ((al->com(al->max,x))<0)
		al->max = al->arr+(al->end*size);
}


void appendsArrayList(ArrayList *al, void *x, int size, int num){
	if (al==NULL) {
		printf("ArrayList is NULL\n");
		return;
	}
	if (size != al->size) {
		printf("Data type is not Consistent in appendsArrayList\n");
		return;
	}
	al->end+=num;
	if (al->end + num >= al->len)
		extendArrayList(al);
	memcpy(al->arr+((al->end-num+1)*size),x,size*num);

	if (al->com==NULL) return;

	if (al->min==NULL) {
		al->min = al->arr;
		al->max = al->arr;
	}	

	for (int i=0;i<num;i++){
		#ifdef DEBUG
		printf("min:%d\tmax:%d\tx:%d\n",
			 *((int*)al->min),*((int*)al->max), *(int*)(x+i*size));
		#endif
		if ((al->com(al->min,x+i*size))>0)
			al->min = al->arr+((al->end-num + 1 + i)*size);
		if ((al->com(al->max,x+i*size))<0)
			al->max = al->arr+((al->end-num + 1 + i)*size);
	}
	
}






void* get_ArrayList(ArrayList *al, int i){

	if (al==NULL) {
		printf("ArrayList is NULL\n");
		return NULL;
	}

	if (i>al->end){
		printf("Index %d is out of range in ArrayList\n", i);
		return NULL;
	}
	return al->arr+i;
}




void insert_ArrayList(ArrayList *al,int i, void *x, int size){

	if (al==NULL) {
		printf("ArrayList is NULL\n");
		return;
	}
	if (size != al->size) {
		printf("Data type is not Consistent in insert_ArrayList\n");
		return;
	}

	if (i>al->end+1) {
		printf("Inserting index is out of range \n");
		return;
	}
	al->end++;
	if (al->end >= al->len)
		extendArrayList(al);



// Right shift one size from index i,
	for (int j=al->end;j>i;j--){
		memcpy(al->arr+j*size,al->arr+(j-1)*size, size);
	}
	memcpy(al->arr+(i*size),x,size);
// Testing if min and max is shited

	int l_min = (al->min - al->arr) / size;
	if (l_min>=i) al->min = al->min + size;
	int l_max = (al->max - al->arr) / size;
	if (l_max>=i) al->max = al->min + size;

// If the comparator function is defined
	if (al->com==NULL) return;

	if (al->min==NULL) {
		al->min = al->arr;
		al->max = al->arr;
	}
	else if ((al->com(al->min,x))>0)
		al->min = al->arr+(i*size);
	else if ((al->com(al->max,x))<0)
		al->max = al->arr+(i*size);
}


void remove_ArrayList(ArrayList *al, int i){

	if (al==NULL) {
		printf("ArrayList is NULL\n");
		return;
	}

	if (i>al->end) {
		printf("Removing index is out of range \n");
		return;
	}

// Left shift one size from index i,
	for (int j=i;j<al->end+1;j++){
		memcpy(al->arr+j*al->size, al->arr+(j+1)*al->size,al->size);
	}

	al->end--;


	if (al->com==NULL) return;

	if (al->end<0) {
		al->min = NULL;
		al->max = NULL;
	}else{	

		al->min = al->arr;
		al->max = al->arr;
		for (int i=1;i<al->end+1;i++){
			#ifdef DEBUG
			printf("min:%d\tmax:%d\t\n",
				 *((int*)al->min),*((int*)al->max));
			#endif
			if ((al->com(al->min,al->arr+i*al->size))>0)
				al->min = al->arr+i*al->size;
			if ((al->com(al->max,al->arr+i*al->size))<0)
				al->max = al->arr+i*al->size;
		}	
	}
}


// j is included
void removes_ArrayList(ArrayList *al, int i, int j){

	if (al==NULL) {
		printf("ArrayList is NULL\n");
		return;
	}

	if (j>al->end || i < 0) {
		printf("Removing index is out of range \n");
		return;
	}

// Left shift one size from index i,
	for (int k=j+1;k<al->end+1;k++){
		memcpy(al->arr+(k-j-1+i)*al->size, al->arr+k*al->size,al->size);
	}

	al->end-=(j-i+1);

	if (al->com==NULL) return;
	if (al->end<0) {
		al->min = NULL;
		al->max = NULL;
	}else{	

		al->min = al->arr;
		al->max = al->arr;
		for (int i=1;i<al->end+1;i++){
			if ((al->com(al->min,al->arr+i*al->size))>0)
				al->min = al->arr+i*al->size;
			if ((al->com(al->max,al->arr+i*al->size))<0)
				al->max = al->arr+i*al->size;
		}	
	}
}



int in_ArrayList(ArrayList *al, void *x, int size){
	if (al==NULL) {
		printf("ArrayList is NULL\n");
		exit(1);
	}

	if (x==NULL) {
		printf("Element is NULL\n");
		return 0;
	}
	if (size != al->size) {
		printf("Data type is not Consistent in appendArrayList\n");
		exit(1);
	}


	for (int i=0;i<al->end+1;i++)
		if (!memcmp(al->arr+i*al->size, x, size))
			return 1;
	return 0;
}



ArrayList* concat_ArrayList(ArrayList *al1, ArrayList *al2){

	if (al1==NULL){
		if (al2==NULL) return NULL;
		else return al2->copy(al2);
	}else if (al2==NULL)
			 return al1->copy(al1);
	
	ArrayList *al = al1->copy(al1);

	al->appends(al,al2->arr,al2->size,al2->end+1);

	return al;
}
