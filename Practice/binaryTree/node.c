#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data ;
    struct node * left ;
    struct node * right ;
};
struct stack{
    int val ;
    struct stack * bottom;
};

void postPush(struct stack ** aStack, int val ){
    if ( *aStack == NULL ){
        struct stack * tempstack = (struct stack * ) malloc(sizeof(struct stack)) ;
        tempstack->val = val ;
        *(*aStack)= *tempstack ;
        printf("Created a node and added Value %d\n",(*aStack)->val);
    }
    else{
        struct stack * tmpStack = (struct stack *)malloc(sizeof(struct stack));
        tmpStack->val = val ;
        tmpStack->bottom = (*aStack);
        **aStack = *tmpStack;
    }
}
struct stack * postPop(struct stack ** stack){
    if ( *stack != NULL ){
        struct stack * top = *stack;
        *stack = (*stack)->bottom ; // Swap vals not addresses b/c the change wont stick outside funtion
        top->bottom = NULL ;
        return *stack ;
    }
    else{
        return NULL ;
    }
}
void printStack(struct stack * stack ){
    if ( stack == NULL ){
        return ;
    }
    printf("val: %d\n",stack->val);
    printStack(stack->bottom);
}

/*-----------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
struct node * createNode( int data ){
    struct node * node = (struct node * )malloc(sizeof(struct node ));
    node->left = NULL ;
    node->right = NULL ;
    node->data = data ;
    return node ;
}
void inorder(struct node *current_ptr) {

  // Only traverse the node if it's not null.
  if (current_ptr != NULL) {
    inorder(current_ptr->left); // Go Left.
    printf("%d ", current_ptr->data); // Print the root.
    inorder(current_ptr->right); // Go Right.
  }
}

struct node * insert(struct node * root , struct node * toAdd ){
    if ( root == NULL ){
        return toAdd ;
    }

    else{
        if ( root->data < toAdd->data ){
            if ( root->left != NULL ){
                root->left = insert(root->left,toAdd);
            }
            else{
                root->left = toAdd;
            }
        }
        else {
            if ( root->right != NULL ){
                    root->right= insert(root->right ,toAdd);
            }
            else{
                root->right = toAdd;
            }
        }
    }
    return root ;
}



int main(){
    struct stack ** aStack ;
    *aStack = NULL ;
    int i = 0 ;
    postPush(aStack,5*5);
    return 0 ;
}