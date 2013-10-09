#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOODTYPESIZE 5

struct group{
	char * organname ;
	struct patient * p ;
	struct group * next ;
};

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

struct node{
	organT patient ;
	struct node * next ;
};

struct group * setGroups(struct group * groups, char * organname ){
	if ( groups == NULL ){
		struct group * grp = (struct group *)malloc(sizeof(struct group  ));
		grp->organname = (char *)malloc(sizeof(char)*strlen(organname));
		strcpy(grp->organname,organname );
		grp->next = NULL ;
		printf("Created INit %s\n",grp->organname);
		return grp ;
	}
	else{
		struct group * helper = groups ;

		while ( helper->next != NULL && strcmp(helper->organname,organname)!=0 ){
			helper=helper->next ;
		}
		// At the node before the NULL
		if ( helper->next == NULL ){
			// If still no match, create a new node and append to the end
			if ( strcmp(helper->organname,organname) != 0 ){
				struct group * grp = (struct group *)malloc(sizeof(struct group  ));
				grp->organname = (char *)malloc(sizeof(char)*strlen(organname));
				strcpy(grp->organname,organname);
				grp->next = NULL ;
				helper->next = grp ;
				printf("(Created and inserted at end) helper->next == NULL, and strcmp != 0 %s\n",grp->organname);
			}
			// If match found, then insert into that node struct organT *
			else{
				printf("(Inserted into last node) helper->next == NULL , and strcmp == 0 %s\n",organname);
			}
		}
		else{
			printf("(Found and inserted) helper->next != NULL %s\n",helper->organname);
		}
		return groups;
	}
}

struct node * append(struct node * patientList,organT patient){
	struct node * hlpr = patientList ;

	if ( patientList == NULL ){
		patientList=(struct node * ) malloc(sizeof(struct node));
		patientList->patient = patient ;
		patientList->next = NULL ;
		return patientList ;
	}
	while ( hlpr->next != NULL){
		hlpr=hlpr->next ;
	}
	hlpr->next = (struct node * ) malloc(sizeof(struct node));
	hlpr->next->next = NULL ;
	hlpr->next->patient = patient ;
	return patientList ;
}
int main(){
	struct group * grp = NULL ;
	grp = setGroups(grp,"kidney");
	grp = setGroups(grp,"kidney");
	grp = setGroups(grp,"heart");
	grp = setGroups(grp,"kidney");
	grp = setGroups(grp,"vagina");
	grp = setGroups(grp,"vagina");
	grp = setGroups(grp,"vagina");
	grp = setGroups(grp,"vagina");
}