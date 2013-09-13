#include <stdio.h>
#include <string.h>
int main(){
    char * word = "hi,my,name,is,james";
    char * line ;
    strtok(line,","); // line = "hi"
    printf("%s",line);
    return 0 ;
}