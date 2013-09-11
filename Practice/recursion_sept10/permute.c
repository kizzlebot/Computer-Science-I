# include <stdio.h>
#include <stdlib.h>
void cooco(char *tmp ){

    char b[] = "\e[38;5;26m";
    char c[] = "\e[0m";
    char * original = b;
    char * add = tmp ;
    while(*original)
        original++;

    while(*add)
    {
        *original = *add;
        add++;
        original++;
    }
    //add = c ;
    //while(*add)
    //{
    //    *original = *add;
    //    add++;
    //    original++;
   // }
    *original = '\0';
}

void concatenate_string(char *original, char *add)
{
   while(*original)
     original++;

      while(*add)
     {
               *original = *add;
                             add++;
                                       original++;
                                          }
             *original = '\0';
             *add = *original ;
}

/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char * b= "\e[38;5;26m";
    char c[] = "\e[0m";
  char temp;
  temp = *x;
  *x = *y;
  concatenate_string(b,&temp);
  *y = *b;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
  char b[]= "\e[38;5;26m";
  char c[] = "\e[0m";
  int j ;
  if (i == n){
    int l = i ;
    //printf("%s%.*s%s%s\n",b,l,a,a+l-1,c);
    printf("%s\n",a+l);
  }
  else
    {
      for (j = i; j <= n; j++)
	{
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
	}
    }
}



/* Driver program to test above functions */
int main(){
  char a[]= "ABCDEFG";

  char b[]= "\e[38;5;26m";
  char c[] = "\e[0m";
  *a = *b ;
  permute(a, 0, 6);
  return 0;
}
