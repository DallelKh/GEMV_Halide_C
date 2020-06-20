#include <stdio.h>
#include <stdlib.h>

    // Global Declarations

    int n,m; //Dimensions of Matrix and Vector
    FILE *input; //  pointer to file that contains Matrix,Vector Values
    FILE *output; //pointer to file that contains Halide Result

void retriveData(int A[m][n],int X[n]){
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
        //get integer
            fscanf(input,"%d", &temp);
            X[j]=temp;

    }
    return ;

}


void gemv(int A[m][n],int X[n],int Y[m]){

    int i,j,a,x;
    for (i = 0; i < m; i++){ Y[i]=0;

        for (j = 0; j <n; j++){
             a= A[i][j] ;
             x= X[j];
	    Y[i] +=  a*x;
	 }
    }
    return ;
}

 int validate_halide(int Y[m]){
        int j,temp;
        int H[m];

        //Retrieving results calculated by halide implementation
        output = fopen("./files/output","r");
    	if (output == NULL){
       		printf("Error! opening output file\n");
       		exit(1);
    	}
	printf("____Comparing C and Halide Results\n");
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
    input = fopen("./files/input","r");
    if (input == NULL){
       printf("Error! opening input file\n");
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
    printf("____Results Match\n");
    else printf("____Results Do Not Match! \n ----> re-Check the Dimensions and Data in input File\n");

   return 0;
}

