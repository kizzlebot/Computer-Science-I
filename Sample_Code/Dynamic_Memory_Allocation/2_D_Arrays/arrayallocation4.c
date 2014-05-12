// NOT RECOMMENDED!
// Arup Guha
// 1/28/08
// Example for COP 3502

// Dynamic memory allocation for an array of strings.
// In this implementation, we dynamically allocate an array of fixed-length
// strings.

// Note: I don't know if it's a limitation of C, but I haven't figured out
//       how to get this implementation to work when you have to pass the
//       structure created back to a function as the return type. The only
//       thing I have been able to successfully do is print out the structure
//       through a function after it's been read in.

// I finally got my readList to work, but it gives me a gazillion warnings
// when I compile, so I am pretty sure this is NOT a good technique. It did
// work though, but that doesn't mean that it will work on another machine.

// Due to this limitation, I strongly suggest the approach taken in the file
// arrayallocation.c instead of this approach, since this approach will
// hamper your ability to create a modularized program.

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH     256

void printList(char (*pList)[MAX_STRING_LENGTH], int length);
char* readList(char* fileName, int* wordsCount);

int main() {

    char fileName[50];
    int wordCount, i;

    // If you do this, you CAN'T allocate the space for the pointers in a
    // separate function, or at least I haven't figured out how yet.
    char (*pList)[MAX_STRING_LENGTH];

    // Get the filename.
    printf("Enter the file name.\n");
    scanf("%s", fileName);

    pList = readList(fileName, &wordCount);
    printList(pList, wordCount);

    free(pList);

    system("PAUSE");
    return 0;
}

// Pre-condition: pList is a pointer to an array of pointers, each of which
//                already stores a string. length is the number of strings
//                stored in the structure.
// Post-condition: All of the strings stored in pList will be printed.
void printList(char (*pList)[MAX_STRING_LENGTH], int length) {
     int i;

     // Just loop through each pointer and print the appropriate string.
     for (i=0; i<length; i++)
         printf("%s\n", pList[i]);
}

// Pre-conditions: fileName is the name of a valid file with the proper
//                 format, and wordsCount is a pointer to an integer that will
//                 store the number of words read in.
// Post-condition: A pointer to an array of static strings will be returned
//                 that stores all of the words.
char* readList(char* fileName, int* wordsCount) {

  char (*pList)[MAX_STRING_LENGTH];

  char word[MAX_STRING_LENGTH];
  int i, wordLength;

  FILE* pFile = fopen(fileName, "r");   // open file.

  if (pFile != NULL){
    /* read the 1st line, get to know how many words in the dictionary. */
    fscanf(pFile, "%d", wordsCount);

    /* Here we allocate space a pointer for each word in the list.
    Note that the space for the words themselves is NOT allocated here. */
    pList = (char *)malloc(*wordsCount * sizeof(*pList));

    for (i = 0; i < *wordsCount; i++){

      // read in this word.
      fscanf(pFile, "%s", pList[i]);
    }

    fclose(pFile);    // close file.
  }

  return pList;
}
