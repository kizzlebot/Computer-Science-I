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
            if ( nodePtr->data % 3 == 1 ){
                printf("%d",nodePtr->data+2);
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




int main(){
    struct treeNode * treeNode1 = (struct treeNode *)malloc(sizeof(struct treeNode));
    treeNode1->data = 50 ;
    prob3(treeNode1);

    return 0 ;
}

