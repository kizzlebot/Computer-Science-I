#include <stdio.h>
int f(int a, int b){
    int x =0 ;
    printf("  b*f(a-1,b-1)=%d\n",x);
    if ( a <= 0 ){
        return 1 ;
    }
    else{
        //x = b*f(a-1,b-1)/a;
        x = b*f(a-1,b-1)/a;

        printf("  b*f(a-1,b-1)=%d\n",x);
        return x ;
    }
}
int main(){
    int a , b;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);

    int x = f(a,b);
    printf("Answer %d\n",x);
}