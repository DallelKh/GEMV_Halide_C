#include <stdio.h>
#include <stdlib.h>

// Global Declarations

    int n,m; //Dimensions of Matrix and Vector
    FILE *input; //  pointer to file that contains Matrix,Vector Values
    FILE *output; //pointer to file that contains Halide Result

void retriveData(int A[n][m],int X[n]){
    int temp,i,j;
    // filling A

    for (i = 0; i < m; i++)
    {
        for (j = 0; j <n; j++){
            fscanf(input,"%d", &temp);
            A[i][j]=temp;
        }
    }
    //filling X

    for (j = 0; j <n; j++){
        //get row
            fscanf(input,"%d", &temp);
            X[j]=temp;
    }
    return ;

}


void gemv(int A[m][n],int X[n],int Y[m]){

    int i,j;
    for (i = 0; i < m; i++){ Y[i]=0;
        for (j = 0; j <n; j++){
            Y[i] += A[i][j] * X[j];
        }
    }
    return ;
}

 int validate_halide(int Y[m]){
        int j,temp;
        int H[m];

        //Retrieving results calculated by halide implementation
        output = fopen("..\\files\\output.txt","r");
    	if (output == NULL){
       		printf("\nError! opening file");
       		exit(1);
    	}
         for (j = 0; j <m; j++){
                //get  int
                fscanf(output,"%d", &temp);
                H[j]= temp;

                if(Y[j]!=H[j])
                    return 0;
               }
           fclose(output);
        return 1;
 }

int main()

{    //opening Input file
    input = fopen("..\\files\\input.txt","r");
    if (input == NULL){
       printf("\nError! opening file");
       exit(1);
    }

    //getting dimensions n,m
    fscanf(input,"%d", &m);
    fscanf(input,"%d", &n);


   //Declaring and allocating  matrix A and vectors X,Y
    int A[m][n];
    int X[n];
    int Y[m];

   //filling A and X from file
   retriveData(A,X);
   fclose(input);

   //Calculating Y = A*X
   gemv(A,X,Y);

   //Checking with Halide Results
   if(validate_halide(Y))
    printf("\nResults Match\n");
    else printf("\nResults Do Not Match!\n");

   return 0;
}

