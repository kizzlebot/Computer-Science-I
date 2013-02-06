#include <stdio.h>
#include <stdlib.h>

struct integer{
	int* digits ;
	int size ;
};


struct integer* readThis( void ){
	FILE *infile = fopen("infile.txt", "r");
	
	
	struct integer *new_int = malloc(sizeof(struct integer));
        int i = 0 ;	
	fscanf(infile,"%d", &(new_int->size));
	new_int->digits = malloc(sizeof(int)*(new_int->size+1));
	
        for ( i = 0 ; i < new_int->size ; i++){
		new_int->digits[i] = i ;
	}
	return new_int ;
}

int main(){
	struct integer* bigint ;
	bigint = readThis();
        int i = 0 ;
        printf("%d\n",bigint->size);
        for ( i = 0 ; i < bigint->size ; i++){
            printf("%d ",bigint->digits[i]); 
        }
        printf("\n The Size of bigint->digits: %d",(int)sizeof(int)*bigint->size);
        printf("\n The Size of int: %d",(int)sizeof(int));
        printf("\n The Size of int: %d",(bigint->size));
}
