#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node  * alloc(int val) {
  // Allocate space for the node, set the fields.
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node ));
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp; // Return a pointer to the created node.
}

struct node * insert(struct node *root, struct node *element) {

  // Inserting into an empty tree.
  if (root == NULL) return element;
  else {
    // element should be inserted to the right.
    if (element->data > root->data) {
      // There is a right subtree to insert the node.
      if (root->right != NULL) root->right = insert(root->right, element);
      // Place the node directly to the right of root.
      else root->right = element;
    }

    // element should be inserted to the left.
    else {
      // There is a left subtree to insert the node.
      if (root->left != NULL) root->left = insert(root->left, element);
      // Place the node directly to the left of root.
      else root->left = element;
    }
    // Return the root pointer of the updated tree.
    return root;
  }
}
void printT(struct node * root ){
    if ( root != NULL ){
        printT(root->left);
        printf("%d ",root->data);
        printT(root->right);
    }
}
int main(){
    struct node * root = NULL ;
    root = insert(root,alloc(0));
    root = insert(root,alloc(1));
    root = insert(root,alloc(2));
    root = insert(root,alloc(3));
    root = insert(root,alloc(4));
    root = insert(root,alloc(5));
    root = insert(root,alloc(6));
    root = insert(root,alloc(7));
    root = insert(root,alloc(8));
    root = insert(root,alloc(9));
    root = insert(root,alloc(10));
    printT(root);
}
