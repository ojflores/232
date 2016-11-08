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



int minimum(node_t * heap){
	int min = heap->val;
	node_t * list = heap->next;
	list = list->next;
	while (list != NULL){
		if (list->val < min){
			min = list->val;
		}
		list = list->next;
	}
	return min;
}

//found at https://www.cs.bu.edu/teaching/c/linked-list/delete/
node_t * extract_min(node_t * heap){
	int min = minimum(heap);
	//printf("%d\n", min);
	if (heap == NULL){
		return NULL;
	}
	
	if (heap->val == min){
		node_t * temp;
		temp = heap->next;
		free(heap);
		return temp;
	}
	heap->next =  extract_min(heap->next);
	return heap;
}


void main(){
	
	node_t * heap1 = malloc(sizeof(node_t));
	insert_sorted(heap1, 12);
	insert_sorted(heap1, 14);
	insert_sorted(heap1, 3);
	node_t * list = heap1->next;
	extract_min(list);
	//printf("%d\n", minimum(heap1));
	while (list != NULL){
		printf("%d\n", list->val);
		list = list->next;
	}
}






