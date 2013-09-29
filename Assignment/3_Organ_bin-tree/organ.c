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

void printPatient(organT ** patientList){
	if ( *patientList == NULL ){
		return ; 
	}
	printf("name %s\n",(*patientList)->name);
	printf("organ:%s\n",(*patientList)->organname);
	printf("bloodtype:%s\n",(*patientList)->bloodtype);
	printf("DateAdded:%d/%d/%d\n",(*patientList)->dateAdded.month,(*patientList)->dateAdded.day,(*patientList)->dateAdded.year);
	printf("TimeAdded:%d:%d\n\n",(*patientList)->timeAdded.hour,(*patientList)->timeAdded.minute);
	printPatient(patientList+1);
}

void read(int count ,organT ** patientList ){
	if (count == 0 ){
		return ; 
	}
	char ch ; 
	*patientList = (organT *)malloc(sizeof(organT));
	(*patientList)->name = (char *) malloc(sizeof(char)*26);
	(*patientList)->organname = (char *) malloc(sizeof(char)*26);
	scanf("%s %s %s %d%c%d%c%d %d%c%d",((*patientList)->name),((*patientList)->organname),((*patientList)->bloodtype),
								   //  Month            /        Day            /      year
								   &((*patientList)->dateAdded.month),(&ch),&((*patientList)->dateAdded.day),(&ch),&((*patientList)->dateAdded.year),
								   //    Hour           :      Minute
								   &((*patientList)->timeAdded.hour),(&ch),&((*patientList)->timeAdded.minute));
	read(count-1,patientList+1);

}

int main(){
	int numPatients ; 
	scanf("%d",&numPatients);
	organT ** patientList = (organT **)malloc(sizeof(organT*)*(numPatients+1));
	read(numPatients,patientList);
	printPatient(patientList);
}
