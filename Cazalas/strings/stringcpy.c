#include <stdio.h>
#include<string.h>
int main ( )
{
	int length1,length2;
	char string1[20] =  "alpha";
	char string2[20] =  "assignment";
	printf( "\n the old string is %s", string1 ); 	
	
	//copies string2 on top of string1
    strcpy ( string1, string2);	 

	printf( "\n and the new string is %s", string1 ); 	
	length2 = strlen( string1 );
    printf( "\n length of  new string is  %d", length2 );
    printf( "\n\n");
    
    system("PAUSE");
    return 0;
}
