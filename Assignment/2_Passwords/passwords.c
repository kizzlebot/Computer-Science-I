/* Name:    James Choi
 * Course:  COP 3501 (Mon/Wed/Fri 9:30AM)
 * Assignment #2
 * September 22, 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GUESS 10000

/* Function    : getCombosPerMove
 * Arguments   : (char **) Containing the sets of chars that follow the one in
 *               question.
 * Returns     : (int) The product of the number of elements in the given set
 * Description : In, for example, a 3x3x3x3, in order to the determine
 *               the number of indexes the topmost set can move to reach the
 *               magic number we need the product of the number of elements
 *               in the sets that follow the topmost, that is, 3x3x3=27
 *               This means that in order to move the index to the next element
 *               in the topmost set, we need to make 27 moves in the sets that follow.
 * */
int getCombosPerMove(char ** words  );


/* Function    : findCombo
 * Arguments   : (char **) Contains sets of words, (an array of an array of
 *               chars)
 *               (int)     The magic number (nth value)
 *               (int)     Initially contains product b/t all lengths of sets
 * Returns     : void
 * Description : Figures out the number of indexes to move in the current set of
 *               chars contained in (*words). Then prints this value and calls
 *               itself with the next set and remainder, which will do the same.
 */
void findCombo(char ** words , int magic, int combosPerMove);

/* Function    : recursiveRead
 * Arguments   : (char **) Sets should be unallocated and only declared
 *               (int )    Number of sets to read in from stdin
 * Returns     : (char **) Returns the param allocated+initialized with lines
 *                         read in from stdin
 * Description : Recursively reads from stdin by reading into a temporary
 *               variable (aLine) a line, calloc'ing (*sets) exactly the number of chars
 *               (aLine) contains, and copying (aLine) into it and freeing it before
 *               calling itself with param of next index of char array and numSets-1
 *               until numSets equals 0,
 */
char ** recursiveRead(char ** sets , int numSets);

/* Function   : recursiveFree
 * Arguments  : (char **) sets should be an array of an array of chars
 * Returns    : (void)
 * Description: Keeps calling itself with next index of sets, which contains an array of
 *              chars, until a NULL is reached. Then frees each index.
 */
void recursiveFree(char ** sets  );

/* Function   : recursiveInit
 * Arguments  : (char **) Input should be unallocated
 *              (int)     number of passwords that need to be found
 * Returns    : void
 * Description: This function is in charge of reading the number of sets
 *              (numSets), the sets of chars of each possible character of the
 *              password, and the magic number (magicNumber), before calling
 *              findCombo to find the nth (magicNumber) combination, before
 *              freeing allocated values and then calling itself with
 *              numPassesToGuess-1 until a zero is reached
 */
void recursiveInit(char ** input , int numPassesToGuess);




int main(){
    int numPassesToGuess;
    char ** input ; // Don't need to init, let resursiveInit do that

    // Get the first line containing number of passwords to guess
    scanf("%d",&numPassesToGuess);
    recursiveInit(input,numPassesToGuess); // Lets go
    return 0 ; // Okay, we outta herr
}

int getCombosPerMove(char ** words  ){
    if ( *words == NULL ) return 1 ; // Base Case
    return strlen(*(words)) * getCombosPerMove(words+1); // Return Product strlen and prev strlen
}
void findCombo(char ** words , int magic, int combosPerMove){
    if ( *words == NULL ) return ;
    combosPerMove = combosPerMove / strlen(*words);
    printf("%c",*(*(words)+magic/combosPerMove));
    findCombo(words+1,magic%combosPerMove,combosPerMove);
}
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
    input = recursiveRead( (char **) calloc(numSets+1,sizeof(char *)),numSets);
    scanf("%d",&magicNumber);
    findCombo(input,magicNumber-1,getCombosPerMove(input)); // This is that Ancient Chinese secret homie
    printf("\n");
    recursiveFree(input);
    free(input);
    recursiveInit(input,numPassesToGuess-1);
}