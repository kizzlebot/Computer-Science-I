#include <stdio.h>

int factorial(int n);

int main(){
  int x = factorial(5);
  printf("%d",x);
}

int factorial(int n){
  if ( n != 1 ){
    return n*factorial(n-1) ; 
  }
}
