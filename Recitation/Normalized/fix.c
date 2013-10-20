/* Name:       James Choi, Robert McCord
 * Date:       October 20, 2013
 * Course:     Computer Science-I 9:00AM (Mon,Wed,Fri)
 * Assignment: Recitation Project #4
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack{
    char ch ;
    struct stack * next ;
};

/* Function: alloc
 * Parameters: (char ch)
 * Description: Allocates a new node with member ch and next pointed to NULL  */
struct stack * alloc(char ch );

/* Function: push
 * Parameters: (struct stack * root),(struct stack * newTop)
 * Returns:    (struct stack *) New root
 * Description: Puts newTop before root and returns the new root */
struct stack * push(struct stack * root, struct stack * newTop);

/* Function: pop
 * Parameters: (struct stack * root)
 * Returns:    (struct stack *) Element removed from top of stack
 * Description: Modifies root pointer by changing the root to be the second, and then returns the removed element*/
struct stack * pop(struct stack ** root);

/* Function: top
 * Parameters: (struct stack * root)
 * Returns: N/A
 * Description: Returns the char contained in the root node, without modifying the tree */
char   top(struct stack * root);

/* Function: getYourFix
 * Parameters: (char * aLine),(int caseNum)
 * Returns: N/A
 * Description: Evalaluates the given expression with the most inner expression being an AND and it's outer being an Or and vice versa */
void getYourFix(char * aLine, int caseNum);

/* Function: getBool
 * Parameters: (char ch )
 * Returns: (int) Either 1 or 0 representing true and false respectfully
 * Description: Returns the integer representation of given character 'T' or 'F' */
int getBool(char ch);

/* Function: toChar
 * Parameters: (int i )
 * Returns:    (char)   'T' or 'F'
 * Description: Returns the char representation of given int 0 or 1  */
char toChar(int i);

/* Function:    andOr
 * Parameters:  (int aBool)            Expression argument #1, boolean in integer form
 *              (struct stack * top)   Expression argument #2, struct containing a char representing boolean
 *              (int count)            Level of expression enclosure
 *              (int oddoreven)        This number is the deepest level of enclosed expression, used to determine whether to AND or OR the two parameters given
 * Returns:     (char ) Returns 'T' or 'F'
 * Description: Given the deepest level of the entire expression, and the level of the given subexpression, this function determines whether to AND or OR the two params  */
char andOr(int aBool,struct stack * top,int count,int oddOrEven);

/* Function:    findDepth
 * Parameters:  (char * expr)   String (char *) holding the entire expression
 *              (int curDepth)  Used to keep track of largest depth in recursive calls
 * Returns:     (int )          Integer representing the deepest level of enclosed subexpression in given expression
 * Description: Finds deepest level of subexpression of the entire expression */
int findDepth(char * expr, int curDepth);


int main(){
    char * aLine = (char *)malloc(sizeof(char)*500);
    int i = 1 ;
    // While we have more stuff in stream, read it and calculate it
    while (!feof(stdin) && scanf("%s",aLine)==1){
        getYourFix(aLine,i);
        i++ ;
    }
}

int getBool(char ch){
    if (ch == 'F'){
        return 0 ;
    }
    else{
        return 1 ;
    }
}
char andOr(int aBool,struct stack * top,int count,int oddOrEven){
    // If the deepest level is odd then all odd levels are and'd, and all evens are OR'd
    if (oddOrEven%2 == 1){
        if (count%2==1) return getBool(top->ch)&&aBool;
        else return getBool(top->ch)||aBool;
    }
    // If the deepest level is even then all even levels are and'd, and all odds or OR'd
    else{
        if (count%2==1) return getBool(top->ch)||aBool;
        else return getBool(top->ch)&&aBool;
    }
}
int findDepth(char * expr, int curDepth){
    if (*expr != '\0'){
        int i = 0 ;
        // Every opening parenthesis is a level more than the currentDepth
        if (*expr == '('){
            i = findDepth(expr+1,curDepth+1);
        }
        // Every closing parenthesis is a level less than the currentDepth
        else if (*expr == ')'){
            i = findDepth(expr+1,curDepth-1);
        }
        // Otherwise it's a letter "T" or "F"
        else{
            i = findDepth(expr+1,curDepth);
        }
        // pass the highest value to the bottom of the call stack
        if ( i > curDepth) return i ;
        else return curDepth ;
    }
    else{
        return curDepth;
    }
}
char toChar(int i){
    if (i == 1){
        return 'T';
    }
    else{
        return 'F';
    }
}
void getYourFix(char * aLine, int caseNum){
    struct stack * aStack ;
    struct stack * popped ;
    int n = 0 ;
    
    int TorFx =  0 ;
    // Find out how deep is the deepest subexpression in the given line
    int oddOrEven = findDepth(aLine,0);
    int i = 0 ;
    for ( i = 0 ; i < strlen(aLine) ; i++ ){
        if ( aLine[i] != ')'){
            if ( aLine[i] == '('){
                n++ ;
            }
            // Keep pushing everything preceding a )
            aStack = push(aStack,alloc(aLine[i]));
        }
        // Encountered a )
        else{
            // If at least one T or F precedes )
            if (top(aStack)!='(' ){
                // If control reaches here, we must've had T)
                popped = pop(&aStack);
                TorFx = getBool(popped->ch);
                // free(popped);
                while (top(aStack)!='('){
                    popped = pop(&aStack);
                    TorFx = andOr(TorFx,popped,n,oddOrEven);
                    // free(popped); // get rid of T or F
                }
                // Free (
                // free(pop(&aStack));
                pop(&aStack);
                // Everytime a ( is freed, we move up a level
                n-- ;
                // replace with T or F
                aStack = push(aStack,alloc(toChar(TorFx)));
            }
            // Must've been ()
            else{
                // Free (
                pop(&aStack);
                n--;
            }
        }
    }
    // When control reaches here, we should have a stack containing only a single 'T' or 'F', otherwise, a () was given
    if ( top(aStack) == 'T'){
        printf("%d. true\n",caseNum);
    }
    else if ( top(aStack)=='F'){
        printf("%d. false\n",caseNum);
    }
    else{
        printf("");
    }
}

struct stack * alloc(char ch){
	struct stack * new = (struct stack *) malloc(sizeof(struct stack));
	new->next = NULL ;
    new->ch = ch ;
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
    struct stack * tmp;
    tmp = NULL ;
    
    if (*root != NULL ){
        tmp = (*root);
        (*root)=(*root)->next;
        tmp->next = NULL ;
    }
    return tmp ;
}
char top(struct stack * root){
    char ch ;
    if ( root != NULL ){
        ch = root->ch ;
        return ch ;
    }
    else return '\0';
}
