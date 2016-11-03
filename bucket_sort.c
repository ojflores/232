#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct node{
		float val;
		struct node * next;
	}node_t;
	
void print_array(float arr[], int amount){
	int c;
	//starts at 1 because of indexing isssue
	for (c = 0; c < amount; c++){
		printf("%f\n", arr[c]);
	}
}

void insertion_sort(float a[], int counter){
	int j, i;
	float key;
	//initialization
	//"j" starts at one as opposed to 0 because the first number is already sorted when by itself
	for (j = 1; j < counter; j++){
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key){
			a[i+1] = a[i];
			i -= 1;
		}
		a[i+1] = key;
		//maintenance
	}
	//termination
}
	
	
void bucket_sort(float A[], int n){
	node_t * B[n];
	int i;
	
	for (i = 0; i <= n; i++){
		B[i] = NULL;
	}
	
	for (i = 0; i <= n; i++){
		int x = (n+1) * A[i];
		node_t * newnode = malloc(sizeof(node_t));
		newnode->val = A[i];
		newnode->next = B[x];
		B[x] = newnode;
		
	}
	
	
	for (i = 0; i <= n; i++){
		//this receives the counter for insertion sort
		float array[n];
		node_t * current = B[i];
		int how_many = 0;
		while (current != NULL){
			array[how_many] = current->val;
			how_many += 1;
			current = current->next;
		}
		insertion_sort(array, how_many);
		if(how_many > 0){
			
			print_array(array, how_many);
		}	
	}
	
	/*
	for (i = 0; i <= n; i++){
		node_t * current;
		current = B[i];
		while(current != NULL){
			printf("%f\n", current->val);
			current = current->next;
		}
	}	
	*/
}

void main(){
	float a[] = {.78, .17, .39, .26, .72, .94, .22, .12, .23, .68};
	int counter = 9;
	bucket_sort(a, counter);
}