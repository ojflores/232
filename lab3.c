#include <stdio.h>
#include <stdlib.h>
#define INPUT "input.txt"
#define MAX 20000
#define MIN -20000

void max_heapify(int arr[], int i, int counter){
	//uses a counter to know how big the array is
	//l and r represent left and right node respectively
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
		//switches to put the largest at the bottom
		max_heapify(arr, largest, counter);
	}
}

void build_max_heap(int arr[], int counter){
	int heap_size = counter;
	int i;
	//
	for (i = heap_size/2; i >= 0; i--){
		max_heapify(arr, i, counter);
	}
}

void heap_sort(int arr[], int counter){
	//initialization
	build_max_heap(arr, counter);
	int i, temp;
	for (i = counter; i >= 0; i--){
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		counter -= 1;
		max_heapify(arr, 0, counter);
		//maintenance
	}
	//termination
}

int heap_extract_max(int arr[], int heap_size){
	
	if (heap_size < 1){
		printf("heap underflow");
		exit(0);
	}
	int max = arr[0];
	arr[0] = arr[heap_size];
	heap_size -= 1;
	max_heapify(arr, 0, heap_size);
	return max;
}

void heap_increase_key(int arr[], int i, int key){
	if(key < arr[i]){
		printf("the key is smaller than the current key");
		exit(0);
	}
	arr[i] = key;
	int temp;
	while(i > 1 && arr[i/2] < arr[i]){
		temp = arr[i];
		arr[i] = arr[i/2];
		arr[i/2] = temp;
		i = i / 2;
	}
}

void max_heap_insert(int arr[], int key, int heap_size){
	heap_size += 1;
	arr[heap_size] = MIN;
	heap_increase_key(arr, heap_size, key);
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
	
	//seperated for readability
	heap_sort(a, counter);
	print_array(a, counter);
	printf("\n");
	
	printf("heap extract max: \n");
	printf("%d\n", heap_extract_max(a, counter));
	
	printf("\n");
	
	printf("max heap insert\n");
	max_heap_insert(a, 3, counter);
	print_array(a, counter);
	fclose(f);
}
