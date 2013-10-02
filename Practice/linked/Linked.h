#ifndef LINKED
#define LINKED

struct linked{
    int data ;
    struct linked * next ;
};

struct linked * createNode(int val );
struct linked * insertFront(struct linked * head,int val );
void insertBack(struct linked * head,int val );
void backInsert(struct linked * head , int value );
struct linked * reverse(struct linked * front );
void insertBack(struct linked * head,int val );
void backInsert(struct linked * head , int value );
struct linked * reverse(struct linked * front );
void printAll(struct linked * head);
void printIter(struct linked * head);
void printCircular(struct linked * head);
void makeCircular(struct linked * head);

struct linked * addBetween(struct linked * afterHere,  struct linked * beforeHere , int value );
struct linked * addSorted(struct linked * head, int value );
#endif


