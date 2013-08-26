#include <stdio.h>
#include <stdlib.h>
/*
 * This program calculates the sum of n number of primes 
 *   P(1) = 2
 *	 P(2) = 1+2 = 3
 *	 P(3) = 2+3+5 = 10
 *	 P(4) = 2+3+5+7 = 17
 */

struct readIn* readFile();
void printVar(struct readIn* read);
struct readIn{
  int* read ;
  int size ; 
};

int main(){
  struct readIn * read = readFile();
  printVar(read);
}

struct readIn* readFile(){
  FILE * infile;
  FILE * outfile;
  int BUFFER = 10 ;
  // Open file for reading
  infile  = fopen(  "primes.txt",   "r" );
	int temp ;

  struct readIn* read = malloc(sizeof(struct readIn)) ;
	read->read = malloc(sizeof(int)*BUFFER);
  read->size = BUFFER ; 
  int i = 0 ;  
	while (fscanf(infile,"%d",&temp)!= EOF){
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
void printVar(struct readIn* read){
  int i = 0 ; 
  for ( i = 0 ; i < read->size ; i++){
    printf("%d\n",read->read[i]);
  }
  printf("Size = %d\n",read->size);
}
void nthPrime(int n){
  int p = 10000 ;
  k = 3 ;  
  int i = 1 ; 
  for ( i = 2 ; i < k ;i++){
    if ( k%i == 0 ){
      
    }
  } 
}
