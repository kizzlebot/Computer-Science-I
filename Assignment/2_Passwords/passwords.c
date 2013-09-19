#include <stdio.h>
#include <stdlib.h>
/**
 *  {b,c,d,a}
 *  {a,b,c}
 *  {t,e,r,k}
 */
char ** alloc( char * ch, int * setLengths ){
    int max_size = 10 ;
    char ** dblArray = (char ** )malloc(sizeof(char *)*max_size);
    int i = 0 ;
    while ( setLengths[i] != '\0'){
        int j = 0 ;

        dblArray[i] = (char *)malloc(sizeof(char)*(setLengths[i]+1));
        for ( j =0 ; j < setLengths[i] ; j++){
            if ( ch[j] != '\0'){
                dblArray[i][j] = ch[j] ;
            }
            else{
                dblArray[i] = (char *)realloc(dblArray[i],(j+1));
                dblArray[i][j] = '\0';
                break;
            }
        }
        if ( j < setLengths[i] ){
            continue ;
        }
        else{
            dblArray[i][setLengths[i]] = '\0' ;
        }
        i++ ;
        if ( i >= max_size ){
            max_size*=2 ;
            char ** dblArray = (char ** )malloc(sizeof(char *)*max_size);
        }
    }
    return dblArray ;

}

void printList(char ** list){
    int i = 0 ;
    while ( list[i] != '\0'){
        int j =0 ;
        printf("Set #%d: ",i);
        while (list[i][j] != '\0'){
            printf("%c ",list[i][j]);
            j++ ;
        }
        printf("\n");
        i++ ;
    }
}
void extend_sets(char * base , char ** set,int n,int k){
    if ( set[n][k] == '\0'){
        printf("%s\n",set[n]);
    }
    else{
        char c = set[n][k] ;
        int i = 0  ;
        for ( i = 0 ; i <= k ; i++){
        }
    }
}

int main(){
    int * in = (int *) malloc(sizeof(int)*20);
    in[0] = 4;
    in[1] = 3;
    in[2] = 4;
    in[3] = 3;
    char ** ch = alloc( "BLAHBLAHBLAHBLAH", in);
    printList(ch);

}