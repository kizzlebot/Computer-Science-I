#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void meaningfulPointer(){
    char * pointer = NULL ; // Pointer declaration
    printf("\e[38;5;26m void meaningfulPointer()\n\n \e[0m\n");
    while (pointer){
        printf("This won't ever print you know.");
    }
}
void indirectionOperator(){
    printf("\e[38;5;26m void indirectionOperator() \e[0m\n");
    char * m = "dog"; // Pointer declaration+initialization
    printf("\e[00;38;5;136m %c \e[0m",*m);
    printf("\n\e[00;38;5;136m %c \e[0m",*(m+1));
    printf("\n\e[00;38;5;136m %c \e[0m\n\n",*m);
}
void addressOperator(){
    printf("\n\e[38;5;26m void addressOperator() \e[0m\n");
    char * m = "dog"; // Pointer declaration+initialization

    char ** pm ;
    pm = &m ;   // **pm <----address---< &m

    char ch = *(m++);
    printf("\e[00;38;5;136m %s \e[0m\n\n",*pm);
}

int main(){
    meaningfulPointer();
    indirectionOperator();
    addressOperator();
}
