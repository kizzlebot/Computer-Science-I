/*  Name:          James Choi
 *  Date:          October 15, 2013
 *  Course:        COP 3502 Computer-Science I (Mon,Wed,Fri)
 *  Assignment #3: Maze.c
 *  Description:   Finds the way out of a maze using concept of Breadth-first search, queues and queues
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY -1

// Stores one node of the linked list.
struct node {
    int * data;
    struct node* next;
};

// Stores our queue.
struct queue {
    struct node* front;
    struct node* back;
};

/*    Function: findExit
 *   Arguments: (struct queue * queue) pointer to queu
 *              (char ** board) game board
 *              (int ** nBoard ) game board containing ints
 * Description: Uses the queue to find the exit */
void findExit(struct queue * queue, char ** board,int ** nBoard);

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
void recursiveRead(char ** sets , int ** nBoard, int numLines, int cols);

/*    Function: alloc
 *    Arguments: (int x, int y ) X and Y Coords
 *    Return: ( int * ) Newly allocated int * contianing X,Y coords as given
 *    Description: Allocates and returns a int *.  */
int * alloc(int x, int y );

/*    Function: init
 *    Arguments: (struct queue * qPtr)
 *    Description: initializes qPtr
 */
void init(struct queue* qPtr);
/*  Function: enqueue
 *  arguements: (struct queue * qptr)  Queue
 *              (int * val) an array containing coords to add to queue
 *  description: adds given data to the queue
 */
int enqueue(struct queue* qPtr, int * val);
/*  Function: dequeue
 *  arguements: (struct queue * qptr)  Queue
 *  description: removes from  the queue
 */
int * dequeue(struct queue* qPtr);

/*  Function: Empty
 *  arguements: (struct queue * qptr)  Queue
 *  description: used to check if queue is empty
 */
int empty(struct queue* qPtr);

/*  Function: Empty
 *  arguements: (struct queue * qptr)  Queue
 *  description: returns values of next in queue without remove
 */
int * front(struct queue* qPtr);

int main() {

    // Allocate space for our queue and initialize it.
    struct queue* MyQueuePtr = (struct queue*)malloc(sizeof(struct queue));
    init(MyQueuePtr);

    int firstLine ;
    scanf("%d",&firstLine);
    callCases(firstLine);// ;P
    return 0;
}

int * alloc(int x, int y ){
    int * ret = (int *)malloc(sizeof(int)*2);
    ret[0] = x ;
    ret[1] = y ;
	return ret ;
}
// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: The struct that qPtr points to will be set up to represent an
//                 empty queue.
void init(struct queue* qPtr) {

     // Just set both pointers to NULL!
     qPtr->front = NULL;
     qPtr->back = NULL;
}

