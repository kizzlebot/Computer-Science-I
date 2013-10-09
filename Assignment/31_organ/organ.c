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
struct binary {
	organT patient ;
	struct binary * left ;
	struct binary * right ;
};
struct node {
	organT patient ;
	struct node * right ;
	struct node * left ;
};

struct node * allocNode(){
		struct node * nodes = (struct node * ) malloc(sizeof(struct node));
		nodes->patient.name = (char *) malloc(sizeof(char)*20);
		nodes->patient.organname = (char *) malloc(sizeof(char)*10);
		nodes->patient.received = 0 ;


		char ch ;
		char * name = (char *)malloc(sizeof(char)*20);
		char * organname = (char *)malloc(sizeof(char)*20);

		char bloodtype[BLOODTYPESIZE];
		int month ;
		int day;
		int year ;

		int hour ;
		int minute;
		scanf("%s %s %s %d%c%d%c%d %d%c%d",name,organname,bloodtype,&month,&ch,&day,&ch,&year,&hour,&ch,&minute);
		strcpy(nodes->patient.name,name);
		strcpy(nodes->patient.organname,organname);
		strcpy(nodes->patient.bloodtype,bloodtype);
		nodes->patient.dateAdded.month = month;
		nodes->patient.dateAdded.day= day ;
		nodes->patient.dateAdded.year = year;

		nodes->patient.timeAdded.minute= minute;
		nodes->patient.timeAdded.hour = hour ;
		nodes->left = NULL ;
		nodes->right = NULL ;

		free(name);
		free(organname);

		return nodes ;
}
int compare (struct node * nodes, struct node * element){
	if ( strcmp(nodes->patient.organname, element->patient.organname)!=0) {
		return -1 ;
	}
	else{
		if ( strcmp(nodes->patient.bloodtype,element->patient.bloodtype) != 0){
			return -1 ;
		}
		else{
			if ( nodes->patient.dateAdded.year < element->patient.dateAdded.year ){
				return -1 ; // right
			}
			else {
				if ( nodes->patient.dateAdded.month < element->patient.dateAdded.month){
					return -1 ;
				}
				else{
					if ( nodes->patient.dateAdded.day < element->patient.dateAdded.day ){
						return -1 ;
					}
					else{
						if ( nodes->patient.timeAdded.hour < element->patient.timeAdded.hour ){
							return -1 ;
						}
						else{
							if ( nodes->patient.timeAdded.minute < element->patient.timeAdded.minute ){
								return -1 ;
							}
							else{
								return 1 ; // Right
							}
						}
					}
				}
			}
		}
	}
	return 0 ;
}
struct node * insertBin(struct node * root, struct node * element){
	if ( root == NULL ){
		return element ;
	}
	else{
		if (compare( root, element) == -1  ){
			if ( root->right != NULL ){
				root->right = insertBin(root->right,element);
			}
			else{
				root->right = element ;
			}
		}
		else{
			if ( root->left != NULL ){
				root->left = insertBin(root->left, element);
			}
			else{
				root->left = element ;
			}
		}
		return root ;
	}
}
struct node * readin(int numLines,struct node * nodes){
	if ( numLines == 0 ) return ;
	struct node * tmp = allocNode();
	if ( compare( nodes,tmp ) < 0 ){
		nodes->right = tmp ;
		readIn(numLines-1,nodes->right);
	}
	return nodes;
}

void printNodes(struct node * list){
	if ( list != NULL ){
		printNodes(list->left);
		printf("%s %s %s ",list->patient.name,list->patient.organname,list->patient.bloodtype);
		printf("%d/%d/%d %d:%d\n",
			list->patient.dateAdded.month,
			list->patient.dateAdded.day,
			list->patient.dateAdded.year,
			list->patient.timeAdded.hour,
			list->patient.timeAdded.minute);
		printNodes(list->right);
	}
}


int main(){
	int numLines ;
	scanf("%d",&numLines);
	struct node * nodes = readin(numLines);

	//printNodes(nodes);
	printf("%d",compare(nodes,nodes->right));
    return 0 ;
}

