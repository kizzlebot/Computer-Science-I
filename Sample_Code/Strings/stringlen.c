#include <stdio.h>
#include<string.h>

int main ( ){
    
	int length1,length2;
	char string1[20] =  "alpha";
	char string2[20] =  "beta";

    // finds length of the string
	length1 = strlen( string1 );	 

	printf( "\n length of  %s is %d", string1, length1 );
	
	//concatenates two strings
	strcat ( string1, string2);	
 
	printf( "\n the new string is %s", string1 ); 	
	length2 = strlen( string1 );
    printf( "\n length of  new string is  %d", length2 );
    printf( "\n\n");
    
    system("PAUSE");
    return 0;
}
