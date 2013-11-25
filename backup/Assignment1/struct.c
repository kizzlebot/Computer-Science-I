#include <stdio.h>
#include <stdlib.h>

struct integer {
	int * digits;
	int size ;
};
struct integer* readAndCount(struct integer * p ,char *fileName){
    int CUR_MAX = 40 ;
    int length = 0 ;
    char ch ;
    char * buffer = malloc(sizeof(char)*CUR_MAX);
    FILE * file ;
    file = fopen(fileName,"r");
    int count = 0 ;
    while ((ch != '\n') && (ch != EOF)){
        ch = getc(file);
        //printf("%c",ch);
        length++ ;
        count++ ;
    }
    p->size = length-1 ;
    free(buffer) ; 
    return p ;   
}
char * readInChar(char * fileName){
    int CUR_MAX = 128 ;
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
    
    return buffer ;  
}
struct integer * convertToInt ( char * ch ) {
    struct integer * p = malloc(sizeof(struct integer)) ;
    p->size = 0;
    
        char filename[] = "file.txt";
    // get struct member size
    p = readAndCount(p, filename);
    // use struct member size to malloc digits
    p->digits = malloc(sizeof(int)*(p->size)+1) ; 
    

    int n = p->size-1 ;
    int k = 0; 
    // We got p->size and character array ch
    for ( ; n > -1 ; n--){
        p->digits[k] = chars[n] -'0'; 
        printf("\n%d",p->digits[k]);
        k++ ; 
    }
    return p ; 
}
int main(){
	struct integer * p ;
        int i = 0 ;
	printf("\nSize = %d",p->size);
        //Get char array
        char filename[] = "file.txt";
        char * chars = readInChar(filename) ; 
        printf("\nNow Malloc'ing p->digits to p->size*sizeof(int)") ; 
        p = convertToInt(chars) ;
}
