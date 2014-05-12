#include <stdio.h>
#include <stdlib.h>


int main(){
	int x = 5 ; 
	int * ptr = &x ; 
	printf("\nint x = %d",x) ; 
	printf("\nint * ptr = &x",x) ; 
	printf("\nprint ptr = %d",ptr) ; 
	printf("\nprint *ptr = %d",*ptr) ; 
	printf("\nprint &ptr = %d",&ptr) ; 
	(*ptr)++ ; 
	printf("\n(*ptr)++ = %d",*ptr) ; 
	printf("\nint x = %d",x) ; 


	char * aWord = "Dogs" ; 
	printf("\n%s",aWord);
	printf( "\n%c",*(aWord+1))	;
}
