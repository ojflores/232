#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab1v2.c"
#include "lab2.c"
#include "lab22.c"
#include "lab3.c"
#include "quicksort.c"
#define MAX 100000
//#include "quicksort.c"
//#include "lab4.c"



print_array(int arr[], int counter){
	int c;
	counter += 1;
	for (c = 3; c < counter; c++){
		printf("%d\n", arr[c]);
	}
}

int main()
{
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
	
	
	int my_array[MAX];
	int i;
	int n = MAX;
	for (i = 0; i < n; i++){
		my_array[i] = rand() % MAX;
	}
	
	/*
	//insertion sort
	printf("insertion sort");
	clock_t begin = clock();
	insertion_sort(my_array, n);
	clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("time spent: %f\n", time_spent);
	
	counter -= 1;
	
	//merge sort
	printf("merge sort\n");
	clock_t merge_begin = clock();
	merge_sort(my_array, 0, n);
	clock_t merge_end = clock();
	double merge_spent = (double)(merge_end - merge_begin)/CLOCKS_PER_SEC;
	printf("time spent: %f\n", merge_spent);
	
	printf("\n");
	
	//bubble sort
	printf("bubble sort\n");
	clock_t bubble_begin = clock();
	bubble_sort(my_array, n);
	clock_t bubble_end = clock();
	double bubble_spent = (double)(bubble_end - bubble_begin)/CLOCKS_PER_SEC;
	printf("time spent: %f\n", bubble_spent);
	
	printf("\n");
	
	//heap sort
	printf("heap sort\n");
	clock_t heap_begin = clock();
	heap_sort(my_array, n);
	clock_t heap_end = clock();
	double heap_spent = (double)(heap_end - heap_begin)/CLOCKS_PER_SEC;
	printf("time spent: %f\n", heap_spent);
	*/
	//quicksort
	printf("quicksort\n");
	clock_t quicksort_begin = clock();
	randomized_quicksort(my_array, 0, n);
	clock_t quicksort_end = clock();
	double quicksort_spent = (double)(quicksort_end - quicksort_begin)/CLOCKS_PER_SEC;
	printf("time spent: %f\n", quicksort_spent);
	
	
	
	
	
	fclose(f);	
	return 0;
}