// Pre-condition: qPtr points to a valid struct queue and val is the value to
//                enqueue into the queue pointed to by qPtr.
// Post-condition: If the operation is successful, 1 will be returned, otherwise
//                 no change will be made to the queue and 0 will be returned.
int enqueue(struct queue* qPtr, int * val) {

    struct node * temp;

    // Allocate space for a new node to add into the queue.
    temp = (struct node*) malloc(sizeof(struct node));

    // This case checks to make sure our space got allocated.
    if (temp != NULL) {

        // Set up our node to enqueue into the back of the queue.
        temp->data   = (int *)malloc(sizeof(int)*2);
        temp->data[0] = val[0];
        temp->data[1] = val[1];
        free(val);
        temp->next = NULL;

        // If the queue is NOT empty, we must set the old "last" node to point
        // to this newly created node.
        if (qPtr->back != NULL)
            qPtr->back->next = temp;

        // Now, we must reset the back of the queue to our newly created node.
        qPtr->back = temp;

        // If the queue was previously empty we must ALSO set the front of the
        // queue.
        if (qPtr->front == NULL)
            qPtr->front = temp;

        // Signifies a successful operation.
        return 1;
    }

    // No change to the queue was made because we couldn't find space for our
    // new enqueue.
    else
        return 0;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: If the queue pointed to by qPtr is non-empty, then the value
//                 at the front of the queue is deleted from the queue and
//                 returned. Otherwise, -1 is returned to signify that the queue
//                 was already empty when the dequeue was attempted.
int * dequeue(struct queue* qPtr) {

    struct node* tmp;
    int * retval;


    // Check the empty case.
    if (qPtr->front == NULL)
        return NULL ;

    // Store the front value to return.
    retval = qPtr->front->data;

    // Set up a temporary pointer to use to free the memory for this node.
    tmp = qPtr->front;

    // Make front point to the next node in the queue.
    qPtr->front = qPtr->front->next;

    // If deleting this node makes the queue empty, we have to change the back
    // pointer also!
    if (qPtr->front == NULL)
        qPtr->back = NULL;

    // Free our memory.
    free(tmp);

    // Return the value that just got dequeued.
    return retval;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: returns true iff the queue pointed to by pPtr is empty.
int empty(struct queue* qPtr) {
    return qPtr->front == NULL;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: if the queue pointed to by qPtr is non-empty, the value
//                 stored at the front of the queue is returned. Otherwise,
//                 -1 is returned to signify that this queue is empty.
int * front(struct queue* qPtr) {
    if (qPtr->front != NULL)
        return qPtr->front->data;
    else
        return NULL ;
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
    struct queue* MyQueuePtr = (struct queue*)malloc(sizeof(struct queue));
    init(MyQueuePtr);
    for ( i = 0 ; i < rows ; i++){
        for ( j = 0 ; j < cols ; j++){
            if (board[i][j] == 'S'){
                enqueue(MyQueuePtr,alloc(i,j));
            }
        }
    }
    // Find the shortest distance to get out of maze (if there is one), print -1 if not.
    findExit(MyQueuePtr,board,nBoard) ;

    // Free all the resources
    free(*board);
    free(*nBoard);

    // Recursive call
    callCases(numCases-1);
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
    for (i = 0 ; i < cols ;i++ ){
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

void findExit(struct queue * queue, char ** board,int ** nBoard){
    //while queue is not Empty
    int * dq ;
    while (!empty(queue)){

        dq = dequeue(queue);

        // if this is the goal, print the number stored there and get out of here  ;
        if (board[dq[0]][dq[1]] == '~' ){
            // print the value stored at the coord and get outta here
            printf("%d \n",nBoard[dq[0]][dq[1]]);
            return;
        }
        // else
        else{
            /* In each of the four neighbors of current coordinate, if neighbor is unvisited and not blocked,
             * then put the number of steps required to move from starting point to there,
             * which is always going to be the number stored at this coordinate+1, and
             * enqueue it */
            if ( nBoard[dq[0]][dq[1]+1] == -1 && board[dq[0]][dq[1]+1] != 'X' ){ // Left Adjacent
                 nBoard[dq[0]][dq[1]+1] = nBoard[dq[0]][dq[1]]+1;
                 enqueue(queue,alloc(dq[0],dq[1]+1));
            }
            if ( nBoard[dq[0]][dq[1]-1] == -1 && board[dq[0]][dq[1]-1] != 'X' ){ // Right Adjacent
                nBoard[dq[0]][dq[1]-1] = nBoard[dq[0]][dq[1]]+1;
                enqueue(queue,alloc(dq[0],dq[1]-1));
            }
            if ( nBoard[dq[0]+1][dq[1]] == -1 && board[dq[0]+1][dq[1]] != 'X' ){ // Top Adjacent
                nBoard[dq[0]+1][dq[1]] = nBoard[dq[0]][dq[1]]+1;
                enqueue(queue,alloc(dq[0]+1,dq[1]));
            }
            if ( nBoard[dq[0]-1][dq[1]] == -1 && board[dq[0]-1][dq[1]] != 'X' ){ // Bottom Adjacent
                nBoard[dq[0]-1][dq[1]] = nBoard[dq[0]][dq[1]]+1;
                enqueue(queue,alloc(dq[0]-1,dq[1]));
            }
        }
    }
    printf("-1\n");
    // If control reached here, there was no way to get outta here
}

