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

organT ** readPatients(organT ** patientList ,int numLines){
	if ( numLines == 0 )  return patientList ;
	*patientList= (organT *) malloc(sizeof(organT *)) ; 
	char ch ;
	scanf("%s %s %s %d%c%d%c%d %d%c%d",(*patientList)->name,(*patientList)->organname,(*patientList)->bloodtype,
												   //  Month            /        Day            /      year
                                                   (*patientList)->(&dateAdded.month),(&ch),(*patientList)->(&dateAdded.day),(&ch),(*patientList)->(&dateAdded.year),
                                                   //    Hour           :      Minute
                                                   (*patientList)->(&timeAdded.hour),(&ch),(*patientList)->(&timeAdded.minute));
	readPatients(patientList+1,numLines-1);
	return patientList ;
}
int main(){
}
