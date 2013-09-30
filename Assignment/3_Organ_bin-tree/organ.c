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
struct Node {
    organT patient;
    struct Node * left ;
    struct Node * right ;
} ;

void printPatient(organT * patientList){
	if ( patientList == NULL ){
		return ;
	}
	printf("name %s\n",(patientList)->name);
	printf("organ:%s\n",(patientList)->organname);
	printf("bloodtype:%s\n",(patientList)->bloodtype);
	printf("DateAdded:%d/%d/%d\n",(patientList)->dateAdded.month,(patientList)->dateAdded.day,(patientList)->dateAdded.year);
	printf("TimeAdded:%d:%d\n\n",(patientList)->timeAdded.hour,(patientList)->timeAdded.minute);
	printPatient(patientList+1);
}

void read(int count ,organT * patientList ){
	if (count == 0 ){
		return ;
	}
	char ch ;
	(patientList)->name = (char *) calloc(50,sizeof(char));
	(patientList)->organname = (char *) calloc(50,sizeof(char));
	scanf("%s %s %s %d%c%d%c%d %d%c%d",((patientList)->name),((patientList)->organname),((patientList)->bloodtype),
								   //  Month            /        Day            /      year
								   &((patientList)->dateAdded.month),(&ch),&((patientList)->dateAdded.day),(&ch),&((patientList)->dateAdded.year),
								   //    Hour           :      Minute
								   &((patientList)->timeAdded.hour),(&ch),&((patientList)->timeAdded.minute));
	read(count-1,patientList+1);

}

struct Node * createNode(char * name , char * organname , char * bloodType ,  int month, int day, int year ){
    struct Node * aNode = (struct Node *) calloc(1,sizeof(struct Node));
    aNode->patient.name = (char *)calloc(40,sizeof(char));
    aNode->patient.organname= (char *)calloc(40,sizeof(char));
    strcpy(aNode->patient.name, name) ;
    strcpy(aNode->patient.organname,organname);
    strcpy(aNode->patient.bloodtype,bloodType);
    aNode->patient.dateAdded.month = month ;
    aNode->patient.dateAdded.day= day;
    aNode->patient.dateAdded.year = year;
    aNode->left = NULL ;
    aNode->right = NULL ;
    return aNode ;
}
struct Node * insertPatient(struct Node * root, struct Node * element ){
    if ( root == NULL ){
        return element;
    }
    if ( element->patient.dateAdded.year > root->patient.dateAdded.year ){
        if (root->right != NULL ){
            root->right = insertPatient(root->right,element);
        }
        else {
            root->right = element ;
        }
    }
    else if ( element->patient.dateAdded.year  == root->patient.dateAdded.year ){
        printf("year same than \n");
        if(element->patient.dateAdded.month > root->patient.dateAdded.month) {
            printf("month differ than \n");
            if (root->right != NULL ){
                root->right = insertPatient(root->right,element);
            }
            else {
                root->right = element ;
            }
        }
        else if(element->patient.dateAdded.month == root->patient.dateAdded.month) {
            printf("month same than \n");
            if (element->patient.dateAdded.day >= root->patient.dateAdded.day){
                printf("day differ than \n");
                if (root->right != NULL ){
                    root->right = insertPatient(root->right,element);
                }
                else {
                    root->right = element ;
                }
            }
            else{
                printf("day equal or less than \n");
                if (root->left != NULL ){
                    root->left = insertPatient(root->left,element);
                }
                else{
                    root->left = element ;
                }
            }
        }
        else{
            if (root->left != NULL ){
                root->left = insertPatient(root->left,element);
            }
            else{
                root->left = element ;
            }
        }
    }
    else{
    printf("year less than ");
        if (root->left != NULL ){
            root->left = insertPatient(root->left,element);
        }
        else{
            root->left = element ;
        }
    }
    return root;

}
int main(){
	int numPatients ;
	//scanf("%d",&numPatients);
    struct Node * aNode = NULL;
    aNode = createNode("James","Choi","A",2,24,1990);
    aNode = insertPatient(aNode,createNode("JOhnny","Kidney","A",2,25,1990));
    printf("%s ",aNode->right->patient.name);
    //printf("%s ",aNode->left->patient.organname);
    //printf("%s ",aNode->left->patient.bloodtype);
    return 0 ;
}

