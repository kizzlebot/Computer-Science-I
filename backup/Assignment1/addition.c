#include <stdio.h>
#include <stdlib.h>


struct integer{
	int* digits ;
	int size ;
};
/*
	Function:         add
	Parameters:       struct integer *p, struct integer *q
	Return data-type: struct integer*
*/
/*	Function:    add
	Parameters:	 struct integer p, struct integer q
	Return Val:  struct integer*
	
 */
struct integer* add ( struct integer *p, struct integer *q ){
	// new_int points to a memory address dynamically allocated to be the size of a 'struct integer' type
	struct integer *new_int = malloc(sizeof(struct integer)); // Malloc implicitly declares a new struct integer
	// tmp points to a null node
	struct integer *tmp = NULL;
	
	int i, carry;
	
	// If ( p->size  <  q->size ) then swap pointers between p and q
	if ( p->size < q->size ){
		tmp = p;
		p = q;
		q = tmp;
	}
	
	// Make (new_int*).digits
	new_int->digits = malloc(sizeof(int) * (p->size + 1)); // An int is 4 bytes = 32bits = 2^32-1 indices
	new_int->size = p->size;
	
	for (carry = i = 0; i < q->size; i++){
		new_int->digits[i] = (q->digits[i] + p->digits[i] + carry) % 10;
		carry = (q->digits[i] + p->digits[i] + carry) / 10;
	}

	while (i < p->size){
		new_int->digits[i] = p->digits[i] + carry;
		i++;
		new_int->size = i;
		carry = 0;
	}
	if (carry){
		new_int->digits[i] = carry;
		new_int->size++;
	}
	
	return new_int;
}

/*
	Preconditions:  The first parameter is string that only contains digits and is 10000 digits or fewer. No leading 0s will be included
					unless the number represented is 0.
	Postconditions: The function will read the digits of the large integer character by character, convert them into integers and return a
					pointer to the appropriate struct integer.
*/
struct integer* convert_integer(char* stringInt){
	struct integer *new_int = malloc(sizeof(struct integer)) ;
	
	int i =  0 ;

	new_int->digits = malloc(sizeof(int)*sizeof(stringInt));

	for (i = 0 ; *stringInt+i >= '0' && *stringInt+i <= '9' ; i++){
		new_int->digits[i]  = (*stringInt+i) - '0' ;
	}
	return new_int  ;
}


/*
	Preconditions:  p is a pointer to a big integer.
	Postconditions: The big integer pointed to by p is printed out.
*/
void print(struct integer *p);


/*
	Preconditions:  p and q are pointers to struct integers.
	Postconditions: A new struct integer is created that stores the product of the integers pointed to by p and q and a pointer to it
					is returned.
*/
struct integer* multiply(struct integer *p, struct integer *q);

/*
 Preconditions:  
 Postconditions:
 */

int main(){
}
