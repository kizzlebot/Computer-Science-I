#include <stdio.h>
#include <string.h>
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
	dateT dateAdded ;
	timeT timeAdded;
	int received;
} organT;
typedef struct {
    char * organ ;
    char * bloodType ;
}Donor ;

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
    char ch = 'c';
	// Get the first line
	fscanf(infile,"%d",&numLines);
	// Allocate a pointer of pointers and all the points contained within lol
	organT ** patient = allocate(numLines);

	int i = 0 ;
	// scan an print
	while ( i < numLines ){
		// Scan that shit
        dateT dateAdded  ;
        timeT timeAdded  ;
		fscanf(infile,"%s %s %s %d%c%d%c%d %d%c%d",
                                       (patient[i]->name),
									   (patient[i]->organname),
									   (patient[i]->bloodtype),
									   (&dateAdded.month),
                                       (&ch),
									   (&dateAdded.day),
                                       (&ch),
									   (&dateAdded.year),

                                       (&timeAdded.hour),
                                       (&ch),
									   (&timeAdded.minute)
                                       );
        patient[i]->dateAdded = dateAdded ;
        patient[i]->timeAdded= timeAdded;
		printPatient(patient[i]);
		i++ ;
	}
    i = 0 ;
	return patient ;
}
Donor ** readDonorList(FILE * infile){
    int numLines =0;
    int i = 0 ;
    fscanf(infile,"%d",&numLines);
    Donor ** donorList = (Donor **)malloc(sizeof(Donor*)*(numLines+1));
    while (i < numLines){
        donorList[i]->organ = (char *)malloc(sizeof(char)*SIZE);
        donorList[i]->bloodType = (char *)malloc(sizeof(char)*SIZE);
        fscanf(infile,"%s %s",donorList[i]->organ,donorList[i]->bloodType);
        printf("\nOrgan: %s BloodType: %s",donorList[i]->organ,donorList[i]->bloodType);
        i++ ;
    }
    donorList[i] = NULL;
    return donorList;
}
void findMatch(Donor ** donorList,organT ** patient ,FILE * outfile){
    int i = 0 ;
    int j = 0 ;
   while ( patient[i] != NULL ){
       while (patient[i]->organname != donorList[j]->organ && patient[i]->bloodtype != donorList[j]->bloodType ){
           if (donorList[j+1] == NULL){
              fprintf(outfile,"%s has no match\n",patient[i]->name);
              j++ ;
              break ;
           }
           j++ ;
       }
       if (patient[j] != NULL){
          fprintf(outfile,"%s has match\n with %s %s\n",patient[i]->name, donorList[j]->organ,donorList[j]->bloodType);
       }
       j = 0 ;
       i++ ;
   }
}
int main(){
	FILE * infile = fopen("organ.in","r");
	organT ** patient = readPatients(infile);
    Donor ** donorList = readDonorList(infile);
	FILE * outfile= fopen("organ.in","w+");
    findMatch(donorList,patient,outfile);
}


