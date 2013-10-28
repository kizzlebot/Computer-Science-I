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
typedef struct {
	char * name;
	char * organname;
	char bloodtype[BLOODTYPESIZE];
	dateT dateAdded ;
	timeT timeAdded;
	int received;
} organT;
// Binary Tree
struct node {
	organT * data ;
	struct node * left ;
	struct node * right ;
};

/* Function:     init()
 * Return:       void
 * Parameters:   N/A
 * Description:  Reads the first line to list of patients and iterates, then reads first lines to queries, then iterates */
void init ();

/* Function:     printPatient()
 * Return:       void
 * Parameters:   organT * patient
 * Description:  Prints name and organname of given parameter */
void printPatient(organT * patient);

/* Function:     readPatient()
 * Return:       organT *
 * Parameters:   N/A
 * Description:  Allocates an organT * and reads into it information about a single patient, then returns this value */
organT * readPatient();

/* Function:     compare()
 * Return:       int
 * Parameters:   organT * this, organT * that
 * Description:  Compares organT this with organT that, and returns 1 for right and 0 for left ;  */
int compare(organT * this,organT * that);

/* Function:     makeNode
 * Return:       struct node *
 * Parameters:   organT * data
 * Description:  Puts given parameter into a newly allocated struct node * for the binary tree */
struct node * makeNode(organT * data);

/* Function:     insert
 * Return:       void
 * Parameters:   struct node ** root, struct node * ins
 * Description:  Recursively inserts ins into root which is initially the root of the binary tree. */
void insert(struct node ** root, organT * ins );
void printTree(struct node * tree);

/* Function:     getQuery
 * Return:       void
 * Parameters:   organT ** rtn, struct node * tree, char * organ, char * bloodtype
 * Description:  Given the name of the organ and bloodtype, this function will find the matching query
 *               and put the value into rtn which should initially be NULL.  rtn will remain NULL if match was not found
 */
void getQuery(organT ** rtn , struct node * tree , char * organ, char * bloodtype);

int main(){
    init();
}

