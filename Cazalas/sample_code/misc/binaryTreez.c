#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct treeNode{
    int data ;
    struct treeNode * left;
    struct treeNode * right;
} ;


void prob3(struct treeNode * nodePtr ){
    if (nodePtr != NULL ){
        if (nodePtr->data %3 == 0 ){
            printf("%d",nodePtr->data);
            prob3(nodePtr->left);
        }
        else{
            if ( nodePtr->data % 2 == 0 ){
                printf("%d",nodePtr->data+2);
            }
        }
    }
}
int main(){
    struct treeNode * treeNode1 = (treeNode *)malloc(sizeof(treeNode));

    return 0 ;
}

