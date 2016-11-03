#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100000

typedef struct node{
		float val;
		struct node * next;
	}node_t;
	
void print_array(float arr[], int amount){
	int c;
	for (c = 0; c < amount; c++){
		printf("%f\n", arr[c]);
	}
}

void bucket_insertion_sort(float a[], int counter){
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
		//had to create a pointer to the items in memory
		node_t * current = B[i];
		int how_many = 0;
		while (current != NULL){
			array[how_many] = current->val;
			how_many += 1;
			current = current->next;
		}
		bucket_insertion_sort(array, how_many);
		//doesn't print the zeros that are in the array
		if(how_many > 0){
			print_array(array, how_many);
		}	
	}

}

void main(){
	float a[] = {.78, .17, .39, .26, .72, .94, .22, .12, .23, .68};
 	int counter = 9;
 	bucket_insertion_sort(a, counter);
	print_array(a, counter);
	float my_array[MAX];
	int i;
	int n = MAX;
	float b = 1.0;
	for (i = 0; i < n; i++){
		my_array[i] = ((float)rand()/(float)(RAND_MAX)) * b;	//random number generator found at: http://stackoverflow.com/questions/13408990/how-to-generate-random-float-number-in-c
	}
	
	
	//timed
	printf("timer beginning: \n");
	clock_t begin = clock();
	bucket_insertion_sort(my_array, MAX);
	clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("time spent: %f\n", time_spent);

}