void init(){
    // Read the first line containing number of patients
    int tmp ;
    scanf("%d",&tmp);

    // Read into binary tree
    struct node * tree ;
    int i = 0 ;
    for ( i = 0 ; i < tmp ; i++){
        if ( i == 0 ) tree = makeNode(readPatient());
        else{
            insert(&tree,readPatient());
        }
    }

    // Read line containing number of queries.
    scanf("%d",&tmp);
    // Loop tmp number of times, reading the two queries, finding the query, and printing the value
    for ( i = 0 ; i < tmp ; i++ ){
        char * organQ = (char *)malloc(sizeof(char)*20);
        char * bloodtypeQ = (char *)malloc(sizeof(char)*20);
        organT * rtn = NULL ;
        scanf("%s %s",organQ,bloodtypeQ);

        getQuery(&rtn, tree,organQ,bloodtypeQ);
        printPatient((rtn));
        free(organQ);
        free(bloodtypeQ);
    }
}
void printPatient(organT * patient){
    if (patient != NULL && patient->name != NULL && patient->organname != NULL ){
        printf("%s %s \n",patient->name,patient->organname);
        //printf("%s %s %s %d%c%d%c%d %d%c%d\n",patient->name,patient->organname,patient->bloodtype,patient->dateAdded.month,'/',patient->dateAdded.day,'/',patient->dateAdded.year,patient->timeAdded.hour,':',patient->timeAdded.minute);
    }
    // If patient is NULL, it probably was never found
    else{
        printf("No Match Found\n");
    }
}
organT * readPatient(){

    // Initially allocate some temporaries
    char ch ;
    char * name = (char *)malloc(sizeof(char)*20);
    char * organname = (char *)malloc(sizeof(char)*20);
    char bloodtype[BLOODTYPESIZE];
    int month ;
    int day;
    int year ;
    int hour ;
    int minute;

    scanf("%s%s%s%d%c%d%c%d%d%c%d",name,organname,bloodtype,&month,&ch,&day,&ch,&year,&hour,&ch,&minute);

    // Allocate exactly the amount of space required, and copy temps into created organT *
    organT  * patient = (organT *)malloc(sizeof(organT));
    patient->name = (char *) malloc(sizeof(char)*(strlen(name)+1));
    patient->organname = (char *) malloc(sizeof(char)*(strlen(organname)+1));
    patient->received = 0 ;

    strcpy(patient->name,name);
    strcpy(patient->organname,organname);
    strcpy(patient->bloodtype,bloodtype);

    patient->dateAdded.month = month;
    patient->dateAdded.day= day ;
    patient->dateAdded.year = year;
    patient->timeAdded.minute= minute;
    patient->timeAdded.hour = hour ;

    // Free the temps
    free(name);
    free(organname);
    // Return
    return patient;
}
int compare(organT * this,organT * that){
    // if organ diff then return 1 for right
    if (strcmp(this->organname,that->organname)!=0) return 1 ;
    // else
    else{
        // if blood type diff then return 1
        if (strcmp(this->bloodtype,that->bloodtype)!=0 ) return 1 ;
        // else
        else{
            // this submisison year is less than return 1
            if (this->dateAdded.year < that->dateAdded.year) return 1 ;
            // else if this submission year greater than return 0
            else if (this->dateAdded.year > that->dateAdded.year) return 0 ;
            // else
            else{
                // if this month is less than return 1
                if ( this->dateAdded.month < that->dateAdded.month ) return 1 ;
                // else if this month is greater than return 0
                else if ( this->dateAdded.month > that->dateAdded.month) return 0 ;
                // else
                else{
                    // if this day is less than return 1
                    if (this->dateAdded.day < that->dateAdded.day) return 1 ;
                    // else if this day is greater than return 0
                    else if (this->dateAdded.day > that->dateAdded.day) return 0 ;
                    // else
                    else{
                        // if this submission hour is less than, return  1
                        if (this->timeAdded.hour < that->timeAdded.hour ) return 1 ;
                        // else if this submission hour is greater than return 0
                        else if (this->timeAdded.hour > that->timeAdded.hour ) return 0 ;
                        // else
                        else{
                            // if this submission min is less than return 1
                            if (this->timeAdded.minute < that->timeAdded.minute ) return 1 ;
                            // else if this submisison min is greater than return 0
                            else if (this->timeAdded.minute > that->timeAdded.minute ) return 0 ;
                            // else return -1i
                            else {
                                // if this name and that name identical, and all other params are the same, then this is a duplicate
                                if ( strcmp(this->name,that->name) == 0 ){
                                    return -1 ;
                                }
                                // otherwise, just put it left
                                else{
                                    return  0 ;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

struct node * makeNode(organT * data){
    struct node * rtn = (struct node * )malloc(sizeof(struct node));
    rtn->data = data ;
    rtn->left = NULL ;
    rtn->right= NULL ;
    return rtn ;
}
void insert(struct node ** root, organT * ins ){
    if (*root == NULL){
       (*root) = makeNode(ins) ;
    }
    else if (compare((*root)->data,ins)==1){
        insert(&((*root)->right),ins);
    }
    else if (compare(((*root)->data),ins)==0){
        insert(&((*root)->left),ins);
    }
    else{
        return ;
    }
}
void printTree(struct node * tree){
    if ( tree != NULL ){
        printTree(tree->left);
        printf("%s %s \n",tree->data->name,tree->data->organname);
        printTree(tree->right);
    }
}
void getQuery(organT ** rtn , struct node * tree , char * organ, char * bloodtype){
    if ( tree != NULL ){
        getQuery(rtn , tree->left,organ,bloodtype);
        if (strcmp(organ,tree->data->organname)==0 && strcmp(bloodtype,tree->data->bloodtype)==0 && tree->data->received == 0 && *rtn == NULL ) {
            tree->data->received = 1 ;
            *rtn = tree->data;
            return ;
        }
        getQuery(rtn , tree->right,organ,bloodtype);
    }
}
