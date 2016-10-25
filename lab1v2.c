#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
#define INPUT "input.txt"

void insertion_sort(int a[], int counter){
	int j, i, key;			
	//initialization
	//"j" starts at one as opposed to 0 because the first number is already sorted when by itself
	for (j = 1; j < counter; j++){
		key = a[j];
		i = j - 1;
		//
		while (i >= 0 && a[i] > key){
			a[i+1] = a[i];
			i -= 1;
		}
		a[i+1] = key;
		//maintenance
	}
	//termination
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
	printf("test from input file: \n");
	insertion_sort(a, counter);
	//i, n are used below for the timed test
	int c, i, n;
	for (c = 0; c < counter; c++){
		printf("%d\n", a[c]);
	}
	
	printf("now the timed test: \n");
	
	//creating a list of random to time how long it takes for it to run
	int array[MAX];
	n = MAX;
	for (i = 0; i < n; i++){
		array[i] = rand() % MAX;
	}
	
	
	clock_t begin = clock();
	
	insertion_sort(array, n);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("time spent: %f\n", time_spent);
	
	
	
	fclose(f);	
	return 0;
}
