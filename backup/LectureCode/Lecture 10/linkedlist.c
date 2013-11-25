#include <stdio.h>
#include <stdlib.h>

struct linked { 
	int data ; 
	struct linked * next ; 
};
/*
	Array is stored in continuous space.
	Linked lists is the simplest form of linked structure
	Array is an O(n) notation.

*/
int main(){
	struct linked * a, b, c ;  // Statically declared. 
	a.data = 0 ; 
	b.data = 1 ; 
	c.data = 2 ; 

	a.next = &b ;  // a.next is a pointer to b's memory location
	b.next = &c ;  // b.next is a pointer to c's memory location
	a.next = b.next = c.next = NULL ; 

	a.next->b.next->data ; // value 2 from c.data

}