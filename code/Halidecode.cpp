#include "Halide.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ostream>

const int dim1 = 5;
const int dim2 =3;

using namespace std;
using namespace Halide;

int main(int argc, char **argv)
{    
    //m,n will contain the actual dimmension of the matrix
    int n,m;
    int i,j;//for loops
    //getting dimensions m,n from input file
    fstream fs("./files/input", std::fstream::in);
    if (!fs.is_open())
        cout << "Unable to open input file\n";
    fs >> m ;
    fs >> n ;
	m=2;n=2;
    //creating the Matrix A ,Vector X,Y
    int A[dim1][dim2];
    int X[dim2];
    int Y[dim1];

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

   
   //Declaring function gemv and needed variables
    Var d,e;
    Func gemv;
    //Rdom to make a reduction on the operations according to number of columns
    RDom r(0, n);
    //Creating Halide buffers
    Halide::Buffer<int> A_Halide(A);
    Halide::Buffer<int> X_Halide(X);
    Halide::Buffer<int> Y_Halide(Y);
    // + a very useful Reduction helper is sum()
    gemv(d,e) = sum( A_Halide(r, e) * X_Halide(d) ) ;
    gemv.parallel(e);

    Y_Halide = gemv.realize(m, n);

       // this is equivalent using a compile-time loop in our C++:
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


