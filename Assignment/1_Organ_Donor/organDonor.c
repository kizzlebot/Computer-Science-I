#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define BLOODTYPESIZE 4


typedef struct {
	int month;
	int day;
	int year;
} dateT;

typedef struct {
	int hour;
	int minute;
} timeT;

typedef struct {
	char * name;
	char * organname;
	char bloodtype[BLOODTYPESIZE];
	char * dateAdded;
	char * timeAdded;
	int received;
} organT;

organT ** allocate(int numLines){
	organT ** patient = (organT ** )malloc(sizeof(organT *)*(numLines+1));
	int i = 0 ; 
	for ( i = 0 ; i < numLines ; i++ ){
		patient[i]  = (organT * )malloc(sizeof(organT ));
		patient[i]->name= (char *)malloc(sizeof(char)*SIZE);
		patient[i]->organname = (char *)malloc(sizeof(char)*SIZE);
		patient[i]->dateAdded = (char*)malloc(sizeof(char )*SIZE);
		patient[i]->timeAdded = (char *)malloc(sizeof(char )*SIZE);
		patient[i]->received = 0 ;
	}
	patient[i] = NULL ; 
	return patient ; 
}
void printPatient(organT * patient){
	if ( patient != NULL ){
		printf("     Name: %s\n",patient->name);
		printf("    Organ: %s\n",patient->organname);
		printf("BloodType: %s\n",patient->bloodtype);
		printf("    Added: %s\n",patient->dateAdded);
		printf("    tAdded: %s\n\n",patient->timeAdded);

	}
}
int main(){
	// Each line will contain the 
	// person's name 
	// the organ they need replaced
	// their blood type 
	// the date they were added to the organ database 
	// and the time they were added to the organ database	
	FILE * infile = fopen("organ.in","r");
	int numLines ;
	fscanf(infile,"%d",&numLines);

	organT ** patient = allocate(numLines);
	
	int i = 0 ; 
	while ( i < numLines ){
		fscanf(infile,"%s %s %s %s %s",(patient[i]->name),(patient[i]->organname),(patient[i]->bloodtype),(patient[i]->dateAdded),(patient[i]->timeAdded));
		printPatient(patient[i]);
		i++ ; 
	}
}


