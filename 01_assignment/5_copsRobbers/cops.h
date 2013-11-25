// ifndef checks if COPS has been #defined earlier in the file or in an included file
// code in between ifndef and #else or #endif is included
#ifndef COPS
#define COPS

typedef struct {
  float x, y, speed, direction ;
} Robber ;

typedef struct {
  float x, y, speed  ;
  double time ;
} Cop ;

void readAndExecute();
double getMinTime(Cop copper,Robber rob);
Robber initRobber(int x, int y, int speed, int direction);
void readRobbers(Robber ** rob , int numRobbers);
int * ithPermutation(const int n, int i);
int factorial(int n );
#endif
