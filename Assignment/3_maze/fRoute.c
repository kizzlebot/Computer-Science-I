#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"
#define GUESS 300
char ** recursiveRead(char ** sets , int ** nBoard, int numSets,int cols){
    // Base case
    if (numSets == 0 ) return sets ;

    // Allocate a dummy with a guessed size
    // Read the line into it
    // Use the length of the line read in and allocate a set of chars with that many elements
    *sets = (char *)calloc(cols+1,sizeof(char )) ;
    *nBoard = (int *)calloc(cols+1,sizeof(int )) ;
    scanf("%s",*sets);

    int i = 0 ;
    for (i = 0 ; i < strlen(*sets); i++ ){
        if (*(*(sets)+i)=='S' ){
            *(*nBoard+i)=-0;
        }
        else{
            *(*nBoard+i)=-1;
        }
    }

    // Recursive call with the next index of sets and numSets-1
    recursiveRead(sets+1,nBoard+1,numSets-1,cols);

    // Last one off the stack
    return sets ;
}
void printCC(char ** sets){
    if ( *sets != NULL ){
        printf("%s\n",*(sets));
        printCC(sets+1);
    }
}
int main(){
    int firstLine ;
    scanf("%d",&firstLine);
    int rows, cols;
    scanf("%d %d",&rows,&cols);

    char ** board = (char **)malloc(sizeof(char *)*(rows+1));
    int ** nBoard = (int **)malloc(sizeof(int *)*(rows+1));
    recursiveRead(board,nBoard,rows,cols);
    printCC(board);


    int i = 0 ;
    int j = 0 ;
    for ( i = 0 ; i < rows ; i++){
        for ( j = 0 ; j < cols ; j++){
            printf("%d ",nBoard[i][j]);
        }
        printf("\n");
    }
}


