/*       Name: James Choi, Rob McCord
 *     Course: COP 3502C
 * Assignment: Recitation Project #7
 *       Date: November 24, 2013                          */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------------------------
----------------------------------Function Prototypes---------------------------------
------------------------------------------------------------------------------------*/
/*    Function: exec
 *    Argument: (int) numCases
 * Description: Using the number of test cases, it will read input, then use it to
 *              find stone unit answer. A wrapper function that only needs to know
 *              number of test cases  */
void exec(int numCases);

/*    Function: readIn
 *    Argument: (int **) read, (int) numChars
 * Description: Allocates *read and reads "numChars" number of digits into *read       */
int readIn(int ** read, int numChars);

/*    Function: swap
 *    Argument: (int **) list, (int) i, (int) j
 * Description: Swaps the value stored in list[i] with list[j],
 *              doesn't need to return anything, pass by reference */
void swap(int ** list, int i , int j);

/*    Function: quicksort
 *    Argument: (int **) list, (int) i , (int) j
 * Description: Implements the quicksort algorithm to sort the givent list
 *              least to greatest                                          */
void quicksort(int ** list,int first,int last);

/*    Function: findStoneUnit
 *    Argument: (int *) piles, (int) lastIndex
 * Description: Calculates the stoneUnits of given arrangement of piles */
long long findStoneUnit(int * piles, int lastIndex);

/*------------------------------------------------------------------------------------
----------------------------------END Function Prototypes-----------------------------
------------------------------------------------------------------------------------*/



/*************************************************************************************
********************************** Main Function *************************************
*************************************************************************************/
int main(){
  // Read number of test cases to solve and call exec
  int numCases ;
  scanf("%d",&numCases);
  exec(numCases);
}
/*************************************************************************************
********************************** Main Funcion END **********************************
*************************************************************************************/




/*------------------------------------------------------------------------------------
----------------------------------Function Definition---------------------------------
------------------------------------------------------------------------------------*/

void exec(int numCases){
  int i = 0 ;
  // Loop numCases number of times
  for ( i = 0 ; i < numCases; i++){

    // Get the number of digits to read
    int numChars ;
    scanf("%d",&numChars);

    // Read into read
    int * read ;
    readIn(&read,numChars);

    // Sort the array
    quicksort(&read,0,numChars-1);
    printf("%lld\n",findStoneUnit(read,numChars-1));

    free(read);

  }
}

long long findStoneUnit(int * piles, int lastIndex){
  int i = 0 ;
  long long sum  = 0 ;
  for ( i = 1 ; lastIndex-i > -1 ; i++ ){
    sum+=(long long)piles[lastIndex-i]*i;
  }
  return sum ;
}


int readIn(int ** read, int numChars){
  int i ;
  *read = (int *)malloc(sizeof(int)*numChars);
  for ( i = 0 ; i < numChars ; i++){
    scanf(" %d\n",(*read+i));
  }
  return numChars;
}


void swap(int ** list, int i , int j){
  // Swap values by reference
  int temp=*(*list+i);
  *(*list+i)=*(*list+j);
  *(*list+j)=temp;
}


void quicksort(int ** list,int first,int last){
  int pivot,j,temp,i;

  if( first < last ){
    pivot=first;
    i=first;
    j=last;

    while( i < j ){
      while( *(*list+i) <= *(*list+pivot) && i < last){
        i++;
      }
      while( *(*list+j) > *(*list+pivot) ){
        j--;
      }

      if( i < j ){
        swap(list,i,j);
      }
    }
    swap(list,j,pivot);
    quicksort(list,first,j-1);
    quicksort(list,j+1,last);
  }
}

/*------------------------------------------------------------------------------------
----------------------------------END Function Definition-----------------------------
------------------------------------------------------------------------------------*/
