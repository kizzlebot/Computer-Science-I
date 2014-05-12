#ifndef LINKED
#define LINKED

struct linked {
    int data ;
    struct linked * next ;
};
/* Creation */
struct linked * create(int val );

int insertBetween(struct linked * front, int searchVal, int insertVal );
/* Insertion */
struct linked * insertFront(struct linked * front, int data);
struct linked * insertBack(struct linked * front, int data);

void printLinked(struct linked * front);

#endif
