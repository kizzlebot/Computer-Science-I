// NOT RECOMMENDED!
// Arup Guha
// 1/28/08
// Example for COP 3502

// Dynamic memory allocation for an array of strings.
// In this implementation, we dynamically allocate an array of fixed-length
// strings.

// Note: I don't know if it's a limitation of C, but I haven't figured out
//       how to get this implementation to work when you have to pass the
//       structure created back and forth between functions. That is why this
//       whole implementation is in main.

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH     256

int main() {

    char fileName[50];
    int wordCount, i;

    // If you do this, you CAN'T allocate the space for the pointers in a
    // separate function, or at least I haven't figured out how yet.
    char (*pList)[MAX_STRING_LENGTH];
    int numWords;

    // Get the filename.
    printf("Enter the file name.\n");
    scanf("%s", fileName);

    FILE* pFile = fopen(fileName, "r");   // open file.

    if (pFile != NULL){

       /* read the 1st line, get to know how many words in the dictionary. */
       fscanf(pFile, "%d", &wordCount);

       /* Here we allocate space for the word */
       pList = malloc(wordCount * sizeof(*pList));

       // Read in each word.
       for (i = 0; i < wordCount; i++){
           fscanf(pFile, "%s", pList[i]);
       }

       fclose(pFile);    // close file.
    }

    // Print these words to check that our read worked and free the memory.
    for (i=0; i<wordCount; i++)
        printf("%s\n", pList[i]);

    free(pList);

    system("PAUSE");
    return 0;
}
