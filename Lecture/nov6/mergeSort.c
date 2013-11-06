#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void merge(int * list1, int * list2);
void mergeSort(char * list, int low, int high);
void print(int * list);
int main(){
    char * list1= (char *)malloc(sizeof(char )*20);
    char * list2= (char *)malloc(sizeof(char )*20);

    l1[9]=(int*)NULL ;
    l2[9]=(int)NULL ;
    print(l1);
}

void print(int * list){
    if ( list != NULL ){
        printf("%d ",*list);
        print(list+1);
    }
    else{
        printf("\n");
    }
}
void merge(int * list1, int * list2){
    if ((list1 != NULL && list2 != NULL )){
        if ( list1[0] > list2[0]){
            printf("%d ",*list2);
            merge(list1,list2+1);
        }
        else if ( list1[0] < list2[0]){
            printf("%d ",*list1);
            merge(list1+1,list2);
        }
        else{
            printf("%d ",*list1);
            merge(list1+1,list2+1);
        }
    }
}
void mergeSort(char * list, int low, int high){

}
