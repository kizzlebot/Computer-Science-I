#include <stdio.h>
#include <stdlib.h>


struct integer {
    int * digits ; 
    int size ; 
}
void printThis(char* this, int size){
    printf("\n");
    int i = 0 ; 
    for ( i =0 ; i < size ; i++){
        printf("%c",this[i]);
    }
    printf("\n%d",'2'+'2');
}
void readFile(char *fileName){
    int CUR_MAX = 40 ; 
    char * buffer = malloc(sizeof(char)*CUR_MAX) ; 
    printf("\nBuffer* has been malloc'd to: %lu\n",sizeof(char)*CUR_MAX ); 
    int length = 0 ; 
    char ch  ; 
    FILE * file ; 
    file = fopen(fileName,"r");
    int count = 0 ; 
    while ((ch != '\n') && (ch != EOF)){
        if (count == CUR_MAX){
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
    //free(buffer);
    printf("\nPassing to printThis Function");
    printThis(buffer,length-1); 
    reReadFile(buffer,length-1);
}
struct integer * reReadFile(char* bufr){
    
}
int main(){
    char filename[] = "file.txt" ; 
    char * ff ;
    ff = filename ; 
    char * dd ;
    readFile(ff) ; 
     
}
