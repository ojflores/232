#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define INPUT "input.txt"





int partition(int A[], int p, int r){	//for now counter = 13
	int x = A[r];
	int i = p - 1;
	int temp, t, j;
	//i = p-1 && j = p
	for (j = p; j < r; j++){
		if(A[j] <= x){
			i += 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	//A[j-1] was swapped, now is > x 
	t = A[i+1];
	A[i+1] = A[r];
	A[r] = t;
	return (i + 1);
	//termination: now j = r
}

void quicksort(int A[], int p, int r){
	int q;
	if (p < r){
		q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
	
}

int randomized_partition(int A[], int p, int r){
	//next funky line: makes sure to get a random number from within the array its working with
	int i = rand() % (r-p) + p;
	int temp = A[r];
	A[r] = A[i];
	A[i] = temp;
	partition(A, p, r);	
}

void randomized_quicksort(int A[], int p, int r){
	int q;
	if (p < r){
		q = randomized_partition(A, p, r);
		randomized_quicksort(A, p, q-1);
		randomized_quicksort(A, q+1, r);
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
	counter -= 1;
	printf("regular quicksort:\n");
	quicksort(a, 0, counter);
	print_array(a, counter);
	
	printf("\nrandomized quicksort:\n");
	randomized_quicksort(a, 0, counter);
	print_array(a, counter);
	
	
}
