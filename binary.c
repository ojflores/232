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

//maximum and minimum functions for exercise 12.2-2; all four of them
node_t * maximum(node_t * x){
	//do this so that the original pointer doesn't change
	node_t * temp = x;
	while (temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

node_t * recursive_max(node_t * x){
	node_t * temp = x;
	if (temp->right != NULL){
		return recursive_max(temp->right);
	}
	return temp;
}

node_t * minimum(node_t * x){
	node_t * temp = x;
	while (temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

node_t * recursive_min(node_t * x){
	node_t * temp = x;
	if (temp->left != NULL){
		return recursive_min(temp);
	}
	return temp;
} 

void transplant(node_t * T, node_t * u, node_t * v){
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



node_t * tree_search(node_t * x, int k){
	if (x == NULL || k == x->val){
		return x;
	}
	if (k < x->val){
		return tree_search(x->left, k);
	}
	else {
		return tree_search(x->right, k);
	}
}

node_t * iterative_search(node_t * x, int k){
	while (x != NULL && k != x->val){
		if (k < x->val){
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}

void delete(int x)
{
	printf("delete!\n");
	node_t * z = iterative_search(list, x);
	if (z->left == NULL){
		transplant(list, z, z->right);
	}
	else if (z->right == NULL){
		transplant(list, z, z->left);
	}
	else {
		node_t * y = recursive_min(z->right);
		if (y->parent != z){
			transplant(list, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(list, z, y);
		y->left = z->left;
		y->left->parent = y;
	} 
}
/*
got delete to work alongside transplant
all that's left is writing the other things to do with the lab: delete, insert, and search are finished
*/

void search(int k){
	printf("search -- ");
	node_t * x = list;
	iterative_search(x, k);
	if (iterative_search(x, k)){
		printf("found\n");
	}
	else {
		printf("not found\n");
	}
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
	
}
