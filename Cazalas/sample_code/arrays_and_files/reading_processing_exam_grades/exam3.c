// Kanad Biswas for COP 3502
#include <stdio.h>
#define SIZE 10

void readfile(char filename[], char student[][30], int grade[], int n);
int find( char student[][30], char name[], int n);

int main(void) {
        int grade[SIZE],topper_position, i, newpos;
        double av;
        char filename[30], newname[30],  student[SIZE][30];
        
        // Get the name of the input file and read this information in.
        printf("\nenter the name of the file.\n");
        scanf("%s",filename);
        readfile(filename, student, grade,SIZE);
        
        // Print out the information for each student.
        for (i=0; i< SIZE; i++)
                 printf("\n%s \t %d", student[i] , grade[i] );
        
        // Ask for which grade the user wants.
        printf("\nwhose grade do you want?\n");
        scanf("%s",newname);
        newpos = find(student, newname,SIZE);
	   
	    // No one was found with that name!
        if ( newpos == -1)
		  printf("\n There is no student by this name.");
	    
	    // Answer their request.
        else
		  printf("\n%s has got %d points.", newname, grade[newpos]);
        
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

// Pre-condition: student is an array of length n at least that 
//                already store names.
// Post-condition: If name is stored in student, then the first index in which
//                 it is stored will be returned. Otherwise -1 is returned.
int find( char student[][30], char name[], int n)
{       
        int i;
        
        // Look through the array for a match!
        for (i=0; i < n; i++)
        
                // We found one, so return this index immediately.
                if(strcmp(name,student[i])==0)
                        return i;
	    
	    // If we get here, no match was found.
        return -1;
}
