#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArrayList.h"


ArrayList *trimArrayList(ArrayList *list){

    int newSize = list->size; //no "-1" to include NULL

    if( list->capacity >= list->size ){
        list->array = realloc(list->array, sizeof(char*)*(list->size)); //realloc rows
    }
    list->capacity = list->size - 1;

    return list;
}

char *insertElement(ArrayList *list, int index, char *str){

    int i, length, nameLength, counter = index + 1;  //shift this many index to the left:

    //if index is out of bounds return NULL
    printf("here we be: line 60 \n");                                            //test
    if( index >= list->size)
        return str = '\0';
    printf("here we be  line 63\n");                                            //test
    /////if array is full add space//////
    length = (list->capacity)*2 + 1;
    if ( list->capacity <= list->size ){
    printf("here we be line 68 \n");                                            //test
    list = expandArrayList(list, length); //for some reason i cant access this in this func with for loop but in main it works ???
    printf("here we be \n");                                            //test
    }
    printf("here we be line 72\n");                                             //test

    //shift all elements to the right. //starting from right to left
    for ( i = list->size - 1; i >= index; i--){
    printf("here we be line 75\n");                                            //test
        nameLength = strlen(list->array[i])+1;             //Aquire length of string imidiatly right of dest
        list->array[i+1] = realloc(list->array[i+1], sizeof(char)*nameLength); //realloc dest columns
        strcpy(list->array[i+1], list->array[i]);
    }
    printf("here we be line 80\n");                                            //test
    //insert element in index
    nameLength = strlen(str)+1;             //Aquire length of string imidiatly right of dest
    list->array[index] = realloc(list->array[index], sizeof(char)*nameLength); //realloc dest columns
    strcpy(list->array[index], str);
    printf("here we be line 85\n");                                            //test
    //should be a pointer the inserted string
    return list->array[index];
}

int removeElement(ArrayList *list, int index){

    int i, nameLength, counter = index + 1;  //shift this many index to the left:

    if( index >= list->size)
        return 0;

    //shift all strings to the right of index left
    for ( i = counter; i< list->size; i++){
        nameLength = strlen(list->array[i])+1;             //Aquire length of string imidiatly right of dest
        list->array[i-1] = realloc(list->array[i-1], sizeof(char)*nameLength); //realloc dest columns
        strcpy(list->array[i-1], list->array[i]);
    }

    list->array[list->size - 1] = '\0';     //acounts for the last spot that does not get allocated
    list->size--; //update list size

    //currently return is incorrect
    return 1;
}

char *set(ArrayList *list, int index, char *str){

    int nameLength;
    char *pointer;

    if( list->array[index] == '\0' || index > list->size)
        return '\0';

    //////add string to list->array[i]///
    nameLength = strlen(str)+1;             //Aquire length of name +1
    list->array[index] = realloc(list->array[index], sizeof(char)*nameLength);
    strcpy(list->array[index], str);
    pointer = list->array[index];


    return pointer;

}

char *get(ArrayList *list, int index){

    char *pointer;
    pointer = list->array[index];

    if( list->array[index] == '\0' || index > list->size)
        return '\0';
    if( index <= list->size)
        return pointer;

 }

char * put(ArrayList *list, char *str){

    int i = 0,length = 0, nameLength;


    /////if array is full add space//////
    length = (list->capacity)*2 + 1;
    if ( list->capacity <= list->size ){
    list = expandArrayList(list, length); //for some reason i cant access this in this func with for loop but in main it works ???
    }

    //////add string to list->array[i]///
    nameLength = strlen(str)+1;             //Aquire length of name +1
    list->array[list->size] = realloc(list->array[list->size], sizeof(char)*nameLength);
    if (list->array[list->size] == '\0'){
        printf("Error reallocating memory!");
        free (list->array[list->size]);
        exit (1);
    }
    strcpy(list->array[list->size], str);
    //printf("the name in the .txt file is %s: put \n", list->array[list->size]);  //test


    list->size ++;
 }

ArrayList *expandArrayList(ArrayList *list, int length){

    printf("we got here\n");  //test
    int i, nameLength, theSize;
    //create newCharArray with column size of the old list->arry
    char **newCharArray = malloc(sizeof(char*)*(length+1));  //alocate rows//2
    for(i=0; i<list->capacity; i++){  // should fill ten rows + 1//
        nameLength = strlen(list->array[i]) + 1;  //get the string lenght of the old array
        newCharArray[i] =  malloc(nameLength*sizeof(char));          //alocate Columns
        //newCharArray[i] = '\0';
    }

    //Copy old array into the new array
    for( i=0; i<(list->capacity); i++){
		//printf("we got here %d \n", i);  //test
    	strcpy(newCharArray[i],list->array[i]);
    }
	//printf("we got here 4 \n");  //test

    //free the list->array columns and rows and save important info
    theSize = list->size;
    for( i=0; i<list->capacity; i++){
        free((void*)list->array[i]);
    }
    free((void*)list->array);
    //set adress of newCh.. = our old Struct
    list->array = newCharArray;
    //print to test we did what was asked //test
	//for( i=0; i<length + 1; i++){//2
		//printf("value in slot %d is %s : expandArrayList \n", i, list->array[i]);
	//}
    list->size = theSize;
    list->capacity = length;
    return list;
 }

ArrayList *createArrayList(int length){

    int ncolumns, nrows, i;
    ArrayList *theArray;
    char stringVar[5]; //set rows = empty
    //set length
    if(length < DEFAULT_INIT_LEN)
        length = DEFAULT_INIT_LEN;
    nrows = length;
    //allocate struce/rows/columns
    theArray = malloc (sizeof(struct ArrayList));  //alocate struct
    theArray->array = malloc(sizeof(char*)*(nrows)); //alocate Rows 10th row will be null
    for(i=0; i<nrows; i++){  // should fill ten rows
            theArray->array[i] = malloc(2 * sizeof(char)); //alocate Columns //realloc later
    }
    //Initialize capacity and size
    theArray->capacity = nrows; //total rows that are available for use ("not including last null")
    theArray->size = 0; //Amount of rows used

    printf("capacity = %d :createArraylist \n", theArray->capacity);    //test

    return theArray;
}

int getSize(ArrayList *list){
	if ( list != NULL ){
		return list->size;
	}
	else{
		return 0 ; 
	}
}

void printArrayList(ArrayList *list){

    int i;
	if ( list != NULL ){
		for( i=0; i<=list->capacity; i++){                                        //test
			printf("value in slot %d is %s : main \n", i, list->array[i]);    //test
		}
		printf("\n\n");                                                                  //test
		//printf("the real size is %d", L1->size);   //test
		//printf("the test size is %d", getSize(L1));   //test
	}
	else{
		return ; 
	}
}

ArrayList *destroyArrayList(ArrayList *list){

    int i;
	
	if ( list != NULL ){

		for(i=0; i<list->capacity; i++){ //free columns
			free(list->array[i]);
		}
		free(list->array); //free rows

		free(list); // free struct
		
	}

	return NULL;
}

