// Arup Guha
// Written in COP 3502 to illustrate the use of bitwise operators
// 7/17/2012
// Uses a bitmask to solve a small instance of subset sum.
// Uses a different strategy than the previous example.

#include <stdio.h>

#define MAX 20

int main() {

    FILE* ifp = fopen("subset.txt", "r");

    int numbers[MAX];

    int numCases;
    fscanf(ifp, "%d",  &numCases);

    // Go through each test case.
    int loop;
    for (loop=0; loop<numCases; loop++) {

        // Read in the target and numbers for this case.
        int n, target;
        fscanf(ifp, "%d%d", &n, &target);

        int i;
        for (i=0; i<n; i++)
            fscanf(ifp, "%d", &numbers[i]);

        // Try each set.
        int mask;
        int answer = 0;
        for (mask=0; mask< (1<<n); mask++) {

            // Trying set denoted by mask.
            int sum = 0;

            // Here I don't change the mask, rather I change which bit I look at
            // in the mask.
            int index;
            for (index=0; index<n; index++) {
                if ( (mask & (1 << index)) == (1 << index))
                    sum += numbers[index];
            }

            // Prints out this mask if it's a solution.
            if (sum == target) {
                answer = 1;
                printf("Matched with mask %d\n", mask);
            }

        }

        // Indicates no solutions.
        if (answer == 0)
            printf("Sorry no solution found.\n");

        printf("\n");

    }

    fclose(ifp);
}
