#include <stdio.h>
#include <stdlib.h>


struct integer {
    int * digits ;
    int size ;
};
void printThis(char* this, int size){
    printf("\n");
    int i = 0 ;
    printf("\nSize: %d\n",size);
    for ( i =0 ; i < size ; i++){
        printf("%c",this[i]);
    }
}

struct integer * readFile(char *fileName){
    int CUR_MAX = 128 ;
    char * buffer = malloc(sizeof(char)*CUR_MAX) ;
    int length = 0 ;
    char ch  ;
    FILE * file ;
    int count = 0 ;
    int k = 0 ;
    int n ;
    struct integer *new_int = malloc(sizeof(struct integer));
    printf("\nBuffer* has been malloc'd to: %lu\n",sizeof(char)*CUR_MAX );
    file = fopen(fileName,"r");
    new_int->digits = malloc(sizeof(int)*(length+1)); // make new_int->digits have sizeof(int)*n indices
    while ((ch != '\n') && (ch != EOF)){
        if (count == CUR_MAX-1){
            CUR_MAX*= 2 ;
            count = 0 ; 			
            printf("\nMax Size Reached\n" );
            printf("\nReallocating size of buffer to %d\n",CUR_MAX );
            buffer = realloc(buffer,CUR_MAX);
        }
        ch = getc(file);
        buffer[length] = ch ;  
        //printf("%c",ch);
        length++ ;
        count++ ;
    }
    printf("\nPassing to printThis Function");
    printThis(buffer,length-1);
    for ( n = length-2 ; n >  -1; n--){
        new_int->digits[n] = buffer[k] - '0' ;
	printf("\noldint[%d] = %c, new_int->digits[%d] = %d",k,buffer[k],n,new_int->digits[n]);
        k++;
    }
    free(buffer);
    return new_int ; 
}
int main(){
    char filename[] = "file.txt" ;
    char * ff ;
    ff = filename ;
    char * dd ;
    readFile(ff) ;
	
}

