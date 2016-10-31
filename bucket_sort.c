#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lab1v2.c"

typedef struct node{
		float val;
		struct node * next;
	}node_t;


void bucket_sort(float A[], int n){
	node_t * B[n];
	int i;
	
	for (i = 0; i <= n; i++){
		B[i] = malloc(sizeof(node_t));
		if (B[i] == NULL){
			return;
		}
	}
	
	for (i = 1; i <= n; i++){
		B[i]->val = A[i];
	}
	
	for (i = 1; i <= n; i++){
		while(B[i]->val > 0){
			printf("%f\n", B[i]->val);
			B[i] = B[i]->next;
			break;
		}
	}	
	
}

void main(){
	float a[] = {.78, .17, .39, .26, .72, .94, .21, .12, .23, .68};
	int counter = 9;
	bucket_sort(a, counter);
}