#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** init(int n);
int main(){
  int N ;
  int numProbs ;
  scanf("%d",&numProbs);

  int i = 0  ;
  for ( i = 0 ; i < numProbs ; i++){
    scanf("%d",&N);
    char ** board = init(N);
    int j = 0 ;
    for ( j = 0 ; j < N ; j++ ){
      scanf("%s",*(board+j));
    }
    if (analyze(board,int n )){
      printf("True");
    }
    else{
      printf("false");
    }
  }
}

int analyze(char ** board, int n ){
  int i,j;
  for ( i = 0 ; i < n ; i++){
    // get number of solids in this row
    char * first = strchr(*(board+i),'*');

    // get pointer to first occurance of solid

  }
}
char ** init(int n){
  char ** board = (char **)calloc(n,sizeof(char *));
  int i = 0 ;
  for ( i = 0 ; i < n ; i++){
    board[i] = (char *)calloc(n,sizeof(char));
  }
}


