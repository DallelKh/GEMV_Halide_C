# GEMV_Halide_
Halide implementation of GEMV : General Matrix-Vector Multiplication (a Level 2 BLAS routine ) 

## GEMV Routine

Given an input (m,n) matrix **A** (A has m rows and n columns) and an input vector **X** of dimension n, GEMV computes a vector **Y** of dimension m, defined by: **Y = A * X**. In other words, component i of Y is the dot product of row i of A (a vector of dimension n) and vector X.

## Requirements to run on a linux machine 
1. Install llvm 
1. Build Halide 
 * **---> Find out more about halide and how to set it up with llvm step by step at https://github.com/halide/Halide**
 
