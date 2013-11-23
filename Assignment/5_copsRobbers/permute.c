#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct order{
  int * seq ;
  int num ;
  struct order * next ;
  int s[];
};
struct order * ListPermutations(int n, struct order * od );
struct order * RecursivePermute(int n, int k, int* perm, int* used,struct order * od);

struct order * init(int numSeq);
struct order * insert(struct order * root, struct order * ins);
void print(struct order * root);
int main() {

    int n;
    printf("Enter a positive integer.\n");
    scanf("%d", &n);

    // Print out the permutations.
    printf("\nHere are the permutations:\n\n");
    struct order * od ;
    od = ListPermutations(n,od);
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

// Pre-condition: 0 < n < 8 (upper limit due to lots of printing)
// Post-condition: All permutations of 0,1,...,n-1 will
//                 be printed.
struct order * ListPermutations(int n,struct order * od ) {
    // Set up used and permutation arrays.
    int* used = calloc(n,sizeof(int));
    int* perm = calloc(n,sizeof(int));
    od = RecursivePermute(n, 0, perm, used,od);
    free(used);
    free(perm);
    return od ;
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
// Prints out all permutations of 0,1,...,n-1 with the first
// k slots stored in perm and used[i] = 1 if i is in
// perm[0..k-1] and 0 otherwise.
struct order * RecursivePermute(int n, int k, int* perm, int* used,struct order * od){
     int i;
     // We've filled perm already. Print the corresponding permutation.
     if (k == n) {
        struct order * tmp = init(n+1);
        for (i=0; i<n; i++){
          printf("%d ", perm[i]);
          int io = perm[i];
          //tmp->seq[i]=io;
          tmp->seq[i]=perm[i];
        }
        printf("\n");
        od = insert(od,tmp);
     }

     // Try each unused number in spot k.
     for (i=0; i<n; i++) {
        if (!used[i]) {
            perm[k] = i;
            used[i] = 1;
            RecursivePermute(n, k+1, perm, used,od);
            used[i] = 0;
        }
     }
     return od ;
}
