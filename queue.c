#include <stdio.h>
// map the input +/- to each data structure 
// Stack: #define PLUS push #define MINUS pop 
// Queue: 
#define PLUS  enqueue 
#define MINUS dequeue 
#define MAX 10
// Linked List: //#define PLUS  insert //#define MINUS delete 
// uncomment the appropriate lines above
// define your push/pop, enqueue/dequeue, or insert/delete 
// and an appropriate print_datastructure function here 


int array[MAX];
int current = 0;
int head = 0;

void enqueue(int val) {
	if (current == head && array[head] != 0){
		printf("overflow");
	}
	else if (current > 9){
		current = 0;
	}
	array[current] = val;
	current++;
	printf("enqueue: %d \n", val);
}
int dequeue() {
	if (current == 0){
		printf("underflow\n");
		
	}
	else {
		printf("dequeue!: %d\n", array[head]);
		array[head] = 0;
		head++;
	}
	return(1);
}
void print_datastructure() { 
	printf("Printing...\n");
	int c;
	for (c = 0; c < MAX; c++){
		printf("%d\n", array[c]);
	}
	
	
	
} // end definitions
// Leave this alone: 
#include "datastruct_queue.h" 

int main() {
	parse_exec();
	print_datastructure();
}
