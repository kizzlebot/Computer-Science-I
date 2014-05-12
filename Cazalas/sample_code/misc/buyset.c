// Arup Guha
// Written in class Computer Science I
// 4/19/2010

#include <stdio.h>
#include <time.h>

int buyWholeSet(int n);

int main() {
    
    srand(time(0));

    int i;
    for (i=10000; i<=100000; i+= 10000) {
        printf("%d items took %d steps\n", i, buyWholeSet(i));     
    }
            
    system("PAUSE");
    return 0;
}

int buyWholeSet(int n) {
    
    int numDistinct = 0;
    int numSteps = 0;
    int* gotIt = (int*)malloc(sizeof(int)*n);
    
    // Initializing array to say we haven't gotten
    // any item yet.
    int i;
    for (i=0; i<n; i++)
        gotIt[i] = 0;

    // Loop until we have all the items.        
    while (numDistinct < n) {
          
        numSteps++;
        int item = ((1 << 15)*rand() + rand())%n;
        
        // We scored a new item!
        if (gotIt[item] == 0) {
            gotIt[item] = 1;
            numDistinct++;
        }
    }
    
    free(gotIt);    
    return numSteps;
}
