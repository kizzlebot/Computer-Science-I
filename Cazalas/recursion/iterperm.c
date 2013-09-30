// Arup Guha
// 1/26/2010
// Iterative Permutation Algorithm that goes through permutations in
// lexicographical order.

#include <stdio.h>

void printPerm(int perm[], int length);
void nextPerm(int perm[], int length);

int main() {

    // Test with this initial permutation.    
    int perm[] = {1,2,3,4,5};
    
    // We know there are exactly 120 of these...
    int i = 0;
    for (i=0; i<120; i++) {
        printPerm(perm, 5);
        nextPerm(perm, 5);
    }
    
    system("PAUSE");
    return 0;
}

// Just prints out the permutation on a single line.
void printPerm(int perm[], int length) {
     
    int i;
    for (i=0; i<length; i++)
        printf("%d ", perm[i]);
    printf("\n");
}
	 
// Changes perm to be the next lexicographical permutation. If none exists,
// then perm remains unchanged. (This only occurs when perm is in 
// descending order.
void nextPerm(int perm[], int length) {
		
    // Find the spot that needs to change.
    int i = length-1;
    while (i>0 && perm[i] < perm[i-1]) i--;
    i--; // Advance to the location that needs to be swapped.
		
    // So last perm doesn't cause a problem.
    if (i == -1) return;
		
    // Find the spot with which to swap index i.
    int j=length-1;
    while (j>i && perm[j]<perm[i]) j--;
		
    // Swap it.
    int temp = perm[i];
    perm[i] = perm[j];
    perm[j] = temp;
		
   // reverse from index i+1 to length-1.
   int k,m;
   for (k=i+1,m=length-1; k<m; k++,m--) {
       temp = perm[k];
       perm[k] = perm[m];
       perm[m] = temp;
    }
}
