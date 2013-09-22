#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GUESS 10000

/*
 * Takes an array of words, and returns the value of
 * strlen(words[i-1])*strlen(words[i-2])*strlen....
 */
int getCombosPerMove(char ** words  ){
    if ( *words == NULL ) return 1 ;
    return strlen(*(words)) * getCombosPerMove(words+1);
}
void findCombo(char ** words , int magic  ){
    if ( *words == NULL ) return ;
    int combosPerMove = getCombosPerMove(words+1);
    printf("%c",*(*(words)+magic/combosPerMove));
    findCombo(words+1,magic%combosPerMove);
}
char ** read(char ** sets , int numSets){
    if (numSets == 0 ) return sets ;

    char * aLine ;
    aLine = (char *) calloc(GUESS,sizeof(char));
    scanf("%s",aLine );

    *sets = (char *)calloc(strlen(aLine)+1,sizeof(char )) ;
    strcpy(*sets,aLine);
    free(aLine);

    read(sets+1,numSets-1);
    return sets ;
}
void recursiveFree(char ** sets  ){
    if (*sets == NULL ) return ;

    recursiveFree(sets+1);
    free(*sets);
}
void recursiveInit(char ** input , int numPassesToGuess){
    if ( numPassesToGuess == 0 ) return ;

    int numSets ;
    int magicNumber ;
    scanf("%d",&numSets);
    input = read( (char **) calloc(numSets+1,sizeof(char *)),numSets);
    scanf("%d",&magicNumber);

    findCombo(input,magicNumber-1);

    printf("\n");
    recursiveFree(input);
    recursiveInit(input,numPassesToGuess-1);
}


int main(){
    int numPassesToGuess;
    // Get the first line containg number of passwords to guess
    scanf("%d",&numPassesToGuess);
    char ** input ;
    recursiveInit(input,numPassesToGuess);
}