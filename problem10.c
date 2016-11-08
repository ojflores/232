#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node * next;
}node_t;


//takes a node_t and a number and inserts it in a non descending order
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


//finds the minimum
int minimum(node_t * heap){
	int min = heap->val;
	node_t * list = heap->next;
	list = list->next;
	//goes through the list comparing items so that it indeed returns minimum
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

//uses sorted insert to insert items from a sorted list to another sorted list
node_t * sorted_uniter(node_t * list1, node_t * list2){
	node_t * temp = list2;
	int value;
	while (temp->next != NULL){
		 value = temp->val;
		 insert_sorted(list1, value);
		 temp = temp->next;
	}
	return list1;
}

//slaps the list on the end of another list
node_t * uniter(node_t * list1, node_t * list2){
	node_t * temp = list1;
	while(temp != NULL){
		temp->next;
	}
	temp->next = list2;
	return temp;
	
}


void main(){
}






