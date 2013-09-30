#include <stdio.h>
#include<string.h>
int main ( )
{
	int k;
	char names[4][15];

	for(k =0; k<4; k++){
		printf( "\nprint a name = ");
		scanf("%s",names[k]);
	}
 	for(k =0; k<4; k++){

		printf( "\n name %d is %s",k+1, names[k]);
	}
	
	system("PAUSE");
	return 0;
}
