#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int ** swap, int a, int b ){
  int tmp = *(*swap+a);
  *(*swap+a) = *(*swap+b);
  *(*swap+b) = tmp ;
}

void merge(int ** sort, int low, int high ){
  if ( high-low > 1 ){
    int mid = (high-low)/2+low ;
    merge(sort,low,mid);
    merge(sort,low+mid,high);
  }
  else{
    if ( *(*sort+low) > *(*sort+high) ){
      swap(sort,low,high) ;
    }
  }
}



int main(){
  int * array = (int *)malloc (sizeof(int)*10);
  array[0] = 5 ;
  array[1] = 2 ;
  array[2] = 3 ;
  array[3] = 15 ;
  array[4] = 12 ;
  array[5] = 30 ;
  array[6] = 52 ;
  array[7] = 19 ;
  array[8] = 31 ;
  array[9] = 17 ;

  int high = 9 ;
  int low = 0 ;
  merge(&array,low,high);
  for ( low = 0 ; low < 10 ; low++) printf("%d ",*(array+low));
}
