#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"
char ** recursiveRead(char ** sets , int ** nBoard, int numSets,int cols){
    // Base case
    if (numSets == 0 ) return sets ;

    *sets = (char *)calloc(cols+1,sizeof(char )) ;
    *nBoard = (int *)calloc(cols+1,sizeof(int )) ;
    scanf("%s",*sets);

    int i = 0 ;
    for (i = 0 ; i < strlen(*sets); i++ ){
        if (*(*(sets)+i)=='S' ){
            *(*nBoard+i)=0;
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

void spots(struct stack * queue, char ** board,int ** nBoard){
    //while queue is not Empty
    struct stack * dq ;
    while (queue!= NULL ){
        // dequeue: pop off the stack current ;
        dq = pop(&queue);

        // if this is the goal:
        if (board[dq->coord[0]][dq->coord[1]] == '~' ){
            // return ;
            printf("%d \n",nBoard[dq->coord[0]][dq->coord[1]]);
            return;
        }
        // else
        else{
            // for each neighbor of current, (there can only be four neighbors a most)
            // if neighbor is unvisited and not blocked then
            if ( nBoard[dq->coord[0]][dq->coord[1]+1] == -1 && board[dq->coord[0]][dq->coord[1]+1] != 'X' ){
                // figure out dist diff from current to neighboar and put that val in that index
                nBoard[dq->coord[0]][dq->coord[1]+1] = nBoard[dq->coord[0]][dq->coord[1]]+1;
                // enqueue neighbor
                queue = push(queue,alloc(dq->coord[0],dq->coord[1]+1));
            }
            if ( nBoard[dq->coord[0]][dq->coord[1]-1] == -1 && board[dq->coord[0]][dq->coord[1]-1] != 'X' ){
                // figure out dist diff from current to neighboar and put that val in that index
                nBoard[dq->coord[0]][dq->coord[1]-1] = nBoard[dq->coord[0]][dq->coord[1]]+1;
                // enqueue neighbor
                queue = push(queue,alloc(dq->coord[0],dq->coord[1]-1));
            }
            if ( nBoard[dq->coord[0]+1][dq->coord[1]] == -1 && board[dq->coord[0]+1][dq->coord[1]] != 'X' ){
                // figure out dist diff from current to neighboar and put that val in that index
                nBoard[dq->coord[0]+1][dq->coord[1]] = nBoard[dq->coord[0]][dq->coord[1]]+1;
                // enqueue neighbor
                queue = push(queue,alloc(dq->coord[0]+1,dq->coord[1]));
            }
            if ( nBoard[dq->coord[0]-1][dq->coord[1]] == -1 && board[dq->coord[0]-1][dq->coord[1]] != 'X' ){
            // mark current as examined
                // figure out dist diff from current to neighboar and put that val in that index
                nBoard[dq->coord[0]-1][dq->coord[1]] = nBoard[dq->coord[0]][dq->coord[1]]+1;
                // enqueue neighbor
                queue = push(queue,alloc(dq->coord[0]-1,dq->coord[1]));
            }
        }
    }
    printf("There is no way out of this maze!\n");
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
    struct stack * start ;
    for ( i = 0 ; i < rows ; i++){
        for ( j = 0 ; j < cols ; j++){
            if (board[i][j] == 'S'){
                start = alloc(i,j);
            }
        }
    }
    spots(start,board,nBoard) ;
    free(nBoard);
    free(board);
}


