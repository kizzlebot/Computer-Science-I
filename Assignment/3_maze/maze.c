/*  Name:          James Choi
 *  Date:          October 15, 2013
 *  Course:        COP 3502 Computer-Science I (Mon,Wed,Fri)
 *  Assignment #3: Maze.c
 *  Description:   Finds the way out of a maze using concept of Breadth-first search, stacks and queues
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * I got stacks..
 * Linked list implementation of stacks used as queues containing coords as int[]
 */
struct stack{
    int coord[2];
    struct stack * next ;
};


/////////////////////////////////// Stack Functions //////////////////////////////////////////////
/*    Function: alloc
 *   Arguments: (int x, int y ) X and Y Coords
 *      Return: (struct stack * ) Newly allocated node, that has a nextVal of NULL and X,Y coords as given
 * Description: Allocates and returns a node that points to null with coords.  */
struct stack * alloc(int x, int y );

/*    Function: push
 *   Arguments: (struct stack ** root) Pointer to the root node, which is top of stack
 *              (struct stack * newTop) node to add as the new top
 *      Return: Returns pointer to the top of the stack ;
 * Description: Push newTop to the top of the stack  */
struct stack * push(struct stack * root, struct stack * newTop);

/*    Function: pop
 *   Arguments: (struct stack ** root) Pointer to the root node, which is top of stack
 *      Return: (struct stack * ) Element that was on top of stack
 * Description: Given the root node, modify the stack by removing the topmost element and returning it*/
struct stack * pop(struct stack ** root);

/////////////////////////////////// Stack Functions END //////////////////////////////////////////


/////////////////////////////////// Maze Functions //////////////////////////////////////////////
/*    Function: recursiveFree
 *   Arguments: (struct stack * freeMe)  linked list stack of the queues to free
 *      Return: (void)          no need to return anything just free everything
 * Description: Get to the bottom of the linked list, then free as coming down call stack */
void recursiveFree(struct stack * freeMe);

/*    Function: callCases
 *   Arguments: (int numCases)  integer of number of input cases
 *      Return: (void)          no need to return anything just repeat until numCases == 0
 * Description: Keeps finding answers for input cases until numCases == 0 */
void callCases(int numCases);

/*    Function: recursiveRead
 *   Arguments: (char ** charSet)  a set of set of chars (aka an array of strings )
 *              (int ** nBoard)    array of the map filled with ints
 *      Return: (void)             no need to return anything, we passed by reference
 * Description:  while numLines isn't zero, it will read a line into board, then iterate to fill nBoard with
 *               -1 while seeing if board contains 'S', where it will insert a 0 into nBoard, and then recurse */
void recursiveRead(char ** charSet, int ** nBoard, int numLines,int cols);

/*    Function: findExit
 *   Arguments: (struct stack ** queue)  linked list stack of the queues
 *              (char ** board)          char dbl array of the map filled
 *              (int ** nBoard)          int dbl array of the map filled with ints
 *      Return: (void)          no need to return anything just need to print the answer
 * Description:  while numLines isn't zero, it will read a line into board, then iterate to fill nBoard with
 *               -1 while seeing if board contains 'S', where it will insert a 0 into nBoard, and then recurse */
void findExit(struct stack * queue, char ** board,int ** nBoard);

/////////////////////////////////// Maze Functions END //////////////////////////////////////////////

int main(){
    // Read first line containing the number of test cases and call callCases with it to find the answers.
    // then call it a day..
    int firstLine ;
    scanf("%d",&firstLine);
    callCases(firstLine);// ;P
}

