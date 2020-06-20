#include "Halide.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ostream>
using namespace std;
using namespace Halide;

void calculate_gemv(int m,int n,Halide::Buffer<int> A_Halide,Halide::Buffer<int> X_Halide,Halide::Buffer<int> Y_Halide)
{   //Declaring function gemv and needed variables
    Var i,j;
    Func gemv;
    //Rdom to make a reduction on the operations according to number of columns
    RDom r(0, n);
    // + a very useful Reduction helper is sum()
    gemv(i, j) = sum( A_Halide(r, j) * X_Halide(i) ) ;
    gemv.parallel(j);

    Y_Halide = gemv.realize(m, n);


    return;


}

int main(int argc, char **argv)
{
    int n=0,m=0;
    int i ,j;
    //getting dimensions m,n from input file
    fstream fs("./files/input", std::fstream::in);
    if (!fs.is_open())
        cout << "Unable to open input file\n";
    fs >> m ;
    fs >> n ;
	m=2;n=2;
    //creating the Matrix A ,Vector X,Y
    int A[2][2];
    int X[2];
    int Y[2];

    //reading Matrix A and Vector X from input file
    for ( i = 0; i < m; i++ )
      for ( j = 0; j < n; j++ )
        {  fs >> A[i][j] ;
        }
    for ( i = 0; i < n; i++ )
        {  fs >> X[i];
        }
     /* for ( i = 0; i < n; i++ )
            {//X
             printf("%d", X[i]);
            }*/
    fs.close();

    //Creating Halide buffers

    Halide::Buffer<int> A_Halide(A);
    Halide::Buffer<int> X_Halide(X);
    Halide::Buffer<int> Y_Halide(Y);

    //Calcul du produit avec func
    calculate_gemv(i,j,A_Halide,X_Halide,Y_Halide);
        // Or equivalently using a compile-time loop in our C++:
        // for (int i = 0; i < m; i++) {
        //      for(int i = 0; i < m; i++) {
        //   Y[j] += A[i][j] * X[j];
        //      }
        // }


  //writting results to outputfile
    ofstream myfile ("./files/output");
    if (myfile.is_open())
    {  for (i = 0; i < m; i++){
          myfile << Y_Halide(i) << "\n ";
     }
    myfile.close();
    }
    else {
	  cout << "Unable to open output file\n";
	  exit(1);}
    printf("____Halide Results are written to output file\n");
  return 0;


}


