#include <stdio.h>
#include <stdlib.h>





int main()
{
    int i,j;
    double value[10000][3];
    FILE *input;
    input = fopen("input.txt","r");
    if ((fptr = fopen("C:\\program.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if problem openning file.
       exit(1);
   }
    i=0;
    while (feof(archivo) == 0)
    {
        fscanf( archivo, "%lf %lf %lf", &value[i][0],&value[i][1],&value[i][2]);
        printf("%10.0f %f %f\n", value[i][0], value[i][1], value[i][2]);
        i++;
    }

    for (i = 0; i < rows; i++)
    {   Y[i]=0
	for (j = 0; j < cols; j++)
         {
        Y[i] += A[i][jfclose(input); ] * X[j];

	}
    }


    fclose(input);
    return 0;
}
