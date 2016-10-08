#include <stdio.h>
#include <stdlib.h>
#define MAX 20

bubble_sort(int arr[], int counter){
	
	
	
	int i;
	int j;
	int key;
	for(i = 0; i <= (counter - 1); i++){
		for(j = counter; j >= (i + 1); j--){
			key = arr[j];
			if(arr[j] < arr[j - 1]){
				arr[j] = arr[j - 1];
				arr[j - 1] = key;
			}
		}
	}
	
}


print_array(int arr[], int counter){	//test to see if array can be passed
	int c;
	for (c = 0; c < counter; c++){
		printf("%d\n", arr[c]);
	}
}

main(){
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int a[MAX];
	FILE *f = fopen("file.txt", "r");
	
	int counter = 0;
	
	//next 3 lines found at http://man7.org/linux/man-pages/man3/getline.3.html
	//thing that was fixed/added
	while ((read = getline(&line, &len, f)) != -1) {
		a[counter] = atoi(line);
		counter += 1;
	}
	
	bubble_sort(a, counter - 2);
	print_array(a, counter);
}