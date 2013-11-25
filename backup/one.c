#include <stdio.h>
#include <stdlib.h>

struct integer{
        int* digits ;
        int size ;
};


struct integer* readThis( void ){
    FILE *infile = fopen("infile.txt", "r");
            
                
    struct integer *new_int = malloc(sizeof(struct integer));
                        
    fscanf(infile,"%d", &(new_int->size));
    new_int->digits = malloc(sizeof(int)*new_int->size);
    return new_int ;
}

int main(){
        struct integer* bigint ;
        bigint = readThis();
        printf("%d",bigint->size);
}
