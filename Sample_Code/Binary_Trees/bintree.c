// Arup Guha
// 3/25/04, with code added to do delete on 3/30/04
// COP 3502 Lecture: Some Binary Tree Functions
#include <stdio.h>
#include <stdlib.h>
struct tree_node {
  int data;
  struct tree_node *left;
  struct tree_node *right;
};


void prob3(struct tree_node * nodePtr ){
    if (nodePtr != NULL ){
        if (nodePtr->data %3 == 0 ){
            printf(" %d\n",nodePtr->data);
            prob3(nodePtr->left);
        }
        else{
            if ( nodePtr->data % 3 == 1 ){
                printf("%d\n",nodePtr->data+2);
                prob3(nodePtr->right);
            }
            else{
                if ( nodePtr->data % 3 == 2 ){
                    prob3(nodePtr->left);
                    prob3(nodePtr->right);
                }
            }
        }
    }
}
void modifyT(struct tree_node * node_ptr , int key , int num ){
    if (node_ptr != NULL ){
        if ( node_ptr->data % 3 == 0 ){
            node_ptr->data +=key ;
            modifyT(node_ptr->left, key+2, num - key);
            modifyT(node_ptr->right, key-3, num+key);
        }
        else if ( node_ptr->data%5 == 0 ){
            node_ptr->data  -= key ;
            modifyT(node_ptr->right, key - 4, num);
            modifyT(node_ptr->left, key, num + 5);
        }

        else{
            node_ptr->data = num;
            modifyT(node_ptr->right, key - 2, num + 10);
            modifyT(node_ptr->left, key + 5, num - 7);
        }

    }
}
struct tree_node *create_node(int val);
void inorder(struct tree_node *current_ptr);
struct tree_node* insert(struct tree_node *root,
                         struct tree_node *element);
int add(struct tree_node *current_ptr);

int find(struct tree_node *current_ptr, int val);

struct tree_node* parent(struct tree_node *root, struct tree_node *node);
struct tree_node* minVal(struct tree_node *root);
struct tree_node* maxVal(struct tree_node *root);
int isLeaf(struct tree_node *node);
int hasOnlyLeftChild(struct tree_node *node);
int hasOnlyRightChild(struct tree_node *node);
struct tree_node* findNode(struct tree_node *current_ptr, int value);
struct tree_node* delete(struct tree_node* root, int value);

int menu();

int main() {

  struct tree_node *my_root=NULL, *temp_node;
  int done = 0,ans=1, val;
  // Create the node.

  // Insert the value.
      my_root = insert(my_root, create_node(55));
      my_root = insert(my_root, create_node(27));
      my_root = insert(my_root, create_node(60));
      my_root = insert(my_root, create_node(17));
      my_root = insert(my_root, create_node(38));
      my_root = insert(my_root, create_node(91));
      my_root = insert(my_root, create_node(21));
      my_root = insert(my_root, create_node(72));
    inorder(my_root);
    printf("\n");
    modifyT(my_root,7,65);
    inorder(my_root);
  return 0;
}

void inorder(struct tree_node *current_ptr) {

  // Only traverse the node if it's not null.
  if (current_ptr != NULL) {
    inorder(current_ptr->left); // Go Left.
    printf("%d ", current_ptr->data); // Print the root.
    inorder(current_ptr->right); // Go Right.
  }
}

