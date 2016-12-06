#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct node{
	int val;
	struct node * next;
}node_t;

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
			push(array[i], token);
			while(token != NULL){
				
				token = strtok(NULL, delim);
				push(array[i], token);	//herein is the problem
				
			}
			
			
		}
	}
	
	for(i = 0; i < number; i++){
		node_t * current = array[i];
		while(current != NULL){
			if(current->val == 0){
				current = current->next;
			}
			printf("%d\n", current->val);
			current = current->next;
		}
	}
	
	
	
	fclose(input);
}


void main(){
	parse_exec();
	
}