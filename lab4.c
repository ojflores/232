#include <stdio.h>
#include <stdlib.h>
#define AMOUNT_OF_NUMBERS 10
#define MAX 100000

void print_array(int arr[], int amount){
	int c;
	amount += 1;
	for (c = 1; c <= amount; c++){
		printf("%d\n", arr[c]);
	}
}

void counting_sort(int A[], int B[], int k, int length){
	int C[k+1];
	int i, j;
	for (i = 0; i < (k+1); i++){
		C[i] = 0;
	}
	
	for (j = 0; j <= length; j++){
		C[A[j]] = C[A[j]] + 1;
	}
	
	for (i = 1; i < (k+1); i++){
		C[i] = C[i] + C[i-1];
	}
	
	for (j = length; j >= 0; j--){
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
	
}


void main(){
	int A[20] = {2, 5, 3, 0, 2, 3, 0, 3};
	int B[20];
	int k = 5;
	int length = 7;
	counting_sort(A, B, k, length);
	print_array(B, length);
	
	
	
}