struct tree_node* insert(struct tree_node *root,
                         struct tree_node *element) {

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

struct tree_node* create_node(int val) {

  // Allocate space for the node, set the fields.
  struct tree_node* temp;
  temp = (struct tree_node*)malloc(sizeof(struct tree_node));
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp; // Return a pointer to the created node.
}

int find(struct tree_node *current_ptr, int val) {

  // Check if there are nodes in the tree.
  if (current_ptr != NULL) {

    // Found the value at the root.
    if (current_ptr->data == val)
      return 1;

    // Search to the left.
    if (val < current_ptr->data)
      return find(current_ptr->left, val);

    // Or...search to the right.
    else
      return find(current_ptr->right, val);

  }
  else
    return 0;
}

int add(struct tree_node *current_ptr) {

  if (current_ptr != NULL)
    return current_ptr->data+add(current_ptr->left)+
           add(current_ptr->right);
  else
    return 0;
}

// Returns the parent of the node pointed to by node in the tree rooted at
// root. If the node is the root of the tree, or the node doesn't exist in
// the tree, null will be returned.
struct tree_node* parent(struct tree_node *root, struct tree_node *node) {

  // Take care of NULL cases.
  if (root == NULL || root == node)
    return NULL;

  // The root is the direct parent of node.
  if (root->left == node || root->right == node)
    return root;

  // Look for node's parent in the left side of the tree.
  if (node->data < root->data)
    return parent(root->left, node);

  // Look for node's parent in the right side of the tree.
  else if (node->data > root->data)
    return parent(root->right, node);

  return NULL; // Catch any other extraneous cases.

}

// Returns a pointer to the node storing the minimum value in the tree
// with the root, root. Will not work if called with an empty tree.
struct tree_node* minVal(struct tree_node *root) {
  // Root stores the minimal value.
  if (root->left == NULL)
    return root;

  // The left subtree of the root stores the minimal value.
  else
    return minVal(root->left);
}


// Returns a pointer to the node storing the maximum value in the tree
// with the root, root. Will not work if called with an empty tree.
struct tree_node* maxVal(struct tree_node *root) {

  // Root stores the maximal value.
  if (root->right == NULL)
    return root;

  // The right subtree of the root stores the maximal value.
  else
    return maxVal(root->right);
}

// Returns 1 if node is a leaf node, 0 otherwise.
int isLeaf(struct tree_node *node) {
  return (node->left == NULL && node->right == NULL);
}

// Returns 1 iff node has a left child and no right child.
int hasOnlyLeftChild(struct tree_node *node) {
  return (node->left!= NULL && node->right == NULL);
}

// Returns 1 iff node has a right child and no left child.
int hasOnlyRightChild(struct tree_node *node) {
  return (node->left== NULL && node->right != NULL);
}

// Returns a pointer to a node that stores value in it in the subtree
// pointed to by current_ptr. NULL is returned if no such node is found.
struct tree_node* findNode(struct tree_node *current_ptr, int value) {

  // Check if there are nodes in the tree.
  if (current_ptr != NULL) {

    // Found the value at the root.
    if (current_ptr->data == value)
      return current_ptr;

    // Search to the left.
    if (value < current_ptr->data)
      return findNode(current_ptr->left, value);

    // Or...search to the right.
    else
      return findNode(current_ptr->right, value);

  }
  else
    return NULL; // No node found.
}

// Will delete the node storing value in the tree rooted at root. The
// value must be present in the tree in order for this function to work.
// The function returns a pointer to the root of the resulting tree.
struct tree_node* delete(struct tree_node* root, int value) {

  struct tree_node *delnode, *new_del_node, *save_node;
  struct tree_node *par;
  int save_val;

  delnode = findNode(root, value); // Get a pointer to the node to delete.

  par = parent(root, delnode); // Get the parent of this node.

  // Take care of the case where the node to delete is a leaf node.
  if (isLeaf(delnode)) {

    // Deleting the only node in the tree.
    if (par == NULL) {
      free(root); // free the memory for the node.
      return NULL;
    }

    // Deletes the node if it's a left child.
    if (value < par->data) {
      free(par->left); // Free the memory for the node.
      par->left = NULL;
    }

    // Deletes the node if it's a right child.
    else {
      free(par->right); // Free the memory for the node.
      par->right = NULL;
    }

    return root; // Return the root of the new tree.
  }

  // Take care of the case where the node to be deleted only has a left
  // child.
  if (hasOnlyLeftChild(delnode)) {

    // Deleting the root node of the tree.
    if (par == NULL) {
      save_node = delnode->left;
      free(delnode); // Free the node to delete.
      return save_node; // Return the new root node of the resulting tree.
    }

    // Deletes the node if it's a left child.
    if (value < par->data) {
      save_node = par->left; // Save the node to delete.
      par->left = par->left->left; // Readjust the parent pointer.
      free(save_node); // Free the memory for the deleted node.
    }

    // Deletes the node if it's a right child.
    else {
      save_node = par->right; // Save the node to delete.
      par->right = par->right->left; // Readjust the parent pointer.
      free(save_node); // Free the memory for the deleted node.
    }

    return root; // Return the root of the tree after the deletion.
  }

  // Takes care of the case where the deleted node only has a right child.
  if (hasOnlyRightChild(delnode)) {

    // Node to delete is the root node.
    if (par == NULL) {
      save_node = delnode->right;
      free(delnode);
      return save_node;
    }

    // Delete's the node if it is a left child.
    if (value < par->data) {
      save_node = par->left;
      par->left = par->left->right;
      free(save_node);
    }

    // Delete's the node if it is a right child.
    else {
      save_node = par->right;
      par->right = par->right->right;
      free(save_node);
    }
    return root;
  }

  // Find the new physical node to delete.
  new_del_node = minVal(delnode->right);
  save_val = new_del_node->data;

  delete(root, save_val);  // Now, delete the proper value.

  // Restore the data to the original node to be deleted.
  delnode->data = save_val;

  return root;
}

// Prints out the menu of choices for the user and returns their choice.
int menu() {

  int ans;
  printf("Here are your choices.\n");
  printf("1. Insert an item into your tree.\n");
  printf("2. Delete an item from your tree.\n");
  printf("3. Search for an item in your tree.\n");
  printf("4. Print the sum of the nodes in your tree.\n");
  printf("5. Print out an inorder traversal of your tree.\n");
  printf("6. Quit.\n");
  scanf("%d", &ans);
  return ans;
}
