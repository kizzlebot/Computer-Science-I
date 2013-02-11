#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char filename[] = "infile.txt";

/*	Each instance of struct Male and Female can be though as a single individual involved in the matchmaking process
	who each have their score of favor for blind date. */
struct male {
	int * score ; 
	char * mName ; 
	int number ; 
	int * min ; 
	int * diff ; 
};
struct female{
	int * score ; 
	char * fName ; 
	int number ; 
};
/*------ This structure sole purpose is to hold the array of pointers of males and array of pointers of females -----*/
struct couple {
	struct male ** men;  // Plural! Because (struct male **), it is like a 'group of males', ie men
	struct female ** ladies ; 
	int * order ;  // holds the order 1 2 3, 1 3 2, 3 2 1 etc

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
int factorial(int n);

void ExchangeMatch(struct female ** ladies, int a, int b) ;
//----------------------------------------------------------------------------------
// (int) n : number of members of each gender, which is equal to the number of couples
// (int) k : lower bound 
// We're going to keep the set of men fixed and permute female order. We will calculate a new 
// Likeability quotient for each permute
//----------------------------------------------------------------------------------
int ind= 0  ; 

int recursiveMatch( struct male ** men, struct female ** ladies,int n, int k ,int  p, int * currLow){
	int j ; 
	int i ;
	

	// Base Case

	if (k == n) {
		int sum = 0  ;
		int diff = 0 ; 
		// compute likeability quotient for given arrangement
		for ( i = 1 ; i < n ; i++){

			//printf("\n%s  (score: %s:%d) <-%d-> %s (score: %s:%d)",ladies[i]->fName,men[i]->mName,ladies[i]->score[i],i,men[i]->mName,ladies[i]->fName,men[i]->score[ladies[i]->number]);
			//printf("\n %s->%s %d",men[i]->mName,ladies[i]->fName, men[i]->score[ladies[i]->number]);
			// if ladies score greater than men's score	
			if ( ladies[i-1]->score[i-1] > men[i-1]->score[ladies[i-1]->number]){
				//men[i-1]->min[ladies[i]->number] = men[i]->score[ladies[i]->number] ; 
				men[i-1]->min[ladies[i-1]->number] = men[i-1]->score[ladies[i-1]->number] ; 
				men[i-1]->diff[ladies[i-1]->number] = ladies[i-1]->score[i-1] - men[i-1]->score[ladies[i-1]->number];

				
			// if ladies score less than men's score	
			}else if ( ladies[i-1]->score[i-1] < men[i-1]->score[ladies[i-1]->score[i-1]]){
				men[i]->min[ladies[i]->number] = ladies[i]->score[i] ; 
				men[i-1]->diff[ladies[i-1]->number] = men[i-1]->score[ladies[i-1]->number] - ladies[i-1]->score[i-1];  

			// all else	
			}else{
				men[i-1]->min[ladies[i-1]->number] = ladies[i-1]->score[i-1] ; // eqal to each other 
				men[i-1]->diff[ladies[i-1]->number] = men[i-1]->score[ladies[i-1]->number] - ladies[i-1]->score[i-1];  				
				
			}
			printf("\n Low: %d, Diff: %d",men[i-1]->min[ladies[i-1]->number],men[i-1]->min[ladies[i-1]->number]);
			sum+=men[i-1]->min[ladies[i-1]->number];
			diff+=men[i-1]->diff[ladies[i-1]->number];
		}
		printf("The sum %d",sum);
		if ( sum < *(currLow) ){
			*currLow = sum ; 
			printf("\nSUM %d: %d",p, *currLow);
			sum = 0 ; 	
		}
		else if (sum == *(currLow)){
		// figure out the least diff
			
			
		}
	}
	else{
		for ( j = k ; j < n; j++){
			ExchangeMatch(ladies,k,j);
			printf("\nSUM %d: %d",p, *currLow);
			//printf("\n%s",ladies[j]->fName);
			recursiveMatch(men,ladies,n,k+1,p+1,currLow);
			ExchangeMatch(ladies,j,k); 
		}
	}
	return *currLow; 
}
/* */

int main(){
	FILE * file = fopen(filename, "r") ; 
	int events, couples ; 	
	fscanf(file, "%d", &events ); // Read first two lines
	fscanf(file, "%d" ,&couples );
	struct couple * coupleSet = readIn(file,couples) ;
	int i = 0 ;
	int j = 0 ; 
	int  low  ;
	low = 20 ;
	low  = recursiveMatch(*&coupleSet->men, coupleSet->ladies,couples,0,0,&(low))  ; 
	printf("\n\n%d",low);
	for ( i = 0 ; i < couples ; i++ ){
		for ( j = 0 ; j < factorial(couples) ; j++){
			printf("\n%s %d, ",coupleSet->men[i]->mName,coupleSet->men[i]->min[j]);	
		} 
	}
}

int factorial(int n){
	int i = 0 ;
	int factorial = 1; 
	for ( i = 1 ; i < n+1 ; i++){
		factorial*=i ; 
	}
	return factorial ; 
}

struct male ** makeMenPtrs(int members) {
	int i = 0 ;
	struct male ** men = malloc(sizeof(struct male *)*members+1);

	for ( i = 0 ; i < members ; i++){
		men[i] = malloc(sizeof(struct male)) ; 
		men[i]->score = malloc(sizeof(int)*members) ; 
		men[i]->mName = malloc(sizeof(char)*10) ; 
		men[i]->min = malloc(sizeof(int)*10 );
		men[i]->diff = malloc(sizeof(int)*10);
		men[i]->number = i ; 
	}
	return men ; 
}
struct female ** makeLadiesPtrs(int members){
	int i = 0 ; 
	struct female ** ladies = (struct female ** )malloc(sizeof(struct female *)*members+1);

	for ( i = 0 ; i < members ; i++){
		ladies[i] = malloc(sizeof(struct female)) ; 
		ladies[i]->score = malloc(sizeof(int)*members) ; 
		ladies[i]->fName = malloc(sizeof(char)*19) ; 
		ladies[i]->number = i ;
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