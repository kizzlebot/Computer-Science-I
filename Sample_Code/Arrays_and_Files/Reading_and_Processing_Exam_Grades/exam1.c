// Kanad Biswas for COP 3502
#include <stdio.h>
#define SIZE 10

void readfile(char filename[], int grade[], int n);
double  perform ( int grade[], int n);
int topper ( int A[ ], int nn);

int main(void) {
        int grade[SIZE],topper_position;
        double av;
        char filename[30];
        
        // Get the name of the input file.
        printf("\nenter the name of the file.\n");
        scanf("%s",filename);
        
        // Read in the information from the file and process it.
        readfile(filename, grade,SIZE);
        topper_position = topper( grade , SIZE);
        av = perform( grade, SIZE);
        printf("\ntopper got %d points.", grade[topper_position]);
        printf("\nclass average is %.2f points.",av);
        
        system("PAUSE");
        return 0;
}

// Pre-condition: filename stores the name of a valid file for this problem
//                and grade is an array of at least size n.
// Post-condition: grade will be filled with the first n integers in the file
//                 with the name filename.
void readfile(char filename[], int grade[], int n)
{
          int size, i;
          
          // Open the file.
          FILE *ifp;
          ifp = fopen(filename, "r");
          
          // Read in each value from the file into the appropriate array slot.
          for (i=0; i< n; i++)
                 fscanf(ifp, "%d", &grade[i] );
          fclose(ifp);
}

// Pre-condition: grade is an array of size n or greater and stores test grades.
// Post-condition: The average grade will be computed and returned.
double  perform ( int grade[], int n)
{
        int total= 0, i;
        double average;
        
        // Sum up all of the grades.
        for (i=0; i < n; i++)
                total = total+ grade[i];
                
        // Determine the average and return it. Note the cast!
        average = (double)total/n;
        return average;
}
        
// Pre-condition: grade is an array of size nn or greater and stores test grades.
// Post-condition: The maximum grade will be computed and returned.
int topper ( int A[ ], int nn)
{
        int i, max_pos;
        
        // Let's look at the value at the end of the array and assume this is
        // the best one we've seen so far.
        max_pos = nn-1;
        
        // Loop through the rest of the array looking for a better score.
        for (i=0; i < nn-1; i++)
        
                // If you find one better, update the index in which it's stored.
                if ( A[i]> A[max_pos] )
                        max_pos = i;  
        return max_pos;
}
