#include <stdio.h>
#include <stdlib.h>

int* generatePrime(int n );
void printSum(int* primeList ,int n );
int * sieveOfEratosthenes(int numPrimesToFind);
void readFile();
int main(){
	readFile();	
}
int * sieveOfEratosthenes(int numPrimesToFind){
	int i = 0 ;
	int j = 0 ;
	int * consecutive = malloc(sizeof(int)*(numPrimesToFind+1));

	// Fill up the first two indexes with whatevers bc if its zero, it doesn't matter
	consecutive[0] = 0 ;
	consecutive[1] = 0 ;
	// start getting rid of all multiples
	for ( i = 2 ; i < numPrimesToFind; ){
		// Only fill up to numPrimesToFind if first iteration
		if ( i == 2 ){
			j = i ;
			for ( j = i ; j < numPrimesToFind; j++){
				consecutive[j] = j ;
			}
		}
		// Make everything that is a multiple of inner j times outer i equal zero
		for ( j = 2 ;i*j < numPrimesToFind; j++){
			consecutive[i*j] = 0 ;
		}
		// Put the cursor in the very next index regardless of whether its zero or not
		// and keep incrementing until we find a index containing a nonzero
		j = i+1 ;
		while ( consecutive[j] == 0 && j < numPrimesToFind){
			j++;
		}
		// By the time control is here, it would've had a reason to break out
		i = j ;
	}

	// Reset J and use it to count the number of primes
	j = 0 ;
	for ( i = 0 ; i< numPrimesToFind; i++){
		if ( consecutive[i] != 0 ){
			j++ ;
		}
	}
	// Use the count to malloc that exact size
	int * primesOnly = malloc(sizeof(int)*(j+1));
	j = 0 ;
	for ( i = 0 ; i < numPrimesToFind; i++){
		if (consecutive[i] != 0 ){
			primesOnly[j] = consecutive[i] ;
			j++ ;
		}
	}
	free(consecutive);
	//for ( i = 0 ; i < j; i++ ){
		// printf("%d\n",primesOnly[i]);
		//}
	return primesOnly ;
}
void readFile(){
	FILE * infile;
	FILE * outfile;
	// Open file for reading
	infile = fopen( "primesum.in", "r" );
	int temp ;
	int readLines= 0 ;
	int * primeList ;
	while (fscanf(infile,"%d",&temp)!= EOF){
		if ( readLines == 0 ){
			primeList = sieveOfEratosthenes(temp*2);	
		}
		else{
			printSum(primeList,temp);
		}
		readLines++;	
	}	
}


void printSum(int* primeList ,int n ){
	int i = 0 ;
	int sum = 0 ;
	for ( i = 0 ; i < n ; i++){
		sum+=primeList[i] ;
	}
	printf("%d\n",sum);
}
int* generatePrime(int n ){
	int i ;
	int j ;
	int nthprime = n;
	int currentprime = 8	;
	int* primelist = malloc(sizeof(int)*nthprime) ;
	// put a couple of primes in
	primelist[0] = 2;
	primelist[1] = 3;
	primelist[2] = 5;
	primelist[3] = 7;
	//
	for ( i = 3 ; i < nthprime ;){
		for ( j = 2 ; j < currentprime ; j++){
			if ( currentprime%j == 0 ){
				break ;
			}
		}
		if ( j == currentprime ){
			i++;
			primelist[i] = currentprime ;
		}
		currentprime++ ;
	}
	return primelist;
}
