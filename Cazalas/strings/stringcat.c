#include <stdio.h>
#include<string.h>

int main ( ){
	int length1,length2;
	char str1[20] = "alpha";
    char str2[20] = "beta";
    
	printf("\nlength is %d", strlen(strcat(str1, str2)) );
    printf("\n\n");
    
    system("PAUSE");
    return 0;
}
