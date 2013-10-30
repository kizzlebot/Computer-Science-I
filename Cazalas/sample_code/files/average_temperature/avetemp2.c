#include <stdio.h>

int main () {
    
    FILE *infile;
    int temp = 0, sum = 0, count= 0;
    double average;
    
    infile = fopen("max_temp.txt", "r");

    while (1) {
        fscanf(infile, "%d", &temp);
        if(temp<0) 
            break;
        sum += temp;
        count++;
    }

    average = sum*1.0/count;

    printf("\naverage max temp = %.2f\n", average);
    fclose(infile);

    system("PAUSE");
    return 0;

}
