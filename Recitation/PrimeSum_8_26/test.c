#include <stdio.h>

#define LIMIT 1500000 /*size of integers array*/
#define PRIMES 100000 /*size of primes array*/

int main(){
int i,j,numbers[LIMIT];
int primes[PRIMES];

/*fill the array with natural numbers*/
for (i=0;i numbers[i]=i+2;
}

/*sieve the non-primes*/
for (i=0;i if (numbers[i]!=-1){
for (j=2*numbers[i]-2;j numbers[j]=-1;
}
}

/*transfer the primes to their own array*/
j = 0;
for (i=0;i if (numbers[i]!=-1)
primes[j++] = numbers[i];

/*print*/
for (i=0;i printf("%dn",primes[i]);

return 0;
}