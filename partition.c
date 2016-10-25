#include <stdio.h>
#include <stdlib.h>
#define MAX 40
#define INPUT "input.txt"




int partition(int A[], int p, int r){
	int x = A[r];
	int i = p - 1;
	int temp, j;
	for (j = p; j <= r - 1; j++){
		if (A[j] <= x){
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	return i + 1;
}

void quicksort(int A[], int p, int r){
	int q;
	if (p < r){
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

void print_array(int arr[], int counter){
	int c;
	counter += 1;
	for (c = 0; c < counter; c++){
		printf("%d\n", arr[c]);
	}
}

void main(){
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int a[MAX];
	FILE *f = fopen(INPUT, "r");
	
	int counter = 0;
	//while loop found on http://man7.org/linux/man-pages/man3/getline.3.html
	while ((read = getline(&line, &len, f)) != -1) {
		a[counter] = atoi(line);
		counter += 1;
	}
	//sets the counter up correctly
	counter -= 1;
	//counter = r
	print_array(a, counter);
	printf("\n");
	
	quicksort(a, 0, counter);
	print_array(a, counter);
	
	
}