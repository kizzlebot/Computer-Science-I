// Arup Guha
// 2/25/2012
// Coded during Junior Knights session
// Text-based version of minesweeper without recursive clear.

#include <stdio.h>
#include <time.h>

const int HEIGHT = 5;
const int WIDTH = 5;
const int NUMBOMBS = 5;

const int VALIDCLEAR = 0;
const int ALREADYMOVED = 1;
const int HITBOMB = 2;
const int OUTOFBOUNDS = 3;

const int DEBUG = 0;

void initboard(char board[][WIDTH]);
void genbombs(int bomblist[][2], int startx, int starty);
void printboard(char board[][WIDTH]);
void printbomblist(int bomblist[][2]);
void printboardbombs(char board[][WIDTH], int bomblist[][2]);

int isbomb(int bomblist[][2], int x, int y);
int getadjbombs(int bomblist[][2], int x, int y);

int main() {

    srand(time(0));

    int bomblist[NUMBOMBS][2];
    char board[HEIGHT][WIDTH];

    // We get this first so that the first square chosen isn't a bomb.
    int x,y;
    printf("Select a square. 0-%d 0-%d.\n", HEIGHT-1, WIDTH-1);
    scanf("%d%d", &x, &y);

    // Generate the bombs.
    genbombs(bomblist, x, y);

    // Initialize the board.
    initboard(board);

    // If we want to cheat =)
    if (DEBUG)
        printbomblist(bomblist);

    int done = 0;
    int squarescleared = 0;

    // Loop until the game ends.
    while (!done) {

        // Try clearing this square.
        int outcome = clearsquare(board, bomblist, x, y, &squarescleared);

        // You lose!
        if (outcome == HITBOMB) {
            printf("Sorry, you hit a bomb and lost.\n");
            printboardbombs(board, bomblist);
            done = 1;
        }

        // Try again.
        else if (outcome == ALREADYMOVED) {
            printf("Sorry, you previously cleared that square.\n");
        }

        // Stay in bounds!
        else if (outcome == OUTOFBOUNDS) {
            printf("Sorry, that is not a valid square to clear.\n");
        }

        // Check if you won.
        if (squarescleared == HEIGHT*WIDTH - NUMBOMBS) {
            printf("Congrats, you've won!!!\n");
            printboardbombs(board, bomblist);
            done = 1;
        }

        // Get the next move, if you need to.
        else if (!done) {
            printboard(board);
            printf("Please enter your next square to clear:0-%d 0-%d.\n", HEIGHT-1, WIDTH-1);
            scanf("%d%d", &x, &y);
        }
    }

}


// Initializes the board with all underscores.
void initboard(char board[][WIDTH]) {

    int i,j;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            board[i][j] = '_';
        }
    }
}

// Generates a random list of unique bombs, none of which are
// placed on (startx, starty).
void genbombs(int bomblist[][2], int startx, int starty) {

    int i, j;
    int hasbomb[HEIGHT][WIDTH];

    // Will keep track of places we have put bombs.
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            hasbomb[i][j] = 0;
        }
    }

    // This square doesn't have a bomb, but I don't want to pick it.
    hasbomb[startx][starty] = 1;

    int count = 0;

    // Pick NUMBOMBS bombs.
    while (count < NUMBOMBS) {

        int tempx = rand()%HEIGHT;
        int tempy = rand()%WIDTH;

        // We picked this one already, try again.
        if (hasbomb[tempx][tempy])
            continue;

        // Add the bomb and mark that it's there.
        bomblist[count][0] = tempx;
        bomblist[count][1] = tempy;
        count++;
        hasbomb[tempx][tempy] = 1;
    }
}

// Prints out the board.
void printboard(char board[][WIDTH]) {

    int i, j;
    for (i=0; i<HEIGHT; i++) {

        for (j=0; j<WIDTH; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n\n");
    }
}

// Prints out the board wtih all the bomb locations.
void printboardbombs(char board[][WIDTH], int bomblist[][2]) {

    int i, j;
    for (i=0; i<HEIGHT; i++) {

        for (j=0; j<WIDTH; j++) {

            if (isbomb(bomblist, i,j))
                printf("* ");
            else
                printf("%c ", board[i][j]);
        }
        printf("\n\n");
    }
}

// For debugging, let's us know where the bombs are.
void printbomblist(int bomblist[][2]) {

    int i;

    for (i=0; i<NUMBOMBS; i++) {
        printf("(%d, %d), ", bomblist[i][0], bomblist[i][1]);
    }
    printf("\n");
}


// Clears the square x,y and let's us know the outcome.
int clearsquare(char board[][WIDTH], int bomblist[][2], int x, int y, int* pSquares) {

    // Chose an invalid square.
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH) {
        return OUTOFBOUNDS;
    }

    // Chose a previously chosen square.
    if (board[x][y] != '_') {
        return ALREADYMOVED;
    }

    // Hit a bomb!
    if (isbomb(bomblist, x, y)) {
        return HITBOMB;
    }

    // Count the number of bombs and change the board accordingly.
    int numadjbombs = getadjbombs(bomblist, x, y);
    board[x][y] = (char)(numadjbombs + '0');
    (*pSquares)++;

    // Recursively clear adjacent squares, if the number of adjacent bombs is zero.
    if (numadjbombs == 0) {

        // Go through each adjacent square.
        int dx, dy;
        for (dx=-1; dx<=1; dx++) {
            for (dy=-1; dy<=1; dy++) {

                // Make sure this square is (a) inbounds, (b) uncleared
                if (inbounds(x+dx,y+dy) && board[x+dx][y+dy] == '_') {
                    clearsquare(board, bomblist, x+dx, y+dy, pSquares);
                }
            }
        }
    }

    return VALIDCLEAR;
}

// Return 1 iff (x,y) are valid coordinates in the game.
int inbounds(int x, int y) {
    return x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH;
}

// Returns 1 iff (x,y) stores a bomb and is present in bomblist.
int isbomb(int bomblist[][2], int x, int y) {

    int i;

    // Check if any bomb is at (x,y).
    for (i=0; i<NUMBOMBS; i++) {
        if (x == bomblist[i][0] && y == bomblist[i][1]) {
            return 1;
        }
    }
    return 0;
}


// Returns the number of bombs adjacent to (x,y), assuming
// that (x,y) isn't a bomb.
int getadjbombs(int bomblist[][2], int x, int y) {

    int i;
    int count = 0;

    // Go through each bomb.
    for (i=0; i<NUMBOMBS; i++) {

        // See if it's close enough.
        if (abs(x - bomblist[i][0]) <= 1 &&
            abs(y - bomblist[i][1]) <= 1) {
            count++;
        }
    }

    return count;
}
