#include <stdio.h>
#include<string.h>
int main ( )
{
	int k;
	char names[4][20];
	int grade [4];
	
    for(k =0; k<4; k++){
		printf( "\nprint a name and grade = ");
		scanf( "%s%d", names[k],  &grade[k]);
	}
	
 	for(k =0; k<4; k++){
		printf( "\n name %d is %s with grade %d",k+1,names[k], grade[k]);
	}
	
	system("PAUSE");
	return 0;
}
