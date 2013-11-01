#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 20
#define MIN -1
struct stack {
    int stk[MAX];
    int top ;
};

void init(struct stack * stak);
void printStack(int index , struct stack * stak);
int push(struct stack * stak, int val );
int pop(struct stack * stak );
int top(struct stack * stak);
int flush(struct stack * stak );
int empty(struct stack * stack);
int full(struct stack * stack);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    struct stack myStack ;
    init(&myStack);
    srand(time(NULL)) ;
    int i = rand()%100 ;
    i = 0;
    while (!full(&myStack)){
        push(&myStack,i);
        i++ ;
    }
    printStack(myStack.top,&myStack);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init(struct stack * stak){
    stak->top = -1 ;
}
int push(struct stack * stak, int val ){
    if (full(stak)){
        return 0;
    }
    else{
        stak->stk[stak->top];
        stak->top++;
        return 1 ;
    }
}
int pop(struct stack * stak ){
    if (stak ){
        int retn = stak->stk[stak->top];
        stak->stk[stak->top] = -1 ;
        stak->top-- ;
        return retn;
    }
    else{
        return -1 ;
    }
}
int top(struct stack * stak){
    if (!empty(stak)) return stak->stk[stak->top] ;
    else return -1 ;
}
int flush(struct stack * stak ){
    if (!empty(stak)){
        int p = stak->top ;
        stak->top-- ;
        flush(stak);
        stak->stk[p] = -1 ;
    }
    return empty(stak) ;
}
int empty(struct stack * stak){
    if ( stak->top == MIN ){
        return 1 ;
    }
    else{
        return 0 ;
    }
}
int full(struct stack * stack){
    if (stack->top+1 == MAX ){
        return 1 ;
    }
    else{
        return 0 ;
    }
}
void printStack(int index , struct stack * stak){
    if ( index == MIN ){
        return ;
    }
    else{
        printf("%d\n ",stak->stk[index]);
        printStack(index-1,stak);
    }
}
