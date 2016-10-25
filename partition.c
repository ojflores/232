#include <stdio.h>
#include <stdlib.h>
#define MAX 40
#define INPUT "input.txt"


void quicksort(){
	
}

void partition(){
	
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
	
	
	
}