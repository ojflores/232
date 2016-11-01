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

void counting_sort(int A[], int B[], int k, int length, int o){
	int C[k];
	int i, j, mod = 10;
	
	//makes everything in C zero
	for (i = 0; i <= k; i++){
		C[i] = 0;
	}
	
	//adds a counter so that we know how many there are
	for (j = 0; j <= length; j++){
		//divides by "o" to get rid of the unwanted numbers
		//then "%s" it to get the significant digit that we want
		C[(A[j] / o) % mod] = C[(A[j] / o) % mod] + 1;
	}
	
	//adds the numbers previous to make so that things will go into the correct array in the next for loop
	for (i = 1; i < (k+1); i++){
		C[i] = C[i] + C[i-1];
	}
	//B here is 1 indexed, different than C and A which are 0 indexed
	for (j = length; j >= 0; j--){
		B[C[(A[j] / o) % mod]] = A[j];
		C[(A[j] / o) % mod] = C[(A[j] / o) % mod] - 1;
	}
	//copies things into A to reset A and keep numbers in rightful order: as in makes this thing stable
	for (j = 0; j <= length; j++){
		A[j] = B[j+1];
	}
	
}


void main(){
	int A[20] = {24, 50, 32, 12, 22, 33, 10, 33, 28};
	int B[20];
	int k = 8;
	int length = 8;
	
	
	int i, end = 0, o = 1;
	for (i = 2; i > end; i--){
		counting_sort(A, B, k, length, o);
		print_array(B, length);
		printf("\n");
		//used as a divider to get the next signigicant digit
		o = o * 10;
		
	}
}

