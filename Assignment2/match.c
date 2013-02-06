#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char filename[] = "infile.txt";

struct male {
	int * score ; 
	char * mName ; 
};
struct female{
	int * score ; 
	char * fName ; 
};
struct couple {
	struct female ** ladies ; 
	struct male ** men; 
};
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
	struct female ** ladies = malloc(sizeof(struct female *)*members+1);
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

int main(){
	FILE * file = fopen(filename, "r") ; 
	int events, couples ; 
	int j = 0 ; 
	int i = 0 ;
	fscanf(file, "%d", &events ); // Read first two lines
	fscanf(file, "%d" ,&couples );
	
	struct couple * coupleSet = readIn(file,couples) ; 
	
	
}