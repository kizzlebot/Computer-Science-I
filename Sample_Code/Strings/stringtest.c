#include <stdio.h>

void to_upper(char *word);

int main ( ){
	int k;
	char name[20], course[20];

	strcpy(course, "C_Programming");
	printf("\nprint a name = ");
	scanf("%s", name);        

	printf("\n%s is a student in %s.\n", name, course );

	course[13] = 'x';
    to_upper(name);
    printf("Our student %s is now all upper case in course %s!\n", name, course);
    	
	system("sleep 2");
	return 0;
} 

void to_upper(char *word) {
	int index = 0;
	while (word[index] != '\0') {
	    word[index] = toupper(word[index]);
	    index++;
	}
}

