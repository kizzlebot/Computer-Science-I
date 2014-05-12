// Kanad Biswas, written for COP 3502
#include <stdio.h>
#define SIZE 10

void readfile(char filename[], char student[][30], int grade[], int n);
int topper ( int A[ ], int nn); 
double  perform ( int grade[], int n);
void printing (char student[][30],int grade[],int n, int top_pos, double av);


int main(void) {
        int grade[SIZE],topper_position, i;
        double av;
        char filename[30], student[SIZE][30];
        
        // Get the filename and read in the information from the file.
        printf("\nenter the name of the file.\n");
        scanf("%s",filename);
        readfile(filename, student, grade,SIZE);
        
        // Calculate the best and average scores and print out all the info.
        topper_position = topper( grade , SIZE);
        av = perform( grade, SIZE);
        printing (student, grade, SIZE, topper_position, av);

        system("PAUSE");
        return 0;
}

// Pre-condition: filename stores the name of a file with a valid format for 
//                this problem. student is an array of strings of at least
//                length n and grade is at least of length n as well.
// Post-condition: The names and grades of the first n students stored in the
//                 file will be stored in the arrays student and grade,
//                 respectively.
void readfile(char filename[], char student[][30], int grade[], int n)
{
          int size, i;
          
          // Open the input file.
          FILE *ifp;
          ifp = fopen(filename, "r");
          
          // Read in each student's name and grade.
          for (i=0; i< n; i++)  {
                 fscanf(ifp, "%s", student[i] );
                 fscanf(ifp, "%d", &grade[i] );
          }
          fclose(ifp);
}

// Pre-condition: student and grade are arrays of length n at least that 
//                already store names and grades.
void printing (char student[][30],int grade[],int n, int top_pos, double av)
{ 
	int i;
	
	// Print out information for each student one by one.
	for (i=0; i< n; i++)
           printf("\n%s \t %d", student[i] , grade[i] );
           
    // Print out information about the best student and the class average.
	printf("\n%s is the topper and he got %d points.", student [top_pos],grade[top_pos]);
    printf("\nclass average is %.2f points.",av);
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
