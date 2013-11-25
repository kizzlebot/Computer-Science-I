// Arup Guha
// 8/28/2013
// Examples using malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 15

typedef struct {
    char* strand;
    int freq[4];
    char section[20];
} DNA;

const char ALLLETTERS[] = "ACGT";

void fillDNA(DNA* ptrdna);
void printDNA(const DNA* ptrMine);

int main() {

    srand(time(0));

    /*** Example #1 static allocation of one struct ***/
    DNA mine;
    fillDNA(&mine);
    printDNA(&mine);

    // This was the only dynamically allocated part. The struct itself persists...
    free(mine.strand);

    /*** Example #2: Dynamically allocating 1 struct ***/
    // Note the malloc before we call fillDNA.
    DNA* ptrMine;
    ptrMine = malloc(sizeof(DNA));
    fillDNA(ptrMine);
    printDNA(ptrMine);

    // We have two nested frees. The struct does NOT remain after this.
    free(ptrMine->strand);
    free(ptrMine);

    int i;
    /*** Example #3: Statically allocating an array of struct ***/
    DNA mineArray[10];
    for (i=0; i<10; i++)
        fillDNA(&mineArray[i]);
    for (i=0; i<10; i++)
        printDNA(&mineArray[i]);

    // We must free each strand in each element of the array, but the array persists.
    for (i=0; i<10; i++)
        free(mineArray[i].strand);

    /*** Example #4: Dynamically allocating an array of struct ***/
    int n;
    printf("How many strands do you want?\n");
    scanf("%d", &n);
    ptrMine = malloc(n*sizeof(DNA));
    for (i=0; i<n; i++)
        fillDNA(&ptrMine[i]);
    for (i=0; i<n; i++)
        printDNA(&ptrMine[i]);

    // We must free each strand in each element of the array, then the array.
    for (i=0; i<n; i++)
        free(ptrMine[i].strand);
    free(ptrMine);

    /*** Example #5: Dynamically allocating an array of pointers to structs ***/
    // Note that in our initial malloc, we are only allocating space for pointers, no structs.
    DNA** dblptrMine;
    printf("How many strands do you want?\n");
    scanf("%d", &n);
    dblptrMine = malloc(n*sizeof(DNA*));
    for (i=0; i<n; i++) {
        dblptrMine[i] = malloc(sizeof(DNA));

        // dblptrMine[i] is a pointer now, not a struct.
        fillDNA(dblptrMine[i]);
    }
    for (i=0; i<n; i++)
        printDNA(dblptrMine[i]);

    // We must free each strand in each element of the array AND the memory for the struct!
    for (i=0; i<n; i++) {
        free(dblptrMine[i]->strand);
        free(dblptrMine[i]);
    }

    // Finally we can free the array.
    free(dblptrMine);

    return 0;
}

// Written quickly - fills a DNA strand with some random info...
void fillDNA(DNA* ptrdna) {

    strcpy(ptrdna->section, "head");
    int len = 1+rand()%MAXLEN;
    ptrdna->strand = malloc(sizeof(char)*(len+1));
    int i;
    for (i=0; i<4; i++)
        ptrdna->freq[i] = 0;

    for (i=0; i<len; i++) {
        int index = rand()%strlen(ALLLETTERS);
        ptrdna->strand[i] = ALLLETTERS[index];
        ptrdna->freq[index]++;
    }
    ptrdna->strand[len] = '\0';
}

// Basic print.
void printDNA(const DNA* ptrMine) {
    printf("%s\n", ptrMine->strand);
    printf("%s\n",ptrMine->section);
    int i;
    for (i=0; i<4; i++)
        printf("%d ", ptrMine->freq[i]);
    printf("\n");
}
