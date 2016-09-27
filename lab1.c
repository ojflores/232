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
	
	int i = 0;
	
	while ((read = getline(&line, &len, f)) != -1) {
		a[i] = atoi(line);
		i += 1;
	}
	int j;
	for (j = 0; j < i; j++){
		printf("%d\n", a[j]);
	}
	
	
	
	
	//int number_of_numbers[6];
	//fscanf(f, "%d", &number);
	
	
	
	
	
	
	return 0;
	
}