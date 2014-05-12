#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked.h"

struct linked * createNode(int val ){
    struct linked * ll = (struct linked * ) malloc(sizeof(struct linked));
    ll->next = NULL ;
    ll->data = val ;
    return ll ;
}
struct linked * insertFront(struct linked * head,int val ){
    if ( head != NULL ){
        struct linked * newHead = createNode(val);
        newHead->next =  head ;
        return newHead ;
    }
    else{
        head = createNode(val);
        head->next = NULL ;
        return head ;
    }
}

void insertBack(struct linked * head,int val ){
    if ( head->next == NULL ){
        head->next = createNode(val);
    }
    else{
        insertBack(head->next,val);
    }
}
void backInsert(struct linked * head , int value ){
    struct linked * tmp = head ;
    while ( tmp->next != NULL ){
        tmp=tmp->next ;
    }
    tmp->next = createNode(value);
}
struct linked * reverse(struct linked * front ){
    struct linked * ll;
    if ( front == NULL || front->next == NULL ){
        return front ;
    }
    ll = reverse(front->next);

    front->next->next = front ;

    front->next = NULL ;

    return ll ;
}
void printAll(struct linked * head){
    if ( head != NULL ){
        printf("%d ",head->data);
        printAll(head->next);
    }
    else{
        printf("\n");
    }
}
void printIter(struct linked * head){
    struct linked * tmp = head ;
    while ( tmp != NULL ){
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");

}
void makeCircular(struct linked * head){
    struct linked * tmp = head ; ;
    while ( tmp->next != NULL ){
       tmp=tmp->next;
    }
    tmp->next = head ;

}

void printCircular(struct linked * head){
    struct linked * tmp = head;
    int i = 0 ;
    do{
        printf("%d ",tmp->data);
        tmp=tmp->next;
        if ( tmp->next == head ) i++ ;
    }
    while ( tmp != head );
}
struct linked * addBetween(struct linked * afterHere,  struct linked * beforeHere , int value ){

    struct linked * tmp = createNode(value);
    tmp->next = beforeHere ;
    afterHere->next = tmp ;
    return afterHere ;
}

struct linked * addSorted(struct linked * head, int value ){
    struct linked * tmp = head ;
    while ( tmp!= NULL && tmp->next != NULL ){
        if ( tmp->data < value && tmp->next->data > value ){
                tmp = addBetween(tmp,tmp->next,value);
                break;
        }
            tmp=tmp->next ;
    }
        return head ;
}