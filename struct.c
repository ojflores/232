#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define NUMBER_OF_VERTICES 10
#define INF_DISTANCE 20
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct node{
	int val;
	struct node * next;
}node_t;

typedef struct vertex{
	int color;
	int distance;
	struct vertex * parent;
}vertex_t;

void BFS(node_t * array[], int s){
	vertex_t * u[NUMBER_OF_VERTICES];
	int i;
	for (i = 0; i < NUMBER_OF_VERTICES; i++){
		u[i] = malloc(sizeof(vertex_t));
		u[i]->color = WHITE;
		u[i]->distance = INF_DISTANCE;
		u[i]->parent = NULL;
	}
	u[s]->color = GRAY;
	u[s]->distance = 0;
	u[s]->parent = NULL;
	//left off here man
	//need to make an enqueue thing, or find one from previous assignment
	//then write the while loop
	
	printf("\n\n\n");
	for(i = 0; i < NUMBER_OF_VERTICES; i++){
		vertex_t * current = u[i];
		printf("%d, ", current->distance);
		printf("%d\n", current->color);		
	}
}

void push(node_t * head, char * value){
	int number = atoi(value);
	node_t * current = head;
	
	while (current->next != NULL){
		current = current->next;
	}
	current->next = malloc(sizeof(node_t));
	current->next->val = number;
	current->next->next = NULL;
	return;
}

void parse_exec(){
	FILE * input;
	input = fopen("graph.input", "r");
	char mystring[MAX];
	fgets(mystring, MAX, input);
	int number = atoi(mystring);
	node_t * array[number];
	int i, number2;
	for (i = 0; i < number; i++){
		array[i] = malloc(sizeof(node_t));
	}
	const char delim[2] = " ";
	for(i = 0; i < number; i++){
		char *token;
		if(fgets(mystring, MAX, input) != NULL){
			//printf("%s", mystring);
			token = strtok(mystring, delim);
			
			while(token != NULL){
				push(array[i], token);
				token = strtok(NULL, delim);	
			}
		}
	}
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
	BFS(array, 1);
	
	
	fclose(input);
}


void main(){
	
	parse_exec();
	
}