// Arup Guha
// 6/20/07
// Written in COP 3502 to illustrate an array implementation of a stack.

#include <stdio.h>

// The array will store the items in the stack, first in
// index 0, then 1, etc. top will represent the index
// to the top element in the stack. If the stack is 
// empty top will be -1.

#define SIZE 10
#define EMPTY -1

struct stack {

    int items[SIZE];
    int top;   
};

void initialize(struct stack* stackPtr){
	stackPtr->top=-1;
}
int full(struct stack* stackPtr){
	return stackPtr->top==SIZE-1;
}
int push(struct stack* stackPtr, int value){
	if (!full(stackPtr)) {
		stackPtr->items[stackPtr->top+1]=value;
		stackPtr->top++; 
		return 1 ; 
	}
	else{
		return 0 ;
	}
}
int empty(struct stack* stackPtr){
	return stackPtr->top==SIZE-1;
}
int pop(struct stack* stackPtr){
	
}
int top(struct stack* stackPtr);

int main() {
    int i;
    struct stack mine;

    // Set up the stack and push a couple items, then pop one.
    initialize(&mine);
    push(&mine, 4);
    push(&mine, 5);
    printf("Popping %d\n", pop(&mine));
    
    // Push a couple more and test top.
    push(&mine, 22);
    push(&mine, 16);
    printf("At top now = %d\n", top(&mine));
    
    // Pop all three off.
    printf("Popping %d\n", pop(&mine));
    printf("Popping %d\n", pop(&mine));
    printf("Popping %d\n", pop(&mine));
    
    // Checking the empty function.
    if (empty(&mine))
        printf("The stack is empty as expected.\n");
        
    // Fill the stack.
    for (i = 0; i<10; i++)
        push(&mine, i);
    
    // Check if full works.
    if (full(&mine))
        printf("This stack is full as expected.\n");
    
    // Pop everything back off.
    for (i = 0; i<10; i++)
        printf("popping %d\n",pop(&mine));
        
    system("PAUSE");
    return 0;
}


