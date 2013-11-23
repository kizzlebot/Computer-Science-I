#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct order{
  int * seq ;
  int num ;
  struct order * next ;
  int s[];
};

struct order * init(int numSeq);
struct order * insert(struct order * root, struct order * ins);
void print(struct order * root);

int main() {


    return 0;
}

void print(struct order * root){
  if (root == NULL ) return ;
  else{
    int i = 0 ;
    for ( i = 0 ; i < root->num ; i++){
      printf("%d ",root->seq[i]);
    }
    printf("\n");
    print(root->next);
  }
}

struct order * init(int numSeq){
  struct order * od = (struct order *)malloc(sizeof(struct order));
  od->seq=(int *)malloc(sizeof(int)*(numSeq+1));
  od->num = numSeq;
  od->next = NULL;
  return od ;
}
struct order * insert(struct order * root, struct order * ins){
  if ( root==NULL) return ins ;
  else{
    root->next = insert(root->next,ins);
    return root ;
  }
}
