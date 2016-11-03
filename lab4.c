#include <stdio.h>
#include <stdlib.h>
#define AMOUNT_OF_NUMBERS 10
//#define MAX 100000

void print_array(int arr[], int amount){
	int c;
	amount += 1;
	//starts at 1 because of indexing isssue
	for (c = 1; c <= amount; c++){
		printf("%d\n", arr[c]);
	}
}

void counting_sort(int A[], int B[], int k, int length){
	int C[k+1];
	int i, j;
	//makes everything in C zero
	for (i = 0; i < (k+1); i++){
		C[i] = 0;
	}
	//adds a counter so that we know how many there are
	for (j = 0; j <= length; j++){
		C[A[j]] = C[A[j]] + 1;
	}
	//adds the numbers previous to it for some reason
	for (i = 1; i < (k+1); i++){
		C[i] = C[i] + C[i-1];
	}
	//B here is 1 indexed, different than C and A which are 0 indexed
	for (j = length; j >= 0; j--){
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
	
}


void main(){
	int A[20] = {25, 52, 33, 10, 32, 53, 70, 23};
	int B[20];
	int k = 7;
	int length = 7;
	counting_sort(A, B, k, length);
	print_array(B, length);

}
