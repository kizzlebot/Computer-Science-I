// Kanad Biswas
// 5/18/07
// Example for COP 3502 illustrating dynamic memory allocation for arrays.

#include<stdio.h>
     
typedef struct
{
   char first[20];
   char last[20];
   int nos[6];
}gambler;

gambler *read_file(char file[],   int *numbuyers);
void print_winners( gambler *list,  int numtickets );
void  match_one (gambler buyer ,  int win_nos[ ] );

int main()
{
   char filename[20];
   int numbuyers, win_nos[6];
   gambler *ticket_buyers;
  
   printf ("\n Enter the name of the file\n");
   scanf ("%s",filename);

   // reads file information into memory and prints the winning numbers. 
   ticket_buyers = read_file(filename,  &numbuyers);
   print_winners(ticket_buyers,   numbuyers);

   // free the memory space used by this dynamic allocation.
   free (ticket_buyers);
   
   system("PAUSE");
   return 0;
}

//Preconditions: file should be name of file storing the ticket buyer
//information in proper format.
//Postconditions: Returns a Pointer to the array storing all ticket buyer
//information and total number of ticket buyers.

gambler *read_file (char file[],   int *numbuyers)
{ 
   FILE *fp;
   int   i, j;
   gambler  *list  ;

   // Open the input file with the gambler's data and read in the number of buyers.
   fp =  fopen( file,   "r");
   fscanf (   fp,  "%d",    numbuyers);

   // Allocate space to store each buyers' information.
   list=(gambler*) malloc((*numbuyers)*sizeof(gambler));


   // read in individual ticket buyer information
   for (i=0;   i<*numbuyers;    i++) {
       
      // Read in the current gambler's name.
      fscanf(  fp,   "%s",  list[i].last );
      fscanf(  fp,   "%s",  list[i].first);

      // Read in their numbers.
      for ( j  = 0; j<6; j++)
         fscanf( fp, "%d" ,&( list[i].nos[j] ));    
   }

    fclose(fp);
    return list;
}

// This FUNCTION looks at the LIST and gets winning numbers from the user
void print_winners( gambler *list, int numtickets )
{
   int i,  k , win_nos[6];
   
   printf("\nEnter the winning lottery nos :\n ");
   for( i=0 ;i<6 ;i++)
   scanf("%d",&win_nos[i]);

   // for each ticket buyer , match the numbers with the winning numbers. 
   for  ( k = 0;    k< numtickets;  k++)
  	 match_one( list [k ] ,  win_nos  );
}


// FUNCTION TO MATCH DATA 
void  match_one (gambler buyer , int win_nos[] )
{
   int i=0 ,    j=0,    count=0;
   
   // Use i as an index to the list of winning numbers and j as an index
   // to the list of the gambler's numbers. This technique only works because
   // the two lists are sorted!  
   while (i<6 && j<6) {
             
      // This means the gambler could not have picked the current winning number.       
      if ( win_nos[i] <  buyer.nos[j] )
         i++;
         
      // The number chosen by the gambler is NOT on the list of winning numbers.
      else  if (win_nos[i]  >  buyer.nos[j] )
         j++;
         
      // We have a match! A winning number picked by the gambler!
      else {
         count++;
         i++;
         j++;
      }
   }

   //Depending on number matched print out the result
   switch(count) {

      case 3:
         printf( "\n%s %s   matched  3 numbers and won $10.\n", buyer.first, buyer.last);
         break;

      case 4:
         printf( "\n%s %s   matched  4 numbers and won $100.\n", buyer.first, buyer.last);
         break;

      case 5:
         printf( "\n%s %s   matched  5 numbers and won $10000.\n", buyer.first, buyer.last);
         break;

      case 6:
         printf( "\n%s %s   matched  6 numbers and won $1000000.\n", buyer.first, buyer.last);
         break;
	}
}

