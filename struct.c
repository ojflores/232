#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define NUMBER_OF_VERTICES 10
#define INF_DISTANCE 20
#define WHITE 0
#define GRAY 1
#define BLACK 2
//these hold the counters for enqueue/dequeue
int current = 0, head = 0;

typedef struct node{
	int val;
	struct node * next;
}node_t;

typedef struct vertex{
	int n;
	int color;
	int distance;
	struct vertex * parent;
}vertex_t;

void push(node_t * head, int value){
	if (head == NULL){
		head = malloc(sizeof(node_t));
	}
	node_t * current = head;
	while (current->next != NULL){
		current = current->next;
	}
	current->next = malloc(sizeof(node_t));
	current->next->val = value;
	current->next->next = NULL;
	return;
}
//takes in an array and the number(index) of the starting node
//carefule, the input numbers are 1 indexed
void BFS(node_t * array[], int s){
	vertex_t * u[NUMBER_OF_VERTICES];
	int i;
	for (i = 0; i < NUMBER_OF_VERTICES; i++){
		u[i] = malloc(sizeof(vertex_t));
		u[i]->color = WHITE;
		u[i]->distance = 0;
		u[i]->parent = NULL;
	}
	u[s]->color = GRAY;
	u[s]->distance = 0;
	u[s]->parent = NULL;
	
	//left off here man
	node_t * Q = malloc(sizeof(node_t));
	push(Q, s);
	Q = Q->next;
	int d = 1;
	while(Q != NULL){
		int vert = Q->val;
		
		printf("\n verts:  %d:  ", vert);
		
		node_t * current = array[vert];
		current = current->next;
		while (current != NULL){
			printf("\ncurrent values:  %d:  ", current->val);
			if (u[current->val]->color == WHITE){
				u[current->val]->color = GRAY;
				u[current->val]->distance = d;
				u[current->val]->parent = u[vert];
				push(Q, current->val);
			}
			current = current->next;
		u[vert]->color = BLACK;
		
		}
		Q = Q->next;
		d++;
	}
	
	
	
	
	
	
	
	printf("\n\n\n");
	for(i = 0; i < NUMBER_OF_VERTICES; i++){
		vertex_t * x = u[i];
		printf("%d, ", x->distance);
		printf("%d\n", x->color);		
	}
	
}




void parse_exec(){
	FILE * input;
	input = fopen("graph.input", "r");
	char mystring[MAX];
	//gets the first line of input file and makes an array of x amount
	fgets(mystring, MAX, input);
	int number = atoi(mystring);
	node_t * array[number];
	int i, number2;
	
	for (i = 0; i < number; i++){
		array[i] = malloc(sizeof(node_t));
	}
	const char delim[2] = " ";
	//strtok seperates the numbers from the input file
	//while loop pushes them into an array of linked lists
	for(i = 0; i < number; i++){
		char *token;
		if(fgets(mystring, MAX, input) != NULL){
			token = strtok(mystring, delim);
			while(token != NULL){
				number2 = atoi(token);
				push(array[i], number2);
				token = strtok(NULL, delim);	
			}
		}
	}
	//prints everything
	for(i = 0; i < number; i++){
		node_t * current = array[i];
		while(current != NULL){
			if(current->val == 0){
				current = current->next;
			}
			printf("%d ", current->val);
			current = current->next;
		}
		printf("\n");
	}
	BFS(array, 2);
	
	
	fclose(input);
}


void main(){
	
	parse_exec();
	
}