#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int val ;
    struct stack * bottom;
    char * ch ;
};

void postPush(struct stack ** aStack, int value ){
    if ( *aStack == NULL ){
        *aStack = (struct stack * ) malloc(sizeof(struct stack)) ;
        (*aStack)->val = value ;
        (*aStack)->bottom = NULL ;
        printf("Created a node and added Value %d\n",(*aStack)->val);
    }
    else{
        struct stack * tmp = (struct stack *)malloc(sizeof(struct stack));
        tmp->bottom = (*aStack );
        tmp->val = value ;
        *aStack= tmp;
    }
}
int postPop(struct stack ** stack){
    if ( *stack == NULL ){
        printf("None in stack\n");
        return 0;
    }
    else{
        struct stack * bottom = (*stack)->bottom;
        bottom = ((*stack)->bottom);
        free(*stack);
        *stack = bottom;
        return (*stack)->val ;
    }
}
void printStack(struct stack ** stack ){
    if ( *stack == NULL ){
        printf("None in stack\n");
        return ;
    }
    printf("val: %d\n",(*stack)->val);
    printStack(&((*stack)->bottom));
}
int main(){
    struct stack ** astack = (struct stack **) malloc(sizeof(struct stack * ));
    *astack = NULL ;
    postPush(astack,10);
    postPush(astack,20);
    postPush(astack,30);
    postPush(astack,50);
    postPush(astack,23);
    postPush(astack,25);
    printf("Popped: %d\n",postPop((astack)));
    printf("Popped: %d\n",postPop((astack)));
    printf("Popped: %d\n",postPop((astack)));
    printf("Popped: %d\n",postPop((astack)));
    printf("Popped: %d\n",postPop((astack)));
    free(*astack);
    return 0 ;
}