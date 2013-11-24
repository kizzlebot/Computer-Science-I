#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "cops.h"
#define PI 3.14159265358979323846



int factorial(int n){
  if ( n == 0 || n==1){
    return 1 ;
  }
  else{
    return n*factorial(n-1);
  }
}

int * ithPermutation(int n, int i){
  int j, k = 0;
  int *fact = (int *)calloc(n, sizeof(int));
  int *perm = (int *)calloc(n, sizeof(int));

  // compute factorial numbers
  fact[k] = 1;
  while (++k < n)
    fact[k] = fact[k - 1] * k;

  // compute factorial code
  for (k = 0; k < n; ++k){
      perm[k] = i / fact[n - 1 - k];
      i = i % fact[n - 1 - k];
  }

  // readjust values to obtain the permutation
  // start from the end and check if preceding values are lower
  for (k = n - 1; k > 0; --k)
    for (j = k - 1; j >= 0; --j)
      if (perm[j] <= perm[k])
        perm[k]++;

  free(fact);
  return perm ;
}

void readRobbers(Robber ** rob , int numRobbers){
  *rob = (Robber *) calloc((numRobbers+1),sizeof(Robber));

  int i = 0 ;
  int x, y , spd , dir ;
  x = 0 ;
  y = 0 ;
  spd = 0 ;
  dir = 0 ;
  for ( i = 0 ; i < numRobbers ; i++ ){
    scanf("%d %d %d %d",&x,&y,&dir,&spd);
    *(*rob+i) = initRobber(x,y,spd,dir);
  }
}
void readAndExecute(){
  int numRobbers ;
  int spd = 0 ;
  while (!feof(stdin)){
    scanf("%d %d",&numRobbers,&spd);
    if (numRobbers == 0 && spd == 0) break;
    Cop copper ;
    copper.x = 0 ;
    copper.y = 0 ;
    copper.time = 0.0  ;
    copper.speed = spd ;

    Robber * rob ;
    readRobbers(&rob,numRobbers);
    double time =0;
    double minTime = 0 ;
    int j = 0 ;

    int fact = factorial(numRobbers);

    int i = 0 ;
    int * perm ;
    // try every permutation
    for ( j = 0 ; j < fact ; j++ ){
      perm = ithPermutation(numRobbers,j);
      copper.x = 0 ;
      copper.y = 0 ;
      copper.time = 0.0 ;

      for ( i = 0 ; i < numRobbers ; i++){
        time=getMinTime(copper,rob[perm[i]]) ;
        copper.time+=time ;
        copper.x = rob[perm[i]].x+rob[perm[i]].speed*(copper.time)*cos((rob[perm[i]].direction*2*PI)/360);
        copper.y = rob[perm[i]].y+rob[perm[i]].speed*(copper.time)*sin((rob[perm[i]].direction*2*PI)/360);
        //printf("(%d) Robber: %d %d %d %d Time: %f\n",i,rob[i].x,rob[i].y,rob[i].speed,rob[i].direction,time);
      }
      if ( j == 0 ) minTime = copper.time ;
      else{
        if ( copper.time < minTime) minTime = copper.time ;
      }
      free(perm);
    }
    printf("minTime:%f\n",minTime);
    free(rob);
  }
}
double getMinTime(Cop copper,Robber rob){
  double distChase =10;
  // use copper.time to figure robber pos.
  double time = 0.0;
  // while loop until copper.speed*t > distance

  float inc = 10 ;
  while ( 1 ){
    while (copper.speed*(time) < distChase){
      time+=inc;
      distChase = pow((pow((rob.x+rob.speed*(copper.time+time)*cos((rob.direction*2*PI)/360)-copper.x),2)+pow((rob.y+rob.speed*(copper.time+time)*sin((rob.direction*2*PI)/360)-copper.y),2)),0.5);
    }
    inc/=2;
    if (copper.speed*time-distChase < 0.0000001) break;
    while (copper.speed*(time) > distChase ){
      time-=inc;
      distChase = pow((pow((rob.x+rob.speed*(copper.time+time)*cos((rob.direction*2*PI)/360)-copper.x),2)+pow((rob.y+rob.speed*(copper.time+time)*sin((rob.direction*2*PI)/360)-copper.y),2)),0.5);
    }
    inc/=2;
    if (distChase-copper.speed*time< 0.0000001) break;
  }
  return time ;
}

Robber initRobber(int x, int y, int speed, int direction){
  Robber rtn  ;
  rtn.x = (float)x ;
  rtn.y = (float)y ;
  rtn.speed = (float)speed ;
  rtn.direction = (float)direction ;
  return rtn  ;
}


