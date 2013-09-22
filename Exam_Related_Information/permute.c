#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char * word ;
    int length ;
} Set;
typedef struct {
    Set ** set ;
} Sets;
void swap (char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(Set ** set, char *a, int i, int n){
    int j;
    if (i == n  ) printf("%s %s\n",(*set)->word, a,i);
    else{
        for (j = i; j <= n; j++){
            swap((a+i), (a+j));
            permute(set,a, i+1, n);
            swap((a+i), (a+j)); //backtrack
        }
    }
}
/*
 function extend_set (base, sets) {
    if(sets.length === 0) {
        return console.log('found: '+base);
    }
    sets = sets.slice();

    var choices = sets.shift();
    for (var i = 0; i < choices.length; i += 1) {
        var b2 = base.slice();
        b2.push(choices[i]);
        extend_set(b2, sets);
    }
}
 */
Set * pushr( Set * p, char  add ){
    p->word = (char * ) realloc(p->word,p->length+1);
    p->word[p->length] = add;
    p->length=strlen(p->word) ;
    return p;
}
int getLength(char * ch ){
    int i = 0 ;
    while ( *(ch+i) != '\0'){
        i++;
    }
    return i ;
}
char * push( char * ch , char ltr){
    int length = getLength(ch);
    char * c = (char*)malloc(sizeof(char)*(length+1)) ;
    strcpy(c,ch);
    c[length] = ltr ;
    return c ;
}
void extend_set(char * base, Set ** sets, int numSets){
    char * choices = (*sets)->word ;
    if (numSets == 0 ){
        printf("%s\n",(base));
    }
    int i = 0 ;
    int length = getLength(choices);
    //printf("Length %d",length);
    for ( i = 0 ; i < length ; i++){
        char * b2 = push(base,choices[i]);
        extend_set(b2,sets+1,numSets-1);
    }
}
int main(){
    Set ** input = (Set **) malloc(sizeof(Set *)*5) ;
    int i = 0 ;
    for ( i = 0 ; i < 5 ; i++){
        input[i] =(Set *) malloc(sizeof(Set ));
        input[i]->word  =(char*) malloc(sizeof(char)*50);
    }
    strcpy((*(*input)).word, "abc");
    strcpy((*(*(input+1))).word, "def");
    strcpy((*(*(input+2))).word, "ABC");
    (*input)->length = strlen((*input)->word);
    (*(input+1))->length = strlen((*(input+1))->word);
    //permute(sets.set,sets.set[0]->word,0,(*input)->length-1);
    char * base = (char *)malloc(sizeof(char ));;
    //printf("%d",getLength((*input)->word));
    extend_set(base,input,3);
}
