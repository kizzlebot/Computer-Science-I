// Arup Guha
// 2/1/2010
// Solution to 2010 UF High School Contest Problem: Golf Fine
#include <stdio.h>

#define SIZE 10

void floodfill(char grid[][SIZE], int x, int y);
int inbounds(int x, int y);
int countX(char grid[][SIZE]);
int countM(char grid[][SIZE]);
int adjacentX(char grid[][SIZE], int x, int y);

int main() {

    FILE *ifp;
    ifp = fopen("golf.txt", "r");
    char grid[SIZE][SIZE]; 
    char line[SIZE+1];
    int i,j;
	
    // Loop through reading each line of the input file and store each
    // character in grid.
    for (i=0; i<SIZE; i++) {
	fscanf(ifp, "%s", line);
	for (j=0; j<SIZE; j++)
	    grid[i][j] = line[j];
		
    }
		
    // Find s in the grid, store the location in x,y.
    int x=0,y=0;
    for (i=0; i<SIZE; i++) {
	for (j=0; j<SIZE; j++) {
	    if (grid[i][j] == 's') {
	        x = i;
	        y = j;
	        break;
            }
	}
    }
	
    // Run our floodfill and output the appropriate information.	
    floodfill(grid,x,y);
    printf("%d\n",countX(grid));
    printf("$%d 000\n", 50*countM(grid));
	
    fclose(ifp);
	
    system("PAUSE");
    return 0;
}
	
// Floodfills grid starting at location (x,y).
void floodfill(char grid[][SIZE], int x, int y) {
	
    int i,j;
    	
    // Mark this spot
    grid[x][y] = 'X';
		
    // Go through all valid adjacent squares with a 'd' in them.
    for (i=-1; i<2; i++) 
	for (j=-1; j<2; j++)
	    if (inbounds(x+i,y+j) && grid[x+i][y+j]=='d')
                floodfill(grid,x+i,y+j);
}

// Returns true iff (x,y) is a valid index into the grid.
int inbounds(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}
	
// Returns the number of 'X's in the grid. This is the size of the golf
// course.
int countX(char grid[][SIZE]) {
    
    int count = 0, i,j;

    // Just run through each square looking for 'X'		
    for (i=0; i<10; i++)
	for (j=0; j<10; j++)
	    if (grid[i][j] == 'X')
	        count++;
		
    return count;
}

// Returns the number of 'm' that are adjacent to X's.	
int countM(char grid[][SIZE]) {
    
    int count = 0,i,j;

    // Only count an 'm' if it is next to an 'X', go through all squares.    
    for (i=0; i<10; i++)
        for (j=0; j<10; j++)
            if (grid[i][j] == 'm' && adjacentX(grid,i,j))
		count++;
		
    return count;
}
	
int adjacentX(char grid[][SIZE], int x, int y) {
    
    int i,j;
    
    // Run through each adjacent square to (x,y). If we ever see an 'X'
    // return true. 
    for (i=-1; i<2; i++) 
        for (j=-1; j<2; j++)
            if (inbounds(x+i,y+j) && grid[x+i][y+j]=='X')
		return 1;
		
    return 0; // Never found an adjacent 'X'
}
