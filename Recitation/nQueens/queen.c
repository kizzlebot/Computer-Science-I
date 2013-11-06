// Arup Guha
// 1/21/2013
// Recursive Permutation algorithm using boolean array, applied to a string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ListPermutations(char str[]);
void RecursivePermute(char str[], int k, int* perm, int* used);


int main() {

    char word[20];

    // Let the user enter a word to permute.
    printf("Please enter a word you would like to permute.\n");
    scanf("%s", word);

    // Print out the permutations.
    printf("\nHere are the permutations:\n\n");
    ListPermutations(word);

    return 0;

}

// Pre-condition: str is a valid C String.
// Post-condition: All permutations of str (assuming all distinct
// characters) will be printed.
void ListPermutations(char str[]) {

    // Call the appropriate recursive function with the correct
    // parameters.
    int n = strlen(str);
    int* used = calloc(n,sizeof(int));
    int* perm = calloc(n,sizeof(int));
    RecursivePermute(str, 0, perm, used);
    free(used);
    free(perm);
}

// Prints out all permutations of str where the first k
// characters are str[perm[0]], str[perm[1]]...str[perm[k-1]]
// where perm stores the permutation to be printed and used
// stores whether or not each item belongs in perm[0]...perm[k-1].
void RecursivePermute(char str[], int k, int* perm, int* used) {

    int i;

    // We've filled perm already. Print the corresponding permutation.
    if (k == strlen(str)) {
        for (i=0; i<strlen(str); i++)
            printf("%c", str[perm[i]]);
        printf("\n");
    }

    // Try each new item in spot k.
    for (i=0; i<strlen(str); i++) {
        if (!used[i]) {
            perm[k] = i;
            used[i] = 1;
            RecursivePermute(str, k+1, perm, used);
            used[i] = 0;
        }
    }
}
