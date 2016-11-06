#include <stdio.h>
#include <stdlib.h>
// map the input +/- to each data structure 
// Stack: 
#define PLUS push 
#define MINUS pop 
#define MAX 10
// Queue: 
//#define PLUS  enqueue 
//#define MINUS dequeue 
// Linked List: 
//#define PLUS  insert 
//#define MINUS delete 
// uncomment the appropriate lines above
// define your push/pop, enqueue/dequeue, or insert/delete 
// and an appropriate print_datastructure function here 
int array[MAX];
int head = 0, tail = 0;


void push(int val) {
	if (tail > 9){
		printf("overflow");
	}
	array[tail] = val;
	printf("push: %d\n", val);
	tail++;
}
int pop() {
	if (array[head] == 0){
		printf("underflow\n");
	}
	else {
		printf("pop! %d\n", array[tail-1]);
		tail--;
		array[tail] = 0;
	}
	return(1);
}
void print_datastructure() { 
	printf("Printing...\n");
	int c;
	for (c = 0; c < MAX; c++){
		printf("%d\n", array[c]);
	}
} 
// end definitions
// Leave this alone: 
#include "datastruct.h" 
int main() {
	parse_exec();
	print_datastructure();
}

