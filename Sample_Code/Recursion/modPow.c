// Arup Guha
// 9/6/2013
// Modular Exponentiation written with longs.
// Note: Even though we use 64 bit ints, base can't exceed 2^31-1 due to overflow issues.

#include <stdio.h>
#include <time.h>

long long modPowSlow(long long base, long long exp, long long mod);
long long modPowFast(long long base, long long exp, long long mod);

int main() {

    // Business as usual...if exp is high enough, this will be slower than congress...
    int start = time(0);
    long long ans = modPowSlow(109823232L, 300000000L, 987654321L);
    int end = time(0);
    printf("Answer = %lld in %d seconds.\n", ans, end-start);

    // Amazing what a bit of divide and conquer can yield for us.
    start = time(0);
    long long ans2 = modPowFast(109823232L, 300000000L, 987654321L);
    end = time(0);
    printf("Answer = %lld in %d seconds.\n", ans2, end-start);

    return 0;
}

// This how we did this in Intro to C...
long long modPowSlow(long long base, long long exp, long long mod) {

    long long ans = 1;
    long long i;
    for (i=0; i<exp; i++)
        ans = (ans*base)%mod;
    return ans;
}

// Recursive function that quickly calculates base^exp mod mod.
long long modPowFast(long long base, long long exp, long long mod) {

    // Key base case.
    if (exp == 0) return 1;

    // Even case is where we get all of our time savings.
    if (exp%2 == 0) {
        long long mysqrt = modPowFast(base, exp/2, mod);
        return (mysqrt*mysqrt)%mod;
    }

    // This typical recursion is the similar to what happens in the slow version.
    return (base*modPowFast(base, exp-1, mod))%mod;
}

