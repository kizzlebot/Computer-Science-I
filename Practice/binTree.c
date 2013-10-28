#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree {
    int data ;
    struct tree * left ;
    struct tree * right ;
};
typedef struct tree node ;

void insert (node ** root, node * ins);
node * alloc(int val );
void printInOrder(node * root);
int main(){
    node * tree = alloc(5);
    insert(&tree,alloc(5));
    insert(&tree,alloc(6));
    insert(&tree,alloc(8));
    insert(&tree,alloc(9));
    insert(&tree,alloc(1));
    insert(&tree,alloc(0));
    insert(&tree,alloc(2));
    insert(&tree,alloc(4));
    printInOrder(tree);
    printf("\n");
}
node * alloc(int val ){
    node * rtn = (node *) malloc(sizeof(node));
    rtn->data = val ;
    return rtn;
}
void printInOrder(node * root){
    if ( root != NULL ){
        printInOrder(root->left);
        printf("%d ",root->data);
        printInOrder(root->right);
    }
}
void insert (node ** root, node * ins){
    // if root is null
    if ( *root == NULL ){
        *root = ins ;
        return ;
    }
    if ( (*root)->data > ins->data) insert(&((*root)->left), ins);
    else insert(&((*root)->right), ins);
}

