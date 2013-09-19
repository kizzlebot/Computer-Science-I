#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char * word ;
    int length ;
} Set;

char * push( char * ch , char ltr){
    int length = strlen(ch);
    char * c = (char*)malloc(sizeof(char)*(length+1)) ;
    strcpy(c,ch);
    c[length] = ltr ;
    return c ;
}
void extend_set(char * base, Set ** sets, int numSets,int * dt, int magic){
    char * choices = (*sets)->word ;
    if (numSets == 0 ){
        *dt = (*dt)++;
        if ( *dt == magic ) printf("%s %d\n",(base),*dt);
    }
    int i = 0 ;
    //printf("Length %d",length);
    for ( i = 0 ; i < strlen(choices); i++){
        char * b2 = push(base,choices[i]);
        extend_set(b2,sets+1,numSets-1,dt,magic);
        free(b2);
    }
}
int main(){
    Set ** input = (Set **) malloc(sizeof(Set *)*5) ;
    int i = 0 ;
    for ( i = 0 ; i < 5 ; i++){
        input[i] =(Set *) malloc(sizeof(Set ));
        input[i]->word  =(char*) malloc(sizeof(char)*50);
    }
    strcpy((*(*input)).word, "abcdefghijklmnopqrstuvwxyz");
    strcpy((*(*(input+1))).word, "abcdefghijklmnopqrstuvwxyz");
    strcpy((*(*(input+2))).word, "dmnr");
    strcpy((*(*(input+3))).word, "dmnr");
    //permute(sets.set,sets.set[0]->word,0,(*input)->length-1);
    char * base = (char *)malloc(sizeof(char ));;
    int * in = (int *)malloc(sizeof(int));
    //printf("%d",getLength((*input)->word));
    *in = 0 ;
    extend_set(base,input,4,in,676);
    return 0 ;
}
