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
	int * consecutive = malloc(sizeof(int)*(numPrimesToFind+5));
	
	// Fill up the first two indexes with whatevers bc if its zero, it doesn't matter
	consecutive[0] = 2 ;
	consecutive[1] = 3 ; 
	// start getting rid of all multiples 
	for ( i = 2 ; i < numPrimesToFind;  ){
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
		while ( consecutive[j] == 0 && j <= numPrimesToFind){
			j++;
		}
		// By the time control is here, it would've had a reason to break out
		i = j ;
	}

	// Reset J and use it to count the number of primes
	j = 0 ; 
	for ( i = 2  ; i< numPrimesToFind+5; i++){
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
	for ( i = 0 ; i < j; i++ ){
		//printf("%d\n",primesOnly[i]);
	}
	return primesOnly ; 
}
void readFile(){
	FILE * infile;
	FILE * outfile = fopen( "primesum1.out" , "w");
	// Open file for reading
	infile = fopen("primesum.in","r");
	int temp ; 
	int readLines= 0 ;  
	int * primeList ; 
	while (fscanf(infile,"%d",&temp)!= EOF){
		if ( readLines == 0 ){
			primeList = sieveOfEratosthenes(temp);	
			readLines++;	
			continue ; 
		}else{
			printSum(primeList,temp);
		}
	}			
}
void printSum(int* primeList ,int n){
	int i  ;
	int sum = 0 ;  
	for ( i = 0 ; i < n ; i++){
		sum+=primeList[i] ; 	
	}
	printf("%d\n",sum);
	//fprintf(outfile,"%d\n",sum);
}
