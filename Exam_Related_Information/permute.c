#include <stdio.h>
#include <stdlib.h>
int lucas(int n){
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;
    return lucas(n-1) + lucas(n-2);
}
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
int sumOfDigits(int n){
  if ( n>10){
    return sumOfDigits(n/10) + n%10 ;
  }
}

int main(){
    char str[] = "CUBES";
    permute(str,0,3);
    printf("Permute: %d\n",lucas(8));
}