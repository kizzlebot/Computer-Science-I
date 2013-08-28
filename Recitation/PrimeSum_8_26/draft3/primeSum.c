/*
 *        Name: James Choi, Rob McCord
 * 	      Date: August 28, 2013 
 *	    Course: Computer-Science I Recitation (10:30AM-11:20AM)
 *  Submission: Recitation Assignment #1 (Prime Sum)
 * Description: This program reads in a file containing a number specifying how many consecutive prime numbers
 *				to sum up, calculates it, and writes to an output file.
 */
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 250 
#define MAX_LIST_SIZE 10000

/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Function Prototypes //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

/* 
 *    Function:   getPrimeList
 *   Arguments:   (int numberOfPrimes) The number of primes to find
 * Description:   Finds and returns a list of prime numbers containing only prime numbers 
 *     Returns:   A struct ListOfPrimes containing only Primes and the number of primes it contains
 */
struct ListOfPrimes * getPrimeList(int numberOfPrimes);

/* 
 *    Function:   getSum
 *   Arguments:   (int * primeList, int sumUpTo) List containing Primes only, number of indexes to sum up to  
 * Description:   Sums the elements of given int array up to given param and returns the sum
 *     Returns:	  (int) the sum of elements in primeList from 0 to sumUpTo
 */
int getSum(int * primeList, int sumUpTo );

/* 
 *    Function:   filterList
 *   Arguments:   (int * aList, int listSize); An array containing numbers, number of elements in given array
 * Description:   Filters the given array, aList, for zeros. Returns a int * containing only primes.
 *     Returns:   An array of size given by number listSize, containing no zeros.
 */
int * filterList(int * aList, int listSize);

/* 
 *    Function:   sieveOfEratosthemes 
 *   Arguments:   (int * aList, int numElements) A array containing numbers, number of elements allocated for given array  
 * Description:   Fill non prime numbers of given array with zeros and returns number of primes found
 *				  The int * is modified but doesn't need to be returned because passed by reference not value
 *     Returns:   (int) An int of the number of elements in given array. As well as changing given array using reference
 */
int  sieveOfEratosthenes(int * aList, int numElements);


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Data Structure //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

/* 
 * Structure Name:  ListOfPrimes
 *    Description:  A data structure that encapsulates an array of primes and
 *	   			    the number of elements in that array
 */
struct ListOfPrimes{
  int * primeList ;
  int numElements ; 
};


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Main Function ///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
int main ( int argc, char *argv[] ){
	/////////////////////////////////
	//////////// GamePlan ///////////
	/////////////////////////////////
	// *.) Set it up 
	// 1.) Get primes
	// 2.) Read/calculate/write 
	// 3.) Pack it up, we outta here
	/////////////////////////////////
	/////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////////// 
	/////////////////////////////////////* Set it up *///////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////// 
	char * infilename ;
	char * outfilename = "primesum.out";

	int readLine  ; 
	int sum ; 

	FILE * infile;
	FILE * outfile;
	struct ListOfPrimes * prime ;

	// Optional File redirection
	if (argc != 2){
		infilename = "primesum.in";
	}else{
		infilename = argv[1];
	}


	///////////////////////////////////////////////////////////////////////////////////////////// 
	////////////////////////////////////////  Get primes  ///////////////////////////////////////  
	///////////////////////////////////////////////////////////////////////////////////////////// 
	
	// Get an struct containing ONLY primes and the number of primes it contains. Its easy
	prime = getPrimeList(MAX_LIST_SIZE);


	///////////////////////////////////////////////////////////////////////////////////////////// 
	////////////////////////////////////  Read/Calculate/Write //////////////////////////////////  
	///////////////////////////////////////////////////////////////////////////////////////////// 
	
	// Open file for reading and open file for writing
	infile  = fopen( infilename, "r" ); 
	outfile = fopen( "primesum.out", "w+" );

	// Read the first line, (We don't really even need to know the number of tests its going to request but w/e)
	fscanf(infile,"%d",&readLine);

	// Read line by line, finding the sum up to what was read, and write to outfile, as long as fscanf isn't EOF.
	while (fscanf(infile,"%d",&readLine)!= EOF){
		sum = getSum(prime->primeList,readLine);
		fprintf(outfile,"%d\n",sum);
	}


	///////////////////////////////////////////////////////////////////////////////////////////// 
	////////////////////////////////  Pack it up, we outta here! ////////////////////////////////  
	///////////////////////////////////////////////////////////////////////////////////////////// 
	
	// Close and exit
	fclose(infile);
	fclose(outfile);

	// Free willy 
	free(prime->primeList);
	free(prime);
	
	// I keep my word.
	return 0 ; 
}


