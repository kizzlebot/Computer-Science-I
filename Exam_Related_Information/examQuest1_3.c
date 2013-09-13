#include <stdlib.h>
#include <stdio.h>


typedef struct {
    char x[100] ;
    char y[100] ;
    char m ;
    double q[8];
} playerT ;


typedef struct {
    playerT members[50] ;
} teamT;

typedef struct{
    char c,d;
    double x ;
} league;
int main(){
    league * l  = (league *)malloc(sizeof(league));
    teamT * tm = (teamT *) malloc(sizeof(teamT));
    char x[100];
    printf("sizeof x: %d\n",sizeof(x));
    printf("sizeof double: %d\n",sizeof(double));
    printf("sizeof int : %d\n",sizeof(int));
    printf("sizeof league: %d\n",sizeof(league));
    printf("sizeof char x[100]: %d\n",sizeof(char)*100);
    int an = sizeof(tm->members[0].x)+sizeof(tm->members[0].y)+sizeof(tm->members[0].m)+sizeof(tm->members[0].q);//sizeof(double) ;
    printf("sizeof playerT an: %d\n",an);
    an*=100 ;
    printf("sizeof an*100: %d\n",an);
    printf("sizeof playerT: %d\n",sizeof(playerT) );
    printf("sizeof teamT->members[0]: %d\n",sizeof(tm->members[0]) );
    printf("sizeof teamT: %d\n ",sizeof(teamT));
    printf("sizeof teamT[50]: %d\n ",sizeof(tm->members));
    printf("sizeof league: %d\n",sizeof(*l));
}