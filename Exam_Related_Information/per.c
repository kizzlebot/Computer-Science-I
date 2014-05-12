#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    y = &temp;
}
void permuteOneSet(char *a, int i, int n){
    int j;
    if (i == n) {
        printf("%s\n", a);
    }
    else{
        for (j = i; j <= n; j++){
            swap((a+i), (a+j));
            permuteOneSet(a, i+1, n);
            swap((a+i), (a+j)); //backtrack
        }
    }
}




int main(){
    char * input = "ABCDEF";


    permuteOneSet(input,0,5);

}