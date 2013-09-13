#include <stdio.h>
#include <stdlib.h>
//=================================================
// Permutation
//=================================================
void swap (char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *a, int i, int n){
    int j;
    if (i == n) printf("%s\n", a);
    else{
        for (j = i; j <= n; j++){
            swap((a+i), (a+j));
            permute(a, i+1, n);
            swap((a+i), (a+j)); //backtrack
        }
    }
}
//=================================================
// Exponentiation
//=================================================
int numOnes(int n){
    if ( n < 2 ) return n ;
    else return n%2 + numOnes(n/2);
}
int fastExponentiationNoMod(int base, int exp){
    if (exp == 0) return 1;
    else if (exp == 1) return base;
    else if (exp%2 == 0) return fastExponentiationNoMod(base*base, exp/2);
    else return base*fastExponentiationNoMod(base, exp-1);
}
int modPow(int base, int exp, int n) {
    base = base%n;
    if (exp == 0) return 1;
    else if (exp == 1) return base;
    else if (exp%2 == 0) return modPow(base*base%n, exp/2, n);
    else return base*modPow(base, exp-1, n)%n;
}
//=================================================
// fibonacci 
//=================================================
int fibo(int n){
    if ( n == 0  ) return 0 ;
    else if ( n == 1 )return n ;
    else return (fibo(n-1)+fibo(n-2));
}
//=================================================
// binary search 
//=================================================
int binsearch(int a[], int len, int value) {
    int low = 0, high = len-1;
    while (low <= high) {
        int mid = (low+high)/2;
        if (value < a[mid])
            high = mid-1;
        else if (value > a[mid])
            low = mid+1;
        else
            return 1;
    }
    return 0;
}
int binSearchRecursive(int *values, int low, int high, int searchval){
     int mid;
     if (low <= high) {
        mid = (low+high)/2;
        if (searchval < values[mid])
           return binSearch(values, low, mid-1, searchval);
        else if (searchval > values[mid])
           return binSearch(values, mid+1, high, searchval);
        else
           return 1;
     }
     return 0;
}

//=================================================
// Towers of Hanoi 
//=================================================
void moveTower(char * disk,src,dest,spare){
    // if smallest disk, move from source to dest
    // else 
        // moveTower(disk-1,src,spare,dest)
        // move disk from source to dest
        // moveTower(disk-1,spare,dest,src)
}
void towers(int n, int start, int end) {
     int mid;
     if (n > 0) {
          mid = 6 - start - end;
          towers(n-1, start, mid);
          printf("Move disk %d from tower ", n);
          printf("%d to tower %d.", start, end);
          towers(n-1,mid,end);
    }
}
char * dynAlloc(int size){
    char * a = (char *)malloc(sizeof(char)*size);
    printf("%c",a[size-1]);
}

int lucas(int n){
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;
    return lucas(n-1) + lucas(n-2);
}

int main(){
    printf("Lucas: %d\n",lucas(8))

}