#include <stdio.h>
#include <stdlib.h>
#define MAX 200

merge(int arr[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[15];
	int R[15];
	int i;
	int j;
	for(i = 1; i <= n1; i++){
		L[i] = arr[p + i - 1];
	}
	for(j = 1; j <= n2; j++){
		R[j] = arr[q + j];
	}
	L[n1 + 1] = MAX;
	R[n2 + 1] = MAX;
	i = 1;
	j = 1;
	int k;
	for(k = p; k <= r; k++){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i += 1;
		}
		else {
			arr[k] = R[j];
			j +=1;
		}
	}
	
}





print_array(int arr[], int counter){	//test to see if array can be passed
	int c;
	for (c = 0; c < counter; c++){
		printf("%d\n", arr[c]);
	}
}

merge_sort(int arr[], int p, int r){
	int q;
	if(p < r) {
		q = (p + r)/2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
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
	
	merge_sort(a, 0, counter - 1);
	print_array(a, counter);
	
	
}