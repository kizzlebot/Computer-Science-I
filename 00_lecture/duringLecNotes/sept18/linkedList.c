#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ll {
   int data ;
   struct ll * next ;
};

struct ll * insertFront(struct ll * front , int value ){
    struct ll * temp = (struct ll *)malloc(sizeof(struct ll ));
    temp->data = value ;
    temp->next = front ;
    return temp ;
}
struct ll * insertEnd(struct ll * front, int value ){
    if ( front == NULL ){
        front = (struct ll *)malloc(sizeof(struct ll));
        front->data = value ;
        return front ;
    }
    else {
        front->next= insertEnd(front->next,value);
        return front ;
    }
}
int main(){
    struct  ll * list = NULL ;
    list = insertFront(list,0);
    list = insertFront(list,1);
    list = insertFront(list,2);
    list = insertFront(list,3);
    list = insertFront(list,4);
    list = insertFront(list,5);
    insertEnd(list,6);
    insertEnd(list,7);
    printf("INsertfront %d\n",list->data);
    printf("%d\n",list->data);
    printf("%d\n",list->next->data);
    printf("%d\n",list->next->next->data);
    printf("%d\n",list->next->next->next->data);
    printf("%d\n",list->next->next->next->next->data);
    printf("%d\n",list->next->next->next->next->next->data);
    printf("%d\n",list->next->next->next->next->next->next->data);
    printf("%d\n",list->next->next->next->next->next->next->next->data);
    return 0 ;
}