#ifndef MAZE
#define MAZE


/*
 * Contains only tested prototypes
 */


struct stack{
	int coord[2];
	struct stack * next ;
};



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

/*    Function: popBottom
 *   Arguments: (struct stack ** root) Pointer to the root node, which is top of stack
 *      Return: (struct stack * ) Element that was on bottom of stack
 * Description: Given the root node, modify the stack by removing the bottommost element and returning it*/
struct stack * popBottom(struct stack ** root);

/*    Function: getBottomPtr
 *   Arguments: (struct stack ** root) Pointer to the root node, which is top of stack
 *      Return: (struct stack *) The pointer to the bottom of stack w/o modifying the stack ;
 * Description: Returns the pointer to the bottom most element w/o modifying the stack  */
struct stack * getBottomPtr(struct stack ** root);

/*    Function: printnext
 *   Arguments: (struct stack ** root) Pointer to the root node, the top of stack ;
 *      Return: (void)
 * Description: Called by the print function, to print all nodes other than the topmost */
void printnext(struct stack ** root);

/*    Function: print
 *   Arguments: (struct stack ** root) Pointer to the pointer that points to the top of stack
 *      Return: (void)
 * Description: Wrapper function, prints the first element and if there is more, then call printnext */
void print(struct stack ** root);

struct stack * pushBottom(struct stack ** root, struct stack * newBottom );
#endif
