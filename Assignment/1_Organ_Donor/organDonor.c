#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20
#define BLOODTYPESIZE 4


////////////////////////////////////////////////////////////////////
//////////////////////// Data Structures ///////////////////////////
///////////////////////////////////////////////////////////////////
// Date
typedef struct {
	int month;
	int day;
	int year;
} dateT;

// Time
typedef struct {
	int hour;
	int minute;
} timeT;

// Patient on waiting list
typedef struct {
	char * name;
	char * organname;
	char bloodtype[BLOODTYPESIZE];
	dateT dateAdded ;
	timeT timeAdded;
	int received;
} organT;

// Donated Organ
typedef struct {
    char * organ ;
    char * bloodType ;
}Donor ;

////////////////////////////////////////////////////////////////////
///////////////////// Function prototypes  ////////////////////////
///////////////////////////////////////////////////////////////////
organT ** allocate(int numLines);
void printPatient(organT * patient);
organT ** readPatients(FILE * infile);
Donor ** readDonorList(FILE * infile);
void findPair(FILE * outfile, Donor ** donorList , organT ** patient);


int main(){
	FILE * infile = fopen("organ.in","r");
	organT ** patient = readPatients(infile);
    Donor ** donorList = readDonorList(infile);
	FILE * outfile= fopen("organ.out","w");

    findPair(outfile,donorList,patient);
}

void findPair(FILE * outfile, Donor ** donorList , organT ** patient){
    int i = 0 ;
    int j = 0 ;
    int compareLimit = 100 ;
    int result = 0 ;
    while ( donorList[i] != NULL ){
        while ( patient[j] != NULL ){

            if ( strncmp( donorList[i]->organ,patient[j]->organname,compareLimit)==0 && strncmp( donorList[i]->bloodType ,patient[j]->bloodtype,compareLimit)==0 && patient[j]->received != 1 ){
                patient[j]->received = 1 ;
                fprintf(outfile,"%s %s\n",patient[j]->name,donorList[i]->organ);
                j = 0 ;
                break ;
            }
            j++ ;
        }
        if ( patient[j] == NULL ){
            fprintf(outfile,"No match found\n");
        }
        i++ ;
    }
}

organT ** allocate(int numLines){
	organT ** patient = (organT ** )malloc(sizeof(organT *)*(numLines+1));
	int i = 0 ;
	for ( i = 0 ; i < numLines ; i++ ){
		patient[i]  = (organT * )malloc(sizeof(organT ));
		patient[i]->name= (char *)malloc(sizeof(char)*SIZE);
		patient[i]->organname = (char *)malloc(sizeof(char)*SIZE);
		patient[i]->dateAdded.month = 0;
		patient[i]->dateAdded.day= 0;
		patient[i]->dateAdded.year= 0;
		patient[i]->timeAdded.hour = 0;
		patient[i]->timeAdded.minute = 0;
		patient[i]->received = 0 ;
	}
	patient[i] = NULL ;
	return patient ;
}
void printPatient(organT * patient){
	if ( patient != NULL ){
		printf("\nName: %s\n",patient->name);
		printf("Organ: %s\n",patient->organname);
		printf("BloodType: %s\n",patient->bloodtype);
		printf("Added: %d/%d/%d\n",patient->dateAdded.month,patient->dateAdded.day,patient->dateAdded.year);
	}
}
organT ** readPatients(FILE * infile){
	int numLines ;
	// Get the first line
	fscanf(infile,"%d",&numLines);
	// Allocate a pointer of pointers and all the points contained within lol
	organT ** patient = allocate(numLines);

	int i = 0 ;
	// scan an print
	while ( i < numLines ){
        // Make a throwaway variable to hold the characters "/" and ":"
        char ch ;
		// Scan that shit
        dateT dateAdded  ;
        timeT timeAdded  ;
		fscanf(infile,"%s %s %s %d%c%d%c%d %d%c%d",(patient[i]->name),(patient[i]->organname),(patient[i]->bloodtype),
                                                   //  Month            /        Day            /      year
                                                   (&dateAdded.month),(&ch),(&dateAdded.day),(&ch),(&dateAdded.year),
                                                   //    Hour           :      Minute
                                                   (&timeAdded.hour),(&ch),(&timeAdded.minute));
        patient[i]->dateAdded = dateAdded ;
        patient[i]->timeAdded= timeAdded;
		printPatient(patient[i]);
		i++ ;
	}

	return patient ;
}
Donor ** readDonorList(FILE * infile){
    int numLines =0;
    int i = 0 ;
    fscanf(infile,"%d",&numLines);
    Donor ** donorList = (Donor **)malloc(sizeof(Donor*)*(numLines+1));
    while (i < numLines){
        donorList[i] = (Donor *)malloc(sizeof(Donor));
        donorList[i]->organ = (char *)malloc(sizeof(char)*(SIZE+1));
        donorList[i]->bloodType = (char *)malloc(sizeof(char)*(SIZE+1));
        fscanf(infile,"%s %s",donorList[i]->organ,donorList[i]->bloodType);
        printf("\nOrgan: %s \nBloodType: %s\n",donorList[i]->organ,donorList[i]->bloodType);
        i++ ;
    }
    donorList[numLines] = NULL;
    return donorList;
}
