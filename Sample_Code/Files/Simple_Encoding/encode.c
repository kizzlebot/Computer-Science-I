#include <stdio.h>

int main() {

    FILE *infile, *outfile;
    int c, codechar;

    // Open both the input and output files.
    infile = fopen("input.txt","r");
    outfile = fopen("output.txt", "w");

    // Continue reading in characters till the 
    //end of the input file.
    while ((c =fgetc(infile)) != EOF) {
        if (isspace(c))
            fputc(c, outfile);

        // Only process alphabetic characters.
        if (isalpha(c)) {

           // Write out the encoded character to 
           // the output file.
           codechar = ('Z' - toupper(c)) + 'A';
           fputc(codechar, outfile);
        }    
    }
  
    fclose(infile); // Close both files.
    fclose(outfile);
  
    system("PAUSE");
    return 0;
}
