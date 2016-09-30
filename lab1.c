#include <stdio.h>
#include <stdlib.h>
#define MAX 20


int main()
{
	
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
	int c;
	//for (c = 0; c < i; c++){
	//	printf("%d\n", a[c]);}
	
	int j;		//j
	int key;
	int i;				//i
	for (j = 1; j < counter; j++){
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key){
			a[i+1] = a[i];
			i -= 1;
		}
		a[i+1] = key;
	}
	
	for (c = 0; c < counter; c++){
		printf("%d\n", a[c]);
	}
		
	return 0;
	
}