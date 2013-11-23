#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int * ithPermutation(const int n, int i){
   int j, k = 0;
   int *fact = (int *)calloc(n, sizeof(int));
   int *perm = (int *)calloc(n, sizeof(int));

   // compute factorial numbers
   fact[k] = 1;
   while (++k < n)
      fact[k] = fact[k - 1] * k;

   // compute factorial code
   for (k = 0; k < n; ++k){
      perm[k] = i / fact[n - 1 - k];
      i = i % fact[n - 1 - k];
   }

   // readjust values to obtain the permutation
   // start from the end and check if preceding values are lower
   for (k = n - 1; k > 0; --k)
      for (j = k - 1; j >= 0; --j)
         if (perm[j] <= perm[k])
            perm[k]++;


   free(fact);
   return perm ; 
}
/* Driver program to test above functions */
int main(){
	int * perm = ithPermutation(5,1);
	int k = 0 ; 
   // print permutation
   for (k = 0; k < 5; ++k)
      printf("%d ", perm[k]);
   printf("\n");
	return 0;
}
