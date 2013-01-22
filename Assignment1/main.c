#include <stdio.h>
#include <stdlib.h>

char fileName[] = "file.txt" ;
 
struct integer {
    int * digits ;
    int size ;
};
int countChars(char *fileName){
    int length = 0 ;
    char ch  ;
    FILE * file ;
    int count = 0 ;
    int k = 0 ;
    int n ;
    file = fopen(fileName,"r");
    while ((ch != '\n') && (ch != EOF)){
        ch = getc(file);
        //printf("%c",ch);
        length++ ;
        count++ ;
    }
    fclose(file);
    return length-1 ; 
}
char * readChars ( char * fileName){
    char * read = malloc(sizeof(char)*countChars(fileName)+1);
    int k = countChars(fileName) -1 ;
    FILE * file  = fopen(fileName,"r");
    for ( ; k > -1 ; k-- ) {
        read[k] = getc(file) ; 
    }
    fclose(file);
    return read ; 
}
struct integer * convert_integer ( char * stringInt ){
    int k = countChars(fileName) -1 ;
    int firstNonZero = 0 ; 
    while ( firstNonZero == 0  ) {
        if ( stringInt[k] == '0' ){
            k-- ; 
        }else{
            firstNonZero = 1; 
        }
    }
    struct integer * p = malloc(sizeof(struct integer));
    p->size = k+1 ; 
    p->digits = malloc(sizeof(int)*p->size) ; 
    //printf("from convert_int: ",p->digits[k]);
    for ( ; k > -1 ; k-- ) {
        p->digits[k] = stringInt[k] - '0'; 
        //printf("%d",p->digits[k]);
    }
    return p ; 
}
int main(){
    char * readCh = readChars(fileName) ; 
    struct integer * p = convert_integer(readCh) ; 
    int k ;
    for ( k = p->size-1 ; k > -1 ; k-- ) {
        printf("%d",p->digits[k]);
    }
    printf("\nSize of int: %lu",sizeof(int));
    printf("\nSize of p->size: %d",p->size);
    printf("\nSize of p->size*sizeof(int): %lu",sizeof(int)*p->size);
}

