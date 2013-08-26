#include <stdio.h>
#include <stdlib.h>

struct readIn* readFile();

int* nthPrime(int n);
void printVar(struct readIn* read);
void printPrimeSum (struct  readIn * read);
struct readIn{
	int* read ;
	int size ; 
	int largest;
};

int main(){
	struct readIn * read = readFile();
	//printVar(read);
	//int * x = nthPrime(20000);
	printPrimeSum(read);
}

struct readIn* readFile(){
	FILE * infile;
	FILE * outfile;
	int BUFFER = 10 ;
	// Open file for reading
	infile  = fopen(  "primesum.in",   "r" );
	int temp ;

	struct readIn* read = malloc(sizeof(struct readIn)) ;
	read->read = malloc(sizeof(int)*BUFFER);
	read->size = BUFFER ; 
	int i = 0 ;  
	read->largest = 1 ; 
	while (fscanf(infile,"%d",&temp)!= EOF){
		if (temp > read->largest ){
			read->largest = temp ; 
		}
		read->read[i] = temp;
		i++ ;
		if ( i == BUFFER ){
			  BUFFER=BUFFER+10;
			  read->read = realloc(read->read,BUFFER);
		}
	}			
	read->size = i ; 
	read->read = realloc(read->read,read->size);
	return read ; 
}

void printPrimeSum (struct readIn * read){
	int i = 0 ;
	int sum = 0 ;
	int j = 0 ; 	 
	int * primeList = nthPrime(read->largest);	
	for ( i = 0 ; i < read->size ; i++){
		for ( j = 0 ; j < read->read[i] ; j++){
			sum+=primeList[j] ; 				
		}
		printf("%d\n",sum);
		sum = 0 ; 
		free(primeList);
	}
}
void printVar(struct readIn* read){
	int i = 0 ; 
	for ( i = 0 ; i < read->size ; i++){
		printf("%d\n",read->read[i]);
	}
	printf("Size = %d\n",read->size);
}
int* nthPrime(int n){
	int nthPrime = n; 
	int currentPrime = 6 ; 
	int* primeList = malloc(sizeof(int)*nthPrime) ; 
	int i, j ; 
	primeList[0] = 1;
	primeList[1] = 2;
	primeList[2] = 3;
	primeList[3] = 5;
	if ( n < 5 ){
		return primeList ; 	
	}
	else{	
		for ( i = 3 ; i < nthPrime ;){
			for ( j = 2 ; j < currentPrime ; j++){
				if ( currentPrime%j == 0 ){
					break ; 
				}
			}
			if ( j == currentPrime ){
				i++;
				primeList[i] = currentPrime ; 
				//printf("%d\n",primeList[i]);
			}
			currentPrime++ ; 
		}
	}
}
