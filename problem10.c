#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node * next;
}node_t;



//lists are sorted


node_t * insert_sorted(node_t * heap, int num){
	node_t * newnode = malloc(sizeof(node_t));
	newnode->val = num;
	
	if (heap == NULL || num < heap->val){
		newnode->next = heap;
		return newnode;
	}
	
	node_t * list = heap;
	while (list->next != NULL && list->next->val < num){
		list = list->next;
	}
	newnode->next = list->next;
	list->next = newnode;
	return heap;	
	
}

/*
int minimum(){
	int min = heap->val;
	node_t * list = heap;
	list = list->next;
	while (list != NULL){
		if (list->val > min){
			
		}
	}
}
*/



void main(){
	
	node_t * heap1 = malloc(sizeof(node_t));
	insert_sorted(heap1, 12);
	
	node_t * list = heap1;
	while (list != NULL){
		printf("%d\n", list->val);
		list = list->next;
	}
	
}






