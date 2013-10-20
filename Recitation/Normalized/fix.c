#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack{
    char ch ;
    struct stack * next ;
};


struct stack * alloc(char ch );
struct stack * push(struct stack * root, struct stack * newTop);
struct stack * pop(struct stack ** root);
char   top(struct stack * root);
void printStack(struct stack * root);
void getYourFix(char * aLine);
int getBool(char ch);
char andOr(int aBool,struct stack * top,int count,int oddOrEven);
int findDepth(char * expr, int curDepth);
int main(){
    struct stack * operators = NULL ;
    struct stack * operands = NULL ;
    struct stack * popped = NULL ;

    char * aLine = (char *)malloc(sizeof(char)*500);
    int i = 1 ;
    while (scanf("%s",aLine) != EOF ){
        printf("%d. ",i);
        getYourFix(aLine);
        i++;
    }
    free(aLine);
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
    // If the deepest level is odd then all odd levels are and'd
    if (oddOrEven%2 == 1){
        if (count%2==1) return getBool(top->ch)&&aBool;
        else return getBool(top->ch)||aBool;
    }
    // If the deepest level is even then all even levels are and'd
    else{
        if (count%2==1) return getBool(top->ch)||aBool;
        else return getBool(top->ch)&&aBool;
    }
}
int findDepth(char * expr, int curDepth){
    if (*expr != '\0'){
        int i = 0 ;
        if (*expr == '('){
            i = findDepth(expr+1,curDepth+1);
        }
        else if (*expr == ')'){
            i = findDepth(expr+1,curDepth-1);
        }
        else{
            i = findDepth(expr+1,curDepth);
        }
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
void getYourFix(char * aLine){
    struct stack * aStack ;
    struct stack * popped ;
    int n = 0 ;

    int TorFx =  0 ;

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
                free(pop(&aStack));
                // Everytime a ( is freed, we move up a level
                n-- ;
                // replace with T or F
                aStack = push(aStack,alloc(toChar(TorFx)));
            }
            // Must've been ()
            else{
                // Free (
                free(pop(&aStack));
                n--;
            }
        }
    }
    if ( top(aStack) == 'T'){
        printf("true\n");
        free(pop(&aStack));
    }
    else if ( top(aStack)=='F'){
        printf("false\n");
    }
    else{
        printf("\n");
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

    if (root!=NULL ){
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
void printStack(struct stack * root){
    if (root != NULL){
        printf("%c ",root->ch);
        printStack(root->next);
    }
    else{
        printf("\n");
    }
}
