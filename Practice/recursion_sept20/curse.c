#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void elementPick(char ** ch, int * numSets ){
    if ( (int) (strlen(*ch) % *numSets) == 0 ){
        printf("%s",*ch);
    }
    int i = 0 ;
    for ( i = 0 ; i < *numSets ; i++ ){
        elementPick(ch+1 , numSets+1 );
    }
}
int main(){
    int ** numSets = malloc(sizeof(int *));
    *numSets = malloc(sizeof(int)*3);
    *numSets[0] = 4 ;
    *numSets[1] = 4 ;
    *numSets[2] = 4 ;

    char ** strSets = (char **)malloc(sizeof(char *));
    *strSets = (char *) malloc(sizeof(char)*5);
    strSets[0] = "ABCD";
    strSets[1] = "ABCD";
    strSets[2] = "ABCD";
    elementPick(strSets,*numSets);
}