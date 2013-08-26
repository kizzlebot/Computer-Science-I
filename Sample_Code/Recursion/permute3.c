// Arup Guha
// 1/21/2013
// Recursive Permutation algorithm using boolean array.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ListPermutations(int n);
void RecursivePermute(int n, int k, int* perm, int* used);

int main() {

    int n;
    printf("Enter a positive integer.\n");
    scanf("%d", &n);

    // Print out the permutations.
    printf("\nHere are the permutations:\n\n");
    ListPermutations(n);

    return 0;

}

// Pre-condition: 0 < n < 8 (upper limit due to lots of printing)
// Post-condition: All permutations of 0,1,...,n-1 will
//                 be printed.
void ListPermutations(int n) {

    // Set up used and permutation arrays.
    int* used = calloc(n,sizeof(int));
    int* perm = calloc(n,sizeof(int));
    RecursivePermute(n, 0, perm, used);
    free(used);
    free(perm);
}

// Prints out all permutations of 0,1,...,n-1 with the first
// k slots stored in perm and used[i] = 1 if i is in
// perm[0..k-1] and 0 otherwise.
void RecursivePermute(int n, int k, int* perm, int* used) {

     int i;

     // We've filled perm already. Print the corresponding permutation.
     if (k == n) {
        for (i=0; i<n; i++)
            printf("%d ", perm[i]);
        printf("\n");
     }

     // Try each unused number in spot k.
     for (i=0; i<n; i++) {
        if (!used[i]) {
            perm[k] = i;
            used[i] = 1;
            RecursivePermute(n, k+1, perm, used);
            used[i] = 0;
        }
     }

}
