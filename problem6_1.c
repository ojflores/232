#include <stdio.h>
#include <stdlib.h>
#define MIN -1

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

void build_max_heap2(int arr[], int heap_length){
	int heap_size = 1;
	int i;
	for(i = 2; i <= heap_length;  i++){
		max_heap_insert(arr, arr[i], heap_size);
	}
}

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
	//makes sure the largest is always in the position of i
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

void print_array(int arr[], int counter){
	int c;
	counter += 1;
	for (c = 0; c < counter; c++){
		printf("%d\n", arr[c]);
	}
}

void main(){
	int array[20] = {1, 2, 3, 4, 5, 6};
	int counter = 5;
	
	build_max_heap(array, counter);
	print_array(array, counter);
	
	printf("\n");
	
	int array2[20] = {1, 2, 3, 4, 5, 6};
	build_max_heap2(array2, counter);
	print_array(array2, counter);
}