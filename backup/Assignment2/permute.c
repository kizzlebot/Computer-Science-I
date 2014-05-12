// Arup Guha
// 6/14/07
// Running version of the permutation example from Dr. Biswas' COP 3502
// notes.

#include <stdio.h>
#include <string.h>
void ListPermutations(char str[],int n );
void RecursivePermute(char str[], int n ,int k);
void ExchangeCharacters(char str[], int i, int j);

int main() {
    
    char word[] = "James" ; 
    
    // Let the user enter a word to permute.
    //printf("Please enter a word you would like to permute.\n");
    //scanf("%s", word);
    int n ; 
    printf("Please enter a number would like to permute: ");
    scanf("%d", &n);
    // Print out the permutations.
    printf("\nHere are the permutations:\n\n");
    ListPermutations(word,n);
    
    system("PAUSE");
    return 0;
    
}

// Pre-condition: str is a valid C String.
// Post-condition: All permutations of str (assuming all distinct
//                 characters) will be printed.
void ListPermutations(char str[],int n) {
     
     // Call the appropriate recursive function with the correct
     // parameters.

     RecursivePermute(str,n,0);
}

// Pre-condition: str is a valid C String, and k is non-negative and
//                less than or equal to the length of str.
// Post-condition: All of the permutations of str with the first k
//                 characters fixed in their original positions are
//                 printed. Namely, if n is the length of str, then
//                 (n-k)! permutations are printed.
void RecursivePermute(char str[],int n, int k) {
     
     int j;
     
     // Base-case:     Since all letters are fixed, we can ONLY print
     // what's stored in str.
     if (k-n == strlen(str))
         printf("%s\n", str); 
         
     else {
          
         // Loop through each possible starting letter for index k,
         // the first index for which we have a choice.
         for (j=k; j<strlen(str); j++) {
         
            // Place the character stored in index j in location k.
             ExchangeCharacters(str, k, j);
             
             // Print out all of the permutations with that character
             // just chosen above fixed. 
             RecursivePermute(str,n, k+1);
             
             // Put the original character that used to be there back
             // in its place.
             ExchangeCharacters(str, j, k);
         }
     }
}  

// Pre-condition: str is a valid C String and i and j are valid indexes
//                to that string.
// Post-condition: The characters at index i and j will be swapped in
//                 str.
void ExchangeCharacters(char str[], int i, int j) {     
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}
