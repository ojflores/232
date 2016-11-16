#include <stdio.h>
#include <stdlib.h>

#define PLUS insert
#define MINUS delete
#define SEARCH search

typedef struct node{
	int val;
	struct node * left;
	struct node * right;
	struct node * parent;
}node_t;
node_t * list = NULL;

node_t * tree_search(node_t * x, int k){
	if (x == NULL || k == list->val){
		return x;
	}
	if (k < x->val){
		return tree_search(x->left, k);
	}
	else {
		return tree_search(x->right, k);
	}
}

void transplant(node_t * u, node_t * v){
	if(u->parent == NULL){
		list = v;
	}
	else if (u == u->parent->left){
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	if (v != NULL){
		v->parent = u->parent;
	}
}

void insert(int z)
{
	node_t * z_node = malloc(sizeof(node_t));
	z_node->val = z;
	node_t * y = NULL;
	node_t * x = list;
	while (x != NULL){
		y = x;
		if (z < x->val){
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z_node->parent = y;
	if (y == NULL){
		list = z_node; 
	}
	
	else if (z < y->val){
		y->left = z_node;
	}
	else {
		y->right = z_node;
	}
	
	printf("push \n");
}

int delete()
{
	printf("pop!\n");
	return(1);
}

void search(){
	printf("search\n");
}

void print_data(node_t * list)
{
	
	if (list == NULL){
		return;
	}
	//prints things in order
	print_data(list->left);
	printf("%d\n", list->val);
	print_data(list->right);
	
	
}
// end definitions


// Leave this alone:
#include "datastruct.h"
int main()
{
	parse_exec();
	print_data(list);
	tree_search(list, 10);
}