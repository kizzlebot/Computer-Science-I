#include <stdio.h>
#include <stdlib.h>




typedef struct {
	char * strand ; 
	int freq[4] ; 	
	char section[20] ; 
} DNA;


int main(){
	DNA * aDna = (DNA * )malloc(sizeof(DNA));
	aDna->strand = (char *)malloc(sizeof(char)*4) ; 



	return 0 ; 
}
