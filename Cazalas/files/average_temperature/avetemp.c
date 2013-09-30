#include <stdio.h>

int main () {

   FILE * infile;
   int temp,j,sum=0;
   double average;
   infile  = fopen(  "max_temp.txt",   "r" );

   for (j =1; j <= 10; j++)
     {
        fscanf( infile, "%d", &temp);
        sum = sum + temp;
     }
   average = sum/10.0;

   printf(  "\naverage max temp = %.2f\n", average);
   fclose(infile);
   
   system("PAUSE");
   return 0;
}
