#include <stdio.h>
#include <stdlib.h>
struct node{
	int val ;
	struct node * left ;
	struct node * right ;
};


struct node * insert(struct node * root, struct node * element){
	if ( root == NULL ){
		return element ;
	}
	else{
		if ( element->val > root->val ){
			if ( root->right != NULL ){
				root->right = insert(root->right,element);
			}
			else{
				root->right = element ;
			}
		}
		else if ( element->val == root->val ){
			root->val = element->val ;
		}
		else{
			if ( root->left != NULL ){
				root->left = insert(root->left, element);
			}
			else{
				root->left = element ;
			}
		}
		return root ;
	}
}

struct node * create_node(int val){
	struct node * new = (struct node * ) malloc(sizeof(struct node));
	new->val = val ;
	new->left = NULL ;
	new->right = NULL ;
	return new ;
}
struct node * snip(struct node ** root,struct node * target){
	struct node * hlpr;
	if ( root!=NULL ){
		if (*root==target){
			struct node * hlpr = *root ;
			*root=(*root)->left;
		}
	}
	return hlpr;
}
void printTree(struct node * tree){
	if ( tree != NULL ){
		printTree(tree->left);
		printf("%d ",tree->val);
		printTree(tree->right);
	}
}
int main(){
	struct node * root = create_node(5);
	root = insert(root,create_node(20));
	root = insert(root,create_node(40));
	root = insert(root,create_node(50));
	root = insert(root,create_node(40));
	root = insert(root,create_node(40));
	printTree(root);
}