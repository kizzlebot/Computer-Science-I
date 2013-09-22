/* Name:    James Choi
 * Course:  COP 3501 (Mon/Wed/Fri 9:30AM)
 * Assignment #2
 * September 22, 2013 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GUESS 10000


/* Function    : getCombosPossible
 * Arguments   : (char **) Containing the sets of chars that follow the one in
 *               question.
 * Returns     : (int) The product of the number of elements in the given set
 * Description : In, for example, a 3x3x3x3, in order to the determine
 *               the number of indexes the topmost set can move to reach the
 *               magic number we need the product of the number of elements
 *               in the sets that follow the topmost, that is, 3x3x3=27
 *               This means that in order to move the index to the next element
 *               in the topmost set, we need to make 27 moves in the sets that follow.*/
int getCombosPossible(char ** words  );


/* Function    : findCombo
 * Arguments   : (char **) Contains sets of words, (an array of an array of
 *                           chars)
 *               (int)     The magic number (nth value)
 *               (int)     Initially contains product b/t all lengths of sets
 * Returns     : void
 * Description : Figures out the number of indexes to move in the current set of
 *               chars contained in (*words). Then prints this value and calls
 *               itself with the next set and remainder, which will do the same.*/
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
 *               until numSets equals 0,*/
char ** recursiveRead(char ** sets , int numSets);


/* Function   : recursiveFree
 * Arguments  : (char **) sets should be an array of an array of chars
 * Returns    : (void)
 * Description: Keeps calling itself with next index of sets, which contains an array of
 *              chars, until a NULL is reached. Then frees each index.*/
void recursiveFree(char ** sets  );


/* Function   : recursiveInit
 * Arguments  : (char **) Input should be unallocated
 *              (int)     number of passwords that need to be found
 * Returns    : (void)
 * Description: This function is in charge of reading the number of sets
 *              (numSets), the sets of chars of each possible character of the
 *              password, and the magic number (magicNumber), before calling
 *              findCombo to find the nth (magicNumber) combination, before
 *              freeing allocated values and then calling itself with
 *              numPassesToGuess-1 until a zero is reached  */
void recursiveInit(char ** sets, int numPassesToGuess);



/* The only job of main is to read the first line and then call the 
 * initialize function, recursiveInit(input,numPassesToGuess) that will
 * recursively call other recursive functions */
int main(){

    // Get the first line containing number of passwords to guess
    int numPassesToGuess;
    scanf("%d",&numPassesToGuess);
    // Declare a char **, (only declare), and pass to recursiveInit
    char ** input ; 
    recursiveInit(input,numPassesToGuess); 
    return 0 ; // Okay, we outta herr
}

/* How many moves to move from |----to--->  here?
 *  _                                           _ 
 * [a][b][c][d]                            [a][b][c][d]
 * [a][d][f]                               [a][d][f]
 * [x][x][d]                               [x][x][d]
 *
 * Requires ((4*3*3)/strlen([a][b][c][d])) = (36/4) = 9 moves_in_other_sets/move_in_this_set
 * Therefore, if magic number is 10, we know how many spots to move 
 * on the first set by this equation, 10 / 9 = 1. The mod between these two is the magic number for
 * the next iteration in the recursion */ 
int getCombosPossible(char ** words  ){
    // Base Case
    if ( *words == NULL ) return 1 ; 
    return strlen(*(words)) * getCombosPossible(words+1); // Return Product strlen and prev strlen
}
void findCombo(char ** words , int magic, int combosPerMove){
    // Base Case
    if ( *words == NULL ) { 
        printf("\n");
        return ; 
    }
    // Compute the number of moves that need to be made to in the following sets
    // If a 3x3x3 (three sets with three chars each), number of moves req to move 
    // an index in the current set is given by (3x3x3)/strlen(currentSet)
    // The magicNumber/num_move_req_in_following_sets = index this set
    combosPerMove = combosPerMove / strlen(*words);
    printf("%c",*(*(words)+magic/combosPerMove));

    // Recursive call
    findCombo(words+1,magic%combosPerMove,combosPerMove);
}


char ** recursiveRead(char ** sets , int numSets){
    // Base case 
    if (numSets == 0 ) return sets ; 

    // Allocate a dummy with a guessed size 
    char * aLine = (char *) calloc(GUESS,sizeof(char));
    // Read the line into it
    scanf("%s",aLine );
    // Use the length of the line read in and allocate a set of chars with that many elements
    *sets = (char *)calloc(strlen(aLine)+1,sizeof(char )) ;
    // Copy the line read into the allocated 
    strcpy(*sets,aLine);
    // Free the dummy 
    free(aLine);

    // Recursive call with the next index of sets and numSets-1
    recursiveRead(sets+1,numSets-1);

    // Last one off the stack
    return sets ;
}
void recursiveFree(char ** sets  ){
    // Base case
    if (*sets == NULL ) return ;
    
    // Recursive call first.. First element is last one freed
    recursiveFree(sets+1);
    // Free the char array
    free(*sets);
}
void recursiveInit(char ** sets, int numPassesToGuess){
    // Base case
    if ( numPassesToGuess == 0 ) return ;
    
    // Read in line containing number of set of sets of chars. numSets_and_magic used for both number of sets and magic number
    int numSets_and_magic ;
    scanf("%d",&numSets_and_magic);
    // Read in the next numSets number of lines
    sets = recursiveRead( (char **) calloc(numSets_and_magic+1,sizeof(char *)),numSets_and_magic);
    // Read magic_number
    scanf("%d",&numSets_and_magic);
    // Find the combo
    findCombo(sets ,numSets_and_magic-1 ,getCombosPossible(sets) ); // << This is that Ancient Chinese secret homie

    // Free the allocated elements
    recursiveFree(sets);
    // Free the allocated (set) itself
    free(sets);

    // Recursive call
    recursiveInit(sets ,numPassesToGuess-1);
}
