#include <stdio.h>

#define PLUS insert
#define MINUS pop
#define SEARCH search
#define MAX 5


int T[MAX];

//hashing using division
int division(int k){
	return k % MAX;
}
int hash(int k, int i){
	return (multi(k) + i) % MAX;
}



//hashing using multiplication
int multi(int k){
	float A = 0.618034;
	float first = (k * A) - (int)(k * A);
	int r_val = (int)(MAX * first);
	return r_val;
}

int search(int k){
	printf("search: %d\n", k);
	int i, j;
	for (i = 0; i < MAX;){
		j = hash(k, i);
		if (T[j] == k){
			printf("found it\n");
			return j;
		}
		i++;
	}
	printf("not here\n");
	return 0;
}

int insert(int val)
{
	printf("insert: %d\n", val);
	int i, j;
	
	for (i = 0; i < MAX; i++){
	
		printf("%d, ", hash(val, i));
	}
	printf("\n");
	for (i = 0; i < MAX;){
		j = hash(val, i);
		if (T[j] == 0){
			T[j] = val;
			return j;
		}
		else{
			i++;
			printf("%d\n", i);
		}
	}
	printf("error: hash table overflow");	
	return 1;
}

int pop()
{
	printf("pop!\n");
	return(1);
}
void print_datastructure()
{
	int i;
	for (i = 0; i < MAX; i++){
		printf("%d\n", T[i]);
	}
}
// end definitions


// Leave this alone:
#include "datastruct.h"
int main()
{
	parse_exec();
	print_datastructure();
}
