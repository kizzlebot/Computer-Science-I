#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void move(char * s,int here , int tohere){
	char temp ; 
	temp = s[tohere];
	s[tohere] = s[here];
	s[here] = temp ; 
}
void prm(char s[],int begin,int center ,int end)
{
	if ( begin == center){
		printf("%s",s);
	}
	else{
		// move center to begin
		move(s,begin,center);
		// move begin to center
		prm(s,begin+1,center,end);
		move(s,begin,center);
	}
}

int main()
{
    char s[100];
    printf("Enter the string\n");
    scanf("%s",s);
    prm(s,0,3,strlen(s));
    prm(s,0,3,strlen(s));

}