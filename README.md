# GEMV_Halide_
Halide implementation of GEMV : General Matrix-Vector Multiplication (a Level 2 BLAS routine ) 

## GEMV routine

Given an input (m,n) matrix **A** (A has m rows and n columns) and an input vector **X** of dimension n, GEMV computes a vector **Y** of dimension m, defined by: **Y = A * X**. In other words, component i of Y is the dot product of row i of A (a vector of dimension n) and vector X.

## Requirements to run on a linux machine 
1. Install llvm 
1. Build Halide <br/>
    **---> Find out more about halide and how to set it up with llvm step by step at https://github.com/halide/Halide**
 
## How to run
* Clone repositiry 
```
git clone https://github.com/DallelKh/GEMV_Halide_C.git
```
* Go to Repository root
```
cd  GEMV_Halide_C/
```
* Set Script permission to allow execution
```
chmod +700 run.sh
```
* Execute the Script run.sh and add path to Halide like this (in case the repository was cloned in the same directory where Halide build directory resides) or provide yours accordingly
```
./run.sh  ../Halide/
```

## Martix ,Vector Data 
**Matrix A and Vector X are read from the file ./files/input**
to change the Data :
```
nano ./files/input
```
Modify there knowing that **first line represensts the dimensions m,n** respectively ,then comes the Matrix **A(m,n)** and the Vector **X(n)** 
```
5 3

1 4 1
5 6 1
6 1 1
7 2 0
8 3 0

3
7
4

```

**Execution results if Halide path is correct are either**

```
$ ./run.sh  ../Halide/
____Compiling ./code/Halidecode.c
____Executing Halide implementation
____Halide Results are written to output file
____Compiling ./code/Ccode.c
____Executing C implementation
____Comparing C and Halide Results
____Results Do Not Match!
 ----> re-Check the Dimensions and Data in input File

```
 
**Or**

```
$ ./run.sh  ../Halide/
____Compiling ./code/Halidecode.c
____Executing Halide implementation
____Halide Results are written to output file
____Compiling ./code/Ccode.c
____Executing C implementation
____Comparing C and Halide Results
____Results Match
```

