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
void avlInsert(node ** root, node * ins, int weight);

node * alloc(int val );
node * avlAlloc(int val );
void printInOrder(node * root);
int evaluate(node * root);
int num_nodes(node * root) {
    if (root == NULL) return 0;
    return 1 + num_nodes(root->left) + num_nodes(root->right);
}

int get_rank(node * root, int k) {

    int numleft = num_nodes(root);/*** Q8 ***/ ;
    if (numleft == k-1){
        return root->data;/*** Q9 ***/;
    }
    else if (numleft > k-1){
        return get_rank(root->left, k);
    }
    else{
        return get_rank(root->right,numleft-k);
    }
}

int main(){
    node * bintree = alloc(5);
    int i = 0 ;
    while ( i != -1 ){
        printf("Enter: ");
        scanf("%d",&i);
        if ( i == -1 ) break;
        insert(&bintree,alloc(i));
//        printInOrder(bintree);
        printf("\n");
        if (i==-2){
            //printf("%d\n",sumTree(bintree));
        }
    }

    printf("Val %d\n",get_rank(bintree,num_nodes(bintree))) ;
    printf("Val %d\n",get_rank(bintree,get_rank(bintree,num_nodes(bintree)))) ;
}
node * alloc(int val ){
    node * rtn = (node *) malloc(sizeof(node));
    rtn->data = val ;
    rtn->left = NULL ;
    rtn->right = NULL ;
    return rtn;
}
void printInOrder(node * root){
    if ( root != NULL ){
        printInOrder(root->left);
        printf("%d ",root->data);
        printInOrder(root->right);
    }
}
int sumTree(node * root ){
    if ( root != NULL ){
        return root->data+sumTree(root->left)+sumTree(root->right);
    }
    else{
        return 0 ;
    }
}
node * avlAlloc(int val ){
    node * rtn = (node *) malloc(sizeof(node));
    rtn->data = val ;
    return rtn;
}
void insert (node ** root, node * ins){
    // if root is null
    if ( *root == NULL ){
        *root = ins ;
        return ;
    }
    if (  ins->data <  (*root)->data ) insert(&((*root)->left), ins);
    else insert(&((*root)->right), ins);

}

