#include <stdio.h>
#include <string.h>
#include "ArrayList.h"

int main(void){
	int i; char buffer[32];

	ArrayList *L1 = createArrayList(10);
	ArrayList *L2 = createArrayList(30);

	FILE *ifp = fopen("names.txt", "rb");

	printf("\nRead Names from file and add them to ArrayList l1\n");
	// Read all names from the file and add them to L1.
	while (fscanf(ifp, "%s", buffer) != EOF)
		put(L1, buffer);
	printf("\nAdd Names to L2 in rev order\n");
	// Add the names to L2 in reverse order.
	for (i = getSize(L1) - 1; i >= 0; i--)
		put(L2, get(L1, i));

	// Print the contents of L1.
	printf("\n-- LIST 1: --\n");
	printArrayList(L1);

	// Print the contents of L2.
	printf("\n-- LIST 2 (First Names): --\n");
	printArrayList(L2);

}
