// Arup Guha
// 5/30/2012
// Solution to Problem: Bodies of Water

#include <stdio.h>

#define MAX 50

int solve(char map[][MAX+1], int rows, int cols);
void floodfill(char map[][MAX+1], int rows, int cols, int x, int y, char oldfill, char newfill);
int main() {

    FILE* ifp = fopen("water.in", "r");

    int loop, nummaps;
    fscanf(ifp, "%d", &nummaps);

    // Go through each case.
    for (loop=1; loop<=nummaps; loop++) {

        // Note that the dimensions make room for the null character.
        char map[MAX][MAX+1];

        int i, rows, cols;
        fscanf(ifp, "%d%d", &rows, &cols);

        // Read in the map, one line at a time.
        for (i=0; i<rows; i++)
            fscanf(ifp, "%s", map[i]);

        int lakes = solve(map, rows, cols);

        // Output the result, according to its plurality.
        if (lakes == 1)
            printf("Map #%d: Contains 1 body of water.\n", loop);
        else
            printf("Map #%d: Contains %d bodies of water.\n", loop, lakes);
    }

    fclose(ifp);
    return 0;
}

int solve(char map[][MAX+1], int rows, int cols) {

    int i, j, numregions = 0;

    // Go through each pixel.
    for (i=0; i<rows; i++) {

        for (j=0; j<cols; j++) {

            // Found a new body of water, so run a floodfill!
            if (map[i][j] == '~') {
                numregions++;
                floodfill(map, rows, cols, i, j, '~', 'X');
            }
        }
    }
    return numregions;
}

// Fills the region adjacent to (x, y) in map that was previously marked by
// oldfill with newfill.
void floodfill(char map[][MAX+1], int rows, int cols, int x, int y, char oldfill, char newfill) {

    // Deal with out of bounds here easily.
    if (x < 0 || x >= rows || y < 0 || y >= cols)
        return;

    // Not the character we're filling.
    if (map[x][y] != oldfill)
        return;

    // Fill this slot with the new character.
    map[x][y] = newfill;

    // Here's the recursion - note that we need no if statements because
    // we check for everything up front in our base cases.
    floodfill(map, rows, cols, x-1, y, oldfill, newfill);
    floodfill(map, rows, cols, x+1, y, oldfill, newfill);
    floodfill(map, rows, cols, x, y-1, oldfill, newfill);
    floodfill(map, rows, cols, x, y+1, oldfill, newfill);

}
