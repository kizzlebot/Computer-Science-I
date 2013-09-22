#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GUESS 10000

/*  Returns the number of moves required to move from current element to next */
int getCombosPerMove(char ** words  ){
    if ( *words == NULL ) return 1 ;
    return strlen(*(words)) * getCombosPerMove(words+1);
}

/* Finds and prints the nth combination specified by what the magic number is */
void findCombo(char ** words , int magic  ){
    if ( *words == NULL ) return ;
    int combosPerMove = getCombosPerMove(words+1);
    printf("%c",*(*(words)+magic/combosPerMove));
    findCombo(words+1,magic%combosPerMove);
}

/* Recursively read and allocate the unallocated char * in **sets and return  */
char ** recursiveRead(char ** sets , int numSets){
    if (numSets == 0 ) return sets ;

    char * aLine ;
    aLine = (char *) calloc(GUESS,sizeof(char));
    scanf("%s",aLine );

    *sets = (char *)calloc(strlen(aLine)+1,sizeof(char )) ;
    strcpy(*sets,aLine);
    free(aLine);

    recursiveRead(sets+1,numSets-1);
    return sets ;
}
/* Free char * in char ** sets, recursively */
void recursiveFree(char ** sets  ){
    if (*sets == NULL ) return ;

    recursiveFree(sets+1);
    free(*sets);
}
/* Recursively call findCombo until we have no more passes to guess*/
void recursiveInit(char ** input , int numPassesToGuess){
    if ( numPassesToGuess == 0 ) return ;

    int numSets ;
    int magicNumber ;
    scanf("%d",&numSets);
    input = recursiveRead( (char **) calloc(numSets+1,sizeof(char *)),numSets);
    scanf("%d",&magicNumber);

    findCombo(input,magicNumber-1); // This is that Ancient Chinese secret homie

    printf("\n");
    recursiveFree(input);
    free(input);

    recursiveInit(input,numPassesToGuess-1);
}


int main(){
    int numPassesToGuess;
    char ** input ; // Don't need to init, let resursiveInit do that

    // Get the first line containing number of passwords to guess
    scanf("%d",&numPassesToGuess);
    recursiveInit(input,numPassesToGuess);
}