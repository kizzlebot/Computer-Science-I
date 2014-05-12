#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mergeSort(int * array,int low, int high);
int * init(int num);
void printList(int * list,int length);
int * getRand(int num);
int main(){
	int * array = init(10000);

	printf("Unsorted: ");
	printList(array,10000);
	mergeSort(array,0,10000);

	printf("Sorted: ");
	printList(array,10000);
}


void mergeSort(int * array,int low, int high){
	if ( low < high ){
		// sort left 
		mergeSort(array,low,(low+high)/2);
		mergeSort(array,(low+high)/2+1,high);
		merge(array,low,(low+high)/2,high);
	}
}
int merge(int arr[],int l,int m,int h){
	int arr1[10],arr2[10];  // Two temporary arrays to
	int n1,n2,i,j,k;
	n1=m-l+1;
	n2=h-m;

	for(i=0; i<n1; i++)
		arr1[i]=arr[l+i];
	for(j=0; j<n2; j++)
		arr2[j]=arr[m+j+1];

	arr1[i]=9999;  // To mark the end of each temporary array
	arr2[j]=9999;

	i=0;
	j=0;
	for(k=l; k<=h; k++) { //process of combining two sorted arrays
		if(arr1[i]<=arr2[j])
			arr[k]=arr1[i++];
		else
			arr[k]=arr2[j++];
	}

	return 0;
}






void printList(int * list,int length){
	int i = 0 ; 
	for ( i = 0 ; i < length ; i++){
		printf("%d ",*(list+i));
	}
	printf("\n ");
}

int * init(int num){
	int * array = getRand(num);
	return array ; 
}
int * getRand(int num){
	int range;
	int * ret = (int *) malloc(sizeof(int)*num) ; 

	srand(time(NULL));
	int i = 0 ; 
	range = (200 - 1) + 1; 
	for ( i = 0 ; i < num ; i++){
		ret[i] =  rand() % range + 1;
	}
	return ret ;
}
