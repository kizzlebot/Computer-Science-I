// Arup Guha
// 8/21/2013
// Solution to COP 3502 Recitation Program #1: Prime Sum
// Note: Problem is adapted from 2010 Mercer Programming Contest problem of the same name.

#include <stdio.h>

#define PRIMELIMIT 1000000
#define NUMPRIMES 10000

int main() {

    int i, j;

    // Dynamically allocate space for the prime sieve.
    int* sieve = calloc(PRIMELIMIT, sizeof(int));

    for (i=0; i<PRIMELIMIT; i++)
        sieve[i] = 1;

    // This is the sieve, without optimization.
    for (i=2; i<PRIMELIMIT; i++)
        for (j=2*i; j<PRIMELIMIT; j+=i)
            sieve[j] = 0;

    // First we'll store the primes in here, then their sums.
    int* primesum = calloc(NUMPRIMES, sizeof(int));

    // i is the number we are checking for primality, j is our index into primesum.
    i = 2;
    j = 0;
    while (j < NUMPRIMES) {

        // We found a prime, copy it into our list.
        if (sieve[i]) {
            primesum[j] = i;
            j++;
        }
        i++;
    }

    // Don't need this array any more.
    free(sieve);

    // This calculates each prime sum successively, building off the previous ones.
    for (i=1; i<NUMPRIMES; i++)
        primesum[i] += primesum[i-1];


    int numCases, n;
    scanf("%d", &numCases);

    // Now, at the end we can quickly process each case.
    for (i=0; i<numCases; i++) {
        scanf("%d", &n);
        printf("%d\n", primesum[n-1]);
    }

    // We don't need this any more.
    free(primesum);

    return 0;
}
