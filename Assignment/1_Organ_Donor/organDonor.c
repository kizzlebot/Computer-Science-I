#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define BLOODTYPESIZE 4



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
	organT * patient = (organT * )malloc(sizeof(organT)*numLines);
	
	int i = 0 ; 
	patient[i]->dateAdded = (dateT *)malloc(sizeof(dateT));
	patient[i]->timeAdded = (timeT *)malloc(size(timeT));
	while ( fscanf(infile,"%d %d %d %d %d %d",patient[i].name,patient[i].organname,patient[i].bloodtype,patient.dateAdded,patient.timeAdded,patient.received)!=EOF){
		i++ ; 
		patient[i]->dateAdded = (dateT *)malloc(sizeof(dateT));
		patient[i]->timeAdded = (timeT *)malloc(size(timeT));
	}
}


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
	char name[SIZE];
	char organname[SIZE];
	char bloodtype[BLOODTYPESIZE];
	dateT dateAdded;
	timeT timeAdded;
	int received;
} organT;

