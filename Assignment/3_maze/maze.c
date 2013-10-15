#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * Queue is part of Breadth First Search
 *
 * Algorithm ;
 *	. Given a starting point,
 *	a.) Travel to all adjacent places, mark these locations as being 1 step away
 *	from starting point
 *	b.) For each location that is 1 step away, visit all adjacent points that are not
 *	visited, mark these locations as being two steps away.
 *	c.) Repeat until one of the spots you mark is the exit
 */
struct stack{
    int coord[2];
    struct stack * next ;
};



/*    Function: alloc
 *    Arguments: (int x, int y ) X and Y Coords
 *    Return: (struct stack * ) Newly allocated node, that has a nextVal of NULL and X,Y coords as given
 *    Description: Allocates and returns a node that points to null with coords.  */
struct stack * alloc(int x, int y );

/*    Function: push
 *    Arguments: (struct stack ** root) Pointer to the root node, which is top of stack
 *    (struct stack * newTop) node to add as the new top
 *    Return: Returns pointer to the top of the stack ;
 *    Description: Push newTop to the top of the stack  */
struct stack * push(struct stack * root, struct stack * newTop);

/*    Function: pop
 *    Arguments: (struct stack ** root) Pointer to the root node, which is top of stack
 *    Return: (struct stack * ) Element that was on top of stack
 *    Description: Given the root node, modify the stack by removing the topmost element and returning it*/
struct stack * pop(struct stack ** root);

/*    Function: popBottom
 *    Arguments: (struct stack ** root) Pointer to the root node, which is top of stack
 *    Return: (struct stack * ) Element that was on bottom of stack
 *    Description: Given the root node, modify the stack by removing the bottommost element and returning it*/
struct stack * popBottom(struct stack ** root);

/*    Function: getBottomPtr
 *    Arguments: (struct stack ** root) Pointer to the root node, which is top of stack
 *    Return: (struct stack *) The pointer to the bottom of stack w/o modifying the stack ;
 *    Description: Returns the pointer to the bottom most element w/o modifying the stack  */
struct stack * getBottomPtr(struct stack ** root);

/*    Function: printnext
 *    Arguments: (struct stack ** root) Pointer to the root node, the top of stack ;
 *    Return: (void)
 *    Description: Called by the print function, to print all nodes other than the topmost */
void printnext(struct stack ** root);

/*    Function: print
 *    Arguments: (struct stack ** root) Pointer to the pointer that points to the top of stack
 *    Return: (void)
 *    Description: Wrapper function, prints the first element and if there is more, then call printnext */
void print(struct stack ** root);

struct stack * pushBottom(struct stack ** root, struct stack * newBottom );

void printCC(char ** sets);
char ** recursiveRead(char ** sets , int ** nBoard, int numSets,int cols);
struct stack * alloc(int x, int y );
void spots(struct stack * queue, char ** board,int ** nBoard);
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
struct stack * pushBottom(struct stack ** root, struct stack * newBottom ){
    if (root != NULL){
        if ( (*root)->next == NULL ){
            (*root)->next = newBottom ;
        }
        else{
            pushBottom(&((*root)->next),newBottom);
        }
    }
    else{
        (*root) = newBottom;
    }
    return *root ;
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

struct stack * popBottom(struct stack ** root){
    if ((*root)==NULL) return NULL ;
    else{
        if ( (*root)->next->next == NULL ){
            struct stack * bottom = (*root)->next;
            (*root)->next = (*root)->next->next ;
            return bottom ;
        }
        return popBottom(&((*root)->next));
    }
}

struct stack * getBottomPtr(struct stack ** root){
	if ( (*root)->next->next == NULL ){
		struct stack * bottom = (*root)->next;
		return bottom ;
	}
    return getBottomPtr(&((*root)->next));
}

void printnext(struct stack ** root){
	if ( *root!=NULL ){
		if ( (*root)->next == NULL ) printf("\e[38;5;26m(%d %d)\e[0m\n",(*root)->coord[0],(*root)->coord[1]);
		else{
			printf("(%d %d)",(*root)->coord[0],(*root)->coord[1]);
			printnext(&((*root)->next));
		}
	}
	else{
		printf("");
	}
}

void print(struct stack ** root){
	printf("\e[38;5;26m(%d %d)\e[0m",(*root)->coord[0],(*root)->coord[1]);
	printnext(&((*root)->next));
}

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

