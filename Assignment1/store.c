#include <stdio.h>
#include <stdlib.h>

int count( int num , int cnt ){
    if ( num == 0 ){
        return cnt ; 
    }
    else {
        count((num-num%10)/10, cnt+1);
    }
}
char *readFile()
{
    FILE *file;
    int i = 0;
    char *code = malloc(1000 * sizeof(char));
    file = fopen("file.txt", "r");
    do 
    {
        code[i++] = (char)fgetc(file);
        printf("%c",code[i]);
    } while(code[i-1] != EOF);
    code[i] = '\0';
    return code;
}
int main(){
    
    int userIn;
    printf("\nEnter number for digitcount: ");
        
    scanf("%d",&userIn);
    int cnt = 0 ; 
    cnt = count(userIn,cnt) ;
    printf("\nThe number of digits: %d",cnt);
    printf("\n");
    char * ch ; 
    ch = readFile();
}
