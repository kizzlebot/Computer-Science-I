#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(int * numArray, int target, int arraySize){
    int high = arraySize;;
    int low = 0 ;
    while( high-low > 0.00001){

        double mid = (high+low)/2.0;

        if ( numArray[(int)mid] > target ){
            high = mid ;
        }
        else{
            low = mid ;
        }
    }
}
int main(){
    int * numArray = malloc(sizeof(int)*50);
    int i = 0 ;
    while ( i < 50 ){
        numArray[i] = 2*i;
    }
    search(numArray,18,50) ;
}
