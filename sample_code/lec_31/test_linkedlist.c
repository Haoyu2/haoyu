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




//  node1 -> node2 -> node3 -> NULL

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node
{
	int val;
	struct list_node *next;
}ListNode;


ListNode* createLinkedList(int *array, int len){

	ListNode *start = NULL, *p = NULL;
	if (len==0) return start;

    start = malloc(sizeof(ListNode));
    start->val = array[0];
	start->next = NULL;
	p = start;
	for (int i=1; i<len;i++ ){
		p->next = malloc(sizeof(ListNode));
		p = p->next;
		p->val = array[i];
		p->next = NULL;
	}

	return start;
}


void printLinkedList(ListNode *start){
	// If the argument is **start
	// then modify *start local will change the start in main

	// In main the start value is intact
	// This start is local 
	if (start==NULL) {
		printf("NULL here\n");
		return;
	}
	while(start!=NULL){

		printf("%d\t", start->val);
		start = start->next;
	}
	printf("\n");
}


ListNode * appendLinkedList(ListNode *start, int val){

	if (start == NULL){
		start = malloc(sizeof(ListNode));		
		start->val = val;
		start->next = NULL;
	}else{
		ListNode *cur = start;		
		while(cur->next!=NULL) cur = cur->next;
		cur->next = malloc(sizeof(ListNode));
		cur->next->val = val;
		cur->next->next = NULL;
	}

	return start;
}


void updateLinkedList(ListNode *start, unsigned index, int val){
	unsigned i=0;
	while(start){
		if (index == i){
			start->val = val;
			return ;
		}
		start = start->next;
		i++;
	} 
	printf("Out of bound\n");
}


ListNode * removeLinkedListIndex(ListNode *start, unsigned index){
	
	unsigned i=1;
	ListNode *cur = start, *p;
	if (cur == NULL) {
		printf("Cannot remove from NULL\n");
		return NULL;
	}
	if (index == 0) {
		p = start;
		start = start->next;
		free(p);
		
		return start;
	}
	while(cur->next!=NULL){
		if (index == i){

			p = cur->next;
			cur->next = cur->next->next;
			free(p);
			return start;
		}
		cur = cur->next;
		i++;
	} 
	printf("Out of bound\n");

	return start;
}





void reverseInpLL(ListNode **start){
	if (!(*start) || !(*start)->next) return;
	ListNode *cur= *start,*pre = NULL,*temp;
	while(cur){
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	*start = pre;
}








int main(int argc, char const *argv[])
{

	int arr[5] = {1,2,3,4,5};
	ListNode *ll = createLinkedList(arr,5);
	printLinkedList(ll);


	printf("\n\n-------Appends----\n");
	ListNode *p = NULL;
	p =  appendLinkedList(p,0); printLinkedList(p);
	printf("-------\n\n");

	ll = appendLinkedList(ll,6);printLinkedList(ll);


	printf("\n\n-------update----\n");
	updateLinkedList(ll,5,-1);printLinkedList(ll);
	
	

	printf("\n\n-------remove----\n");
	ll = removeLinkedListIndex(ll,0);printLinkedList(ll);
    p =	removeLinkedListIndex(p,0);printLinkedList(p);
	removeLinkedListIndex(p,0);
	printf("------\n");


	printLinkedList(ll);
	reverseInpLL(&ll);printLinkedList(ll);
	
	
	return 0;
}

