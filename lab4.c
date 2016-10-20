#include <stdio.h>
#include <stdlib.h>


void counting_sort(int A[], int B[], int k, int length){
	int C[k];
	int i, j;
	for (i = 0; i <= k; i++){
		C[i] = 0;
	}
	for (j = 0; j <= length; j++){
		C[A[j]] = C[A[j]] + 1;
	}
	for (i = 1; i <= k; i++){
		C[i] = C[i] + C[i - 1];
	}
	for (j = 7; j >= 0; j--){
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
	
	int d;
	for (d = 1; d <= 8; d++){
		printf("%d\n", B[d]);
	}
}

void main(){
	int A[20] = {2, 5, 3, 0, 2, 3, 0, 3};
	int B[20];
	int k = 5;
	int length = 7;
	counting_sort(A, B, k, length);
	
}