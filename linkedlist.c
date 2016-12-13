#include <stdio.h>
#include <stdlib.h>
// map the input +/- to each data structure 
// Stack: #define PLUS push #define MINUS pop 
// Queue: //#define PLUS  enqueue //#define MINUS dequeue 
// Linked List: 
#define PLUS  insert
#define MINUS delete 
// uncomment the appropriate lines above
// define your push/pop, enqueue/dequeue, or insert/delete 
// and an appropriate print_datastructure function here 
typedef struct node{
		int value;
		struct node * next;
		struct node * prev;
}node_t;
node_t * list = NULL;

node_t * list_search(int k){
	node_t * x = list;
	while (x != NULL && x->value != k){
		x = x->next;
	}
	return x;
}

void delete_something(node_t * other){
	if (other->prev != NULL){
		other->prev->next = other->next;
	}
	else {
		list = other->next;
	}
	if (other->next != NULL){
		other->next->prev = other->prev;
	}
}

void insert(int val) {

	node_t * newnode = malloc(sizeof(node_t));
	newnode->value = val;
	if (list != NULL){
		newnode->next = list;
	}
	list = newnode;
	printf("push: %d \n", val);
}
int delete(int k) {
	node_t * index;
	index = list_search(k);
	if (index != NULL){
		delete_something(index);
	}
	printf("pop!\n"); 
	return(1);
} 

void print_datastructure() { 
	printf("Printing...\n");
	node_t * temp;
	temp = list;
	while (temp != NULL){
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}
 // end definitions
// Leave this alone: 
#include "datastruct_queue.h" 
int main() {
	parse_exec(); 
	print_datastructure();
}