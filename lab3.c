#include <stdio.h>
#include <stdlib.h>
#define INPUT "input.txt"
#define MAX 20000

void max_heapify(int arr[], int i, int counter){
	int l = 2 * i;	//this is l as in lamb, not the number
	int r = (2 * i) + 1;
	int largest, temp;
	if (l <= counter && arr[l] > arr[i]){
		largest = l;
	}
	else {
		largest = i;
	}
	if (r <= counter && arr[r] > arr[largest]){
		largest = r;
	}
	if (largest != i){
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr, largest, counter);
	}
}

void build_max_heap(int arr[], int counter){
	int heap_size = counter;
	int i;
	for (i = heap_size/2; i > 0; i--){
		max_heapify(arr, i, counter);
	}
}

void heap_sort(int arr[], int counter){
	build_max_heap(arr, counter);
	int i, temp;
	for (i = counter; i >= 1; i--){
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		counter -= 1;
		max_heapify(arr, 0, counter);
		
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
	
	heap_sort(a, counter);
	
	
	int c;
	for (c = 0; c < counter; c++){
		printf("%d\n", a[c]);
	}
	
}


//my name is oscar