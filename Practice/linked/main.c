#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked.h"

int main(){
    struct linked *  head = NULL ;
    int i = 90;
    head = insertFront(head,i*3);
    insertBack(head,90);
    insertBack(head,91);
    insertBack(head,92);
    insertBack(head,93);
    head = addSorted(head,23);
    printAll(head);
    printIter(head);
    return 0 ;
}
