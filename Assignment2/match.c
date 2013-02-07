#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char filename[] = "infile.txt";

/*	Each instance of struct Male and Female can be though as a single individual involved in the matchmaking process
	who each have their score of favor for blind date. */
struct male {
	int * score ; 
	char * mName ; 
};
struct female{
	int * score ; 
	char * fName ; 
};
/*------ This structure sole purpose is to hold the array of pointers of males and array of pointers of females -----*/
struct couple {
	struct male ** men;  // Plural! Because (struct male **), it is like a 'group of males', ie men
	struct female ** ladies ;  
};
/*----------------------------------------------------------------------------------
//  Function: makejjMenPtrs
//  Arguments: (int) members - Number people of each gender
//  Return type:  (struct male **) 
//  Description:  Allocates and returns (struct male ** ) which is essentially an array of pointers ( struct male *).  
//                The number of elements of the struct male ** is the number of members of the gender male.
//				  And since the number of members is also the number of scores each male has to have for each female,
//				  the 'score' integer array is also allocated.
----------------------------------------------------------------------------------*/
struct male ** makeMenPtrs(int members) ;
/*----------------------------------------------------------------------------------
//  Function: makeLadiesPtrs
//  Arguments: (int) members - Number people of each gender
//  Return type:  (struct female **) 
//  Description:  Allocates and returns (struct female ** ) which is essentially an array of the pointer type ( struct female *).  
//                The number of elements of the struct female ** is the number of members of the gender female.
//				  And since the number of members is also the number of scores each female has to have for each female,
//				  the 'score' integer array is also allocated.
----------------------------------------------------------------------------------*/
struct female ** makeLadiesPtrs(int members);
/*----------------------------------------------------------------------------------
//  Function: readIn
//  Arguments: (File * )file, (int) couples
//  Return type:  (struct female **) 
//  Description:  Reads file line by line and splits up the information and assigns to 
// 				  Uses the information read to call makeMenPtrs and makeLadiesPtrs with 
//				  parameter of members to allocate correct sizes and returns
//
----------------------------------------------------------------------------------*/
struct couple * readIn(FILE * file, int couples);
char * removeNewLine(char * str);


void ExchangeMatch(struct female ** ladies, int a, int b) ;
//----------------------------------------------------------------------------------
// (int) n : number of members of each gender, which is equal to the number of couples
// (int) k : lower bound 
// We're going to keep the set of men fixed and permute female order. We will calculate a new 
// Likeability quotient for each permute
//----------------------------------------------------------------------------------
int ind= 0  ; 
void recursiveMatch( struct male ** men, struct female ** ladies, int n, int k ){
	int j ; 
	int i ;
	// Base Case
	if (k == n) {
		// compute likeability quotient for given arrangement
		printf("\n\n");
		for ( i = 0 ; i < n ; i++ ){
			printf("%s, ",ladies[i]->fName);
		}
		printf("\n");
		for ( i = 0 ; i < n ; i++ ){
			printf("%s, ",men[i]->mName);
		}
		
	}else{
		for ( j = k ; j < n; j++){
			ExchangeMatch(ladies,k,j);
			printf("%d %d",j,k);
			recursiveMatch(men,ladies,n,k+1);

			ExchangeMatch(ladies,j,k); 
		}
	}
}
/* */

int main(){
	FILE * file = fopen(filename, "r") ; 
	int events, couples ; 
	fscanf(file, "%d", &events ); // Read first two lines
	fscanf(file, "%d" ,&couples );
	struct couple * coupleSet = readIn(file,couples) ;
	int i = 0 ; 

	recursiveMatch(coupleSet->men, coupleSet->ladies, couples, 0) ; 
	//for ( i = 0 ; i < couples ; i++ ){
	//	printf("%s, ",coupleSet->ladies[i]->fName);	
	//}
}



struct male ** makeMenPtrs(int members) {
	int i = 0 ;
	struct male ** men = malloc(sizeof(struct male *)*members+1);
	men[members+1] = NULL ; 
	for ( i = 0 ; i < members ; i++){
		men[i] = malloc(sizeof(struct male)) ; 
		men[i]->score = malloc(sizeof(int)*members) ; 
		men[i]->mName = malloc(sizeof(char)*19) ; 
	}
	return men ; 
}
struct female ** makeLadiesPtrs(int members){
	int i = 0 ; 
	struct female ** ladies = (struct female ** )malloc(sizeof(struct female *)*members+1);
	ladies[members+1] = NULL ; 
	for ( i = 0 ; i < members ; i++){
		ladies[i] = malloc(sizeof(struct female)) ; 
		ladies[i]->score = malloc(sizeof(int)*members) ; 
		ladies[i]->fName = malloc(sizeof(char)*19) ; 
	}
	return ladies ; 
}
struct couple * readIn(FILE * file, int couples){
	
	int i = 0 ; 
	int j = 0 ; 

	struct male ** men = makeMenPtrs(couples);
	struct  female ** ladies = makeLadiesPtrs(couples);

	// We're gonna read two entire lines and use strtok to separate by whitespace
	for ( j = 0 ; j < couples ; j++){
		fscanf(file,"%s",men[j]->mName);
		removeNewLine(men[j]->mName);
	}
	for ( j = 0 ; j < couples ; j++){
		fscanf(file, "%s", ladies[j]->fName) ; 
		removeNewLine(ladies[j]->fName);
	}


	for ( j = 0 ; j < couples ; j++){
		for ( i = 0 ; i < couples ; i++ ){
			fscanf(file,"%d",&men[j]->score[i]);
			//printf("%d ",men[j]->score[i]) ; 
		}

	}
	for ( j = 0 ; j < couples ; j++){
		for ( i = 0 ; i < couples ; i++ ){
			fscanf(file,"%d",&ladies[j]->score[i]);
			//printf("%d ",ladies[j]->score[i]);
		}

	}
	struct couple * cpl = malloc(sizeof(struct couple));
	cpl->men = men ; 
	cpl->ladies = ladies ; 


	return cpl ; 
}
void ExchangeMatch(struct female ** ladies, int a, int b) {
	struct female * templady = malloc(sizeof(struct female )) ; 
	templady = ladies[a];
	ladies[a] = ladies[b] ; 
	ladies[b] = templady ; 
	free(templady) ; 
}
char * removeNewLine(char * str){
	int j = 0 ; 
	for( j = 0 ; j < strlen(str) ; j++)
	{
		if ( str[j] == '\n')
		{
			str[j] = '\0' ; 
		}
	}
	return str ; 
}