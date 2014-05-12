#include <stdio.h>
#include<string.h>
int main ( ){
    
	int length1,length2;
	char string1[20] =  "alpha";
	char string3[10] = "alpha";
	char string2[20] =  "assignment";
	
    if ( strcmp(string1, string2) != 0)
        printf( "\n string1 and string2 are not same");
    if ( strcmp(string1, string2) < 0)
   	    printf( "\n string1 comes before string2 ");
   	if ( strcmp(string1, string3) == 0)
   	    printf( "\n string1 and string3 are same\n");

    system("PAUSE");
    return 0;
}
