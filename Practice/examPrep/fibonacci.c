#include <stdio.h>
int fibonacci(int n ){
    if ( n == 0 || n==1 ){
        return 1;
    }
    else{
        return n*fibonacci(n-1);
    }
}
int main(){
    printf("Fibonacci of 20 is: %d",fibonacci(20));
}