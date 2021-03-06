#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define NUMBER_OF_VERTICES 11
#define INF_DISTANCE 20
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct v2{
	int color;
	struct v2 * parent;
	int distance;
	int final;
}v2_t;

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

	node_t * Q = malloc(sizeof(node_t));
	push(Q, s);
	Q = Q->next;
	int d = 1;
	while(Q != NULL){
		//use vert to keep the value even after it is passed over later on
		int vert = Q->val;
		printf("\n verts:  %d:  ", vert);
		node_t * current = array[vert];
		//when things are pushed into a list they are pushed into the *next of the head pointer
		//next line corrects this problem
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
		//increases the distance every time the loop finishes
		d++;
	}
	printf("\n\n\n");
	for(i = 0; i < NUMBER_OF_VERTICES; i++){
		vertex_t * x = u[i];
		printf("%d, ", x->distance);
		printf("%d\n", x->color);		
	}
	
}

void DFS_visit(node_t * array[], v2_t * vertex[], int u, int time){
	time += 1;
	vertex[u]->distance = time;
	vertex[u]->color = GRAY;
	node_t * current = array[u];
	current = current->next;
	while (current != NULL){
		if (vertex[current->val]->color == WHITE){
			vertex[current->val]->parent = vertex[u];
			DFS_visit(array, vertex, current->val, time);
		}
		current = current->next;
	}
	vertex[u]->color = BLACK;
	time += 1;
	vertex[u]->final = time;
}

void DFS(node_t * array[], int u){
	v2_t * vertices[NUMBER_OF_VERTICES];
	int i;
	for (i = 0; i < NUMBER_OF_VERTICES; i++){
		vertices[i] = malloc(sizeof(v2_t));
		vertices[i]->color = WHITE;
		vertices[i]->parent = NULL;
	}
	int time = 0;
	node_t * current = array[u];
	current = current->next;
	while (current != NULL){
		if (vertices[current->val]->color == WHITE){
			DFS_visit(array, vertices, u, time);
		}
		current = current->next;
	}
	
	for (i = 0; i < 8; i++){
		printf("\n%d", vertices[i]->color);
		printf("%d", vertices[i]->distance);
		printf("%d\n", vertices[i]->final);
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
	DFS(array, 2);
	
	
	fclose(input);
}


void main(){
	parse_exec();
}