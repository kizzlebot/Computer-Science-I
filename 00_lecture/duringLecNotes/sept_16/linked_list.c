#include <stdio.h>
#include <stdlib.h>

struct Node{
    int aNumber ;
    struct Node * next ;
} ;

struct Node * allocateNumLinked(struct Node * aNode ,struct Node * head ,int n , int numToAlloc){
    aNode->aNumber = n ;
    if ( n == numToAlloc){
        aNode->next = NULL ;
        return aNode ;
    }
    else {
        allocateNumLinked(aNode,n+1,numToAlloc);
    }

}
int countNodes(struct Node * aNode){
    int i = 0 ;
    while ( aNode->next+i != NULL ){
       i++ ;
    }
    return i ;
}

int main(){
    struct Node * myNode = allocateNumLinked( (struct Node *)malloc(sizeof(struct Node)),(struct Node *)NULL,0,20) ;
    struct Node * head = myNode->next-myNode->aNumber+1;
    printf("Size of nodes:%d",head->aNumber );
    //printf("Size of nodes:%d",myNode->next->aNumber);
    //printf("Size of nodes:%d",myNode->next->next->aNumber);
}