void callCases(int numCases){
    if ( numCases == 0 ){
        return ;
    }
    // Read the line containing the rows and columns
    int rows, cols;
    scanf("%d %d",&rows,&cols);

    // Read the input file into board
    char ** board = (char **)malloc(sizeof(char *)*(rows));
    int ** nBoard = (int **)malloc(sizeof(int *)*(rows));
    recursiveRead(board,nBoard,rows,cols);

    int i = 0 ;
    int j = 0 ;

    // Use the char array to find the coord of the 'S' character and queue the first spot
    struct stack * start ;
    for ( i = 0 ; i < rows ; i++){
        for ( j = 0 ; j < cols ; j++){
            if (board[i][j] == 'S'){
                start = alloc(i,j);
            }
        }
    }
    // Find the shortest distance to get out of maze (if there is one), print -1 if not.
    findExit(start,board,nBoard) ;

    // Free all the resources
    for ( i = 0 ; i < rows ; i++) {
        free(board[i]);
        free(nBoard[i]);
    }
    free(board);
    free(nBoard);
    recursiveFree(start);

    // Recursive call
    callCases(numCases-1);
}
void recursiveFree(struct stack * freeMe){
    if (freeMe!= NULL){
        if ( freeMe->next == NULL ){
            free(freeMe);
        }
        else{
            recursiveFree(freeMe->next);
            free(freeMe);
        }
    }
    else{
        return ;
    }
}
struct stack * alloc(int x, int y ){
	struct stack * new = (struct stack *) malloc(sizeof(struct stack));
	new->next = NULL ;
	new->coord[0] = x ;
	new->coord[1] = y ;
	return new ;
}
struct stack * push(struct stack * root, struct stack * newTop){
	if ( root==NULL){
		root = newTop ;
		return root ;
	}
	else{
		newTop->next = root ;
		return newTop ;
	}
}
struct stack * pop(struct stack ** root){
    if (root!=NULL ){
        struct stack * popped = (*root);
        (*root)=(*root)->next;
        popped->next = NULL ;
        return popped ;
    }
    else{
        return NULL ;
    }
}
void recursiveRead(char ** sets , int ** nBoard, int numLines, int cols){
    // Base case
    if (numLines == 0 ) return ;

    // No particular reason for the calloc.
    *sets = (char *)calloc(cols+1,sizeof(char )) ;
    *nBoard = (int *)calloc(cols+1,sizeof(int )) ;
    scanf("%s",*sets); // Read the whole line

    // find the 'S' and put a 0 in the nBoard there, otherwise -1
    int i = 0 ;
    for (i = 0 ; i < strlen(*sets); i++ ){
        if (*(*(sets)+i)=='S' ){
            *(*nBoard+i)=0;
        }
        else{
            *(*nBoard+i)=-1;
        }
    }

    // Recursive call with the next index of and numSets-1
    recursiveRead(sets+1,nBoard+1,numLines-1,cols);
}

void findExit(struct stack * queue, char ** board,int ** nBoard){
    //while queue is not Empty
    struct stack * dq ;
    while (queue!= NULL ){

        // dequeue.. Make me have to pop off
        dq = pop(&queue);

        // if this is the goal, print the number stored there and get out of here  ;
        if (board[dq->coord[0]][dq->coord[1]] == '~' ){
            // print the value stored at the coord and get outta here
            printf("%d \n",nBoard[dq->coord[0]][dq->coord[1]]);
            free(dq);
            return;
        }
        // else
        else{
            /* In each of the four neighbors of current coordinate, if neighbor is unvisited and not blocked,
             * then put the number of steps required to move from starting point to there,
             * which is always going to be the number stored at this coordinate+1, and
             * enqueue it */

            if ( nBoard[dq->coord[0]][dq->coord[1]+1] == -1 && board[dq->coord[0]][dq->coord[1]+1] != 'X' ){ // Left Adjacent
                nBoard[dq->coord[0]][dq->coord[1]+1] = nBoard[dq->coord[0]][dq->coord[1]]+1;
                queue = push(queue,alloc(dq->coord[0],dq->coord[1]+1));
            }
            if ( nBoard[dq->coord[0]][dq->coord[1]-1] == -1 && board[dq->coord[0]][dq->coord[1]-1] != 'X' ){ // Right Adjacent
                nBoard[dq->coord[0]][dq->coord[1]-1] = nBoard[dq->coord[0]][dq->coord[1]]+1;
                queue = push(queue,alloc(dq->coord[0],dq->coord[1]-1));
            }
            if ( nBoard[dq->coord[0]+1][dq->coord[1]] == -1 && board[dq->coord[0]+1][dq->coord[1]] != 'X' ){ // Top Adjacent
                nBoard[dq->coord[0]+1][dq->coord[1]] = nBoard[dq->coord[0]][dq->coord[1]]+1;
                queue = push(queue,alloc(dq->coord[0]+1,dq->coord[1]));
            }
            if ( nBoard[dq->coord[0]-1][dq->coord[1]] == -1 && board[dq->coord[0]-1][dq->coord[1]] != 'X' ){ // Bottom Adjacent
                nBoard[dq->coord[0]-1][dq->coord[1]] = nBoard[dq->coord[0]][dq->coord[1]]+1;
                queue = push(queue,alloc(dq->coord[0]-1,dq->coord[1]));
            }
        }
    }
    // If control reached here, there was no way to get outta here
    free(dq);
    printf("-1\n");
}

