#include <stdio.h>
#include <stdlib.h>
#define AMOUNT_OF_NUMBERS 10
#define MAX 100000



void counting_sort(int A[], int B[], int k, int length){
	int C[k + 1];
	int i, j;
	for (i = 0; i <= k; i++){
		C[i] = 0;
	}
	for (j = 1; j <= length; j++){
		C[A[j]] = C[A[j]] + 1;
	}
	for (i = 1; i <= k; i++){
		C[i] = C[i] + C[i - 1];
	}
	for (j = length; j >= 1; j--){
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
	//return B;
}

void print_array(int arr[], int amount){
	int d;
	for (d = 1; d <= amount; d++){
		printf("%d\n", arr[d]);
	}
}

void main(){
	int A[20] = {0, 2, 5, 3, 0, 2, 3, 0, 3};
	int B[20];
	int k = 5;
	int length = 8;
	//counting_sort(A, B, k, length);
	//print_array(B, 8);
	
	int i;
	int array[AMOUNT_OF_NUMBERS+1];
	int arraybn[AMOUNT_OF_NUMBERS+1];
	for (i = 1; i <	 1+AMOUNT_OF_NUMBERS; i++){
		array[i] = rand() % 10;
	}
	//counting_sort(array, arraybn, 15, AMOUNT_OF_NUMBERS);
	counting_sort(A, arraybn, 15, 8);
	//print_array(array, AMOUNT_OF_NUMBERS);
	print_array(A, 8);
	printf("\n");
	//print_array(arraybn, AMOUNT_OF_NUMBERS);
	print_array(arraybn, 8);
	
	
	
	
	
}