#include <stdio.h>
//     0  1  2   3   4   5   6   7   8
//    [2][7][12][13][48][34][18][23][123]
//     ^              ^               ^
//    Low            Mid             High

int binSearch( int * array, int low, int high, int val){
    if ( low > high ){
        return 0 ;
    }

    int mid = (low+high)/2 ;

    if ( val > array[mid] ) {
        return binSearch( array, mid+1, high, val);
    }


    else if (val < array[mid]){
        return binSearch(array,low,mid-1,val);
    }

    else{
        return 1 ;
    }

}

int main(){
    int array[] = {1,23,63,2950,3456,9342,31,9,18,34};
    int ans = binSearch( array, 0, 9,34 );
    printf("Ans: %d",ans);
}

