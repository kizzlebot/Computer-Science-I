/*
 * Name: James Choi
 * Date: August 28, 2013
 * Course: Computer-Science I (10:30AM-11:20AM)
 * Submission: Assignment #1 (Organ Donor)
 * Description: This program reads in a file containing information about patients
 *              on a waiting list for organ transplant, as well as a list of
 *              donated organs. It matches donated organ with compatible
 *              users on the waiting list; writing the result to the output
 *
 **/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

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

organT * findOrganPatientMatch(organT ** patientList, char * organName){
	if ( strcmp(patientList[0]->organname,organName)==0 ){
		return patientList[0];
	}
	findOrganPatientMatch(patientList+1,organName );
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
void printPatient(organT ** patient){
	if (*patient == NULL) return ; 
	printf("\nName: %s",(*patient)->name);
	printf("\nOrgan: %s",(*patient)->organname);
	printf("\nBloodType: %s",(*patient)->bloodtype);
	printf("\nAdded: %d/%d/%d\n",(*patient)->dateAdded.month,(*patient)->dateAdded.day,(*patient)->dateAdded.year);
	printPatient(patient+1);
}
organT ** readPatients(organT ** patient ){
	if ( (*patient)==NULL ) return ; 	
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
		scanf("%s %s %s %d%c%d%c%d %d%c%d",(patient[i]->name),(patient[i]->organname),(patient[i]->bloodtype),
                                                   //  Month            /        Day            /      year
                                                   (&dateAdded.month),(&ch),(&dateAdded.day),(&ch),(&dateAdded.year),
                                                   //    Hour           :      Minute
                                                   (&timeAdded.hour),(&ch),(&timeAdded.minute));
        patient[i]->dateAdded = dateAdded ;
        patient[i]->timeAdded= timeAdded;
		i++ ;
	}

	return patient ;
}
Donor ** readDonorList(){
    int numLines =0;
    int i = 0 ;
    scanf("%d",&numLines);
    Donor ** donorList = (Donor **)malloc(sizeof(Donor*)*(numLines+1));
    while (i < numLines){
        donorList[i] = (Donor *)malloc(sizeof(Donor));
        donorList[i]->organ = (char *)malloc(sizeof(char)*(SIZE+1));
        donorList[i]->bloodType = (char *)malloc(sizeof(char)*(SIZE+1));
        scanf("%s %s",donorList[i]->organ,donorList[i]->bloodType);
        //printf("\nOrgan: %s \nBloodType: %s\n",donorList[i]->organ,donorList[i]->bloodType);
        i++ ;
    }
    donorList[numLines] = NULL;
    return donorList;
}
organtT ** allocateMembers(organtT ** patientList,int numLines){
	if ( numLines == 0 ) return patientList; 
	*patientList = (organT *) malloc(sizeof(organT));
	allocateMembers(patientList-1,numLines-1);
}
int main(){
	int numLines = 0;
	scanf("%d",&numLines);
	organT ** patientList = readPatients(numLines);		
	patientList = (organT **) malloc(sizeof(organT*)*numLines); 
	printPatient(patientList);
}


