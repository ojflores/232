#include <stdio.h>
#include <stdlib.h>


void counting_sort(int A[], int B[], int k, int length){
	int C[k];
	int i, j;
	for (i = 0; i <= k; i++){
		C[i] = 0;
	}
	for (j = 1; j < length; j++){
		C[A[j]] = C[A[j]] + 1;
	}
	
	
	
	
	
	int d;
	for (d = 0; d < i; d++){
		printf("%d\n", C[d]);
	}
}

void main(){
	int A[20] = {2, 4, 3, 1};
	int B[20];
	int k = 4;
	int length = 4;
	counting_sort(A, B, k, length);
	
}