/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Function Definitions /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

struct ListOfPrimes * getPrimeList(int numberOfPrimes){
	int i = 2 ; 
	int j = 2 ;
	int primesFound = 0; 


	// Make an int * aList, with a guessed size. 
	// This is because we don't know what number we 
	// need to go up to to find the 10000th prime number
	int listSize = numberOfPrimes ;  
	int * aList= (int *) malloc(sizeof(int)*listSize);
	// Fill the first two with blanks, so we can start from subscript 2
	aList[0] = 0 ;
	aList[1] = 0 ;
	// Fill all indexes with values from 2 to listSize
	for ( i = 2 ; i < listSize; i++) aList[i] = i ; 
	// Find out how many primes are in the domain [2,listSize] 
	primesFound = sieveOfEratosthenes(aList,listSize) ;


	// When we haven't found the number of primes that was requested, 
	// we will increment the listSize by 250, realloc the array to listSize,
	// fill with numbers, and call the function that returns the number of
	// primes found, until we have a number that is greater than or equal
	// to the number requested. 
	while ( primesFound < numberOfPrimes){
		listSize+=BUFFER_SIZE ; 
		aList = (int *)realloc(aList,sizeof(int)*listSize)	;
		for ( i = 2 ; i < listSize; i++) aList[i] = i ; 
		primesFound = sieveOfEratosthenes(aList,listSize) ;
	}
	
	//^ We now have a array containing elements that are only prime or zero, 
	//  with (listSize) no. of elements and (numberOfPrimes) no. of prime numbers


	// Allocate the struct we will store this array address at
	struct ListOfPrimes * prime = (struct ListOfPrimes *) malloc(sizeof(struct ListOfPrimes));
	// Filter aList for primes and assign to struct's member
	prime->primeList = filterList(aList,listSize);
	// Store the number of primes contained 
	prime->numElements = numberOfPrimes ;	
	// Free the dirty list (aList), we don't need it no more.
	free(aList);
	// Return the goodness
	return prime ; 
}


int getSum(int * primeList, int sumUpTo ){
	int i = 0 ; 
	int sum = 0 ; 
	// Loop from subscript 0 to sumUpTo
	for ( i = 0 ; i < sumUpTo ; i++) sum+=primeList[i] ; 
	// return the sum calculated
	return sum ; 
}


int * filterList(int * aList, int listSize){
	int i = 0 ; 
	int j = 0 ; 
	// Allocate a list to store the prime numbers
	int * primeList = (int *) malloc(sizeof(int)*MAX_LIST_SIZE);	
	// Loop the given list to the end, storing into primeList only
	// elements that are nonzero
	for ( i = 0 ; i < listSize ; i++){
		if (aList[i] != 0){
			primeList[j] = aList[i];
			j++ ; 
		}
		// When we got the max list size we're done, break out
		if ( j == MAX_LIST_SIZE) break ;
	}
	// Return the goodness
	return primeList; 	
}


int sieveOfEratosthenes(int * aList, int numElements){
	int i = 2 ; 
	int j = 2 ; 
	int primesFound = 0 ;

	// Starting from subscript 2, loop while i is less than the given number
	for ( i = 2 ; i < numElements ; ){
		// Starting from j = 2 , loop until i*j is greater than num
		for ( j = 2 ; i*j < numElements ; j++){
			aList[i*j] = 0 ; 
		}
		// Make j equal to the very next index and loop until we find an nonzero element
		j = i+1 ; 
		while ( aList[j] == 0 && j < numElements){
			j++ ; 
		}
		// We found the subscript containing the nonzero element. Make i equal to that
		i = j ;
		// Increment our prime counter
		primesFound++ ; 		
	}
	// Return this array containing only primes and zeros 
	return primesFound;
}


