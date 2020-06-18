# GEMV_Halide_
Halide implementation of GEMV : General Matrix-Vector Multiplication (a Level 2 BLAS routine ) 

Given an input mxn matrix A (A has m rows and n columns) and an input vector X of dimension n, we compute a vector Y of dimension m, defined by: yi = Σ Aik Xk. In other words, component i of Y is the dot product of row i of A (a vector of dimension n) and vector X.
