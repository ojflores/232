#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
#define INPUT "input.txt"

void insertion_sort(int a[], int counter){
	int j, i, key;			
	//initialization: j == 1, A[] only holds one sorted item in A[0]
	//"j" starts at one as opposed to 0 because the first number is already sorted when by itself
	for (j = 1; j < counter; j++){
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key){
			a[i+1] = a[i];
			i -= 1;
		}
		a[i+1] = key;
		//maintenance: for loop moves by A[j-1] until correct place is found
	}
	//termination: j>A.length and everything is in its rightful place
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
	
	fclose(f);	
	return 0;
}


