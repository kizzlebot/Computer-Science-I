#include <stdio.h>
#include <stdlib.h>

int* generatePrime(int n );
void printSum(int* primeList ,int n );
void readFile();
int main(){
	readFile();	
}

void readFile(){
	FILE * infile;
	FILE * outfile;
	// Open file for reading
	infile  = fopen(  "primesum.in",   "r" );
	int temp ; 
	int readLines= 0 ;  
	int * primeList ; 
	while (fscanf(infile,"%d",&temp)!= EOF){
		if ( readLines == 0 ){
			primeList = generatePrime(temp);	
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
	int currentprime = 8	 ; 
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
