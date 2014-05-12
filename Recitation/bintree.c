#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * left ;
    struct node * right ;
};
struct node * createNode(int val){
    struct node * ret = (struct node *) malloc(sizeof(struct node));
    ret->data = val ;
    ret->left = NULL ;
    ret->right = NULL ;
    return ret ;
}
struct node* insert(struct node *root, struct node *element) {
    // Inserting into an empty tree.
    if (root == NULL)
        return element;
    else {

        // element should be inserted to the right.
        if (element->data > root->data) {

            // There is a right subtree to insert the node.
            if (root->right != NULL)
                root->right = insert(root->right, element);

            // Place the node directly to the right of root.
            else
                root->right = element;
        }

        // element should be inserted to the left.
        else {

            // There is a left subtree to insert the node.
            if (root->left != NULL)
                root->left = insert(root->left, element);

            // Place the node directly to the left of root.
            else
                root->left = element;
        }

        // Return the root pointer of the updated tree.
        return root;
    }
}


struct node * insertZ(struct node * root , struct node * ins ){
    if ( root == NULL ) return ins ;
    else{
        if ( root->data > ins->data ){
            if (root->right!=NULL){
                root->right = insert(root->right,ins);
            }
            else{
                root->right = ins;
            }
        }
        else{
            if (root->left!=NULL){
                root->left = insert(root->left,ins);
            }
            else{
                root->left = ins;
            }
        }
        return root ;
    }
}
int main(){
    struct node * root ;
    root = insert(root,createNode(5));

}


