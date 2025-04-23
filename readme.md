//lihicohen1123@gmail.com

Assignment 2 - Operation Loading in c++

Run Example:
make
./Main

to compile the project and run the tests:
make test
./Test

to clean the objects files:
make clean

to run memory leak analysis:
for main:make valgrind_main
for test:make valgrind_test

Project stracture:
├── CCP_files/          
│   ├── main.cpp
│   ├── SquareMat.cpp
|   ├── test.cpp
├── HPP_files/        
│   ├── doctest.h
│   ├── SquareMat.hpp
├── Makefile       
└── README.md 

General Explanation of the Code:

This project focuses on implementing a custom matrix class SquareMat in C++, using operator overloading. The class represents square matrixes and supports a set of functionalities detailed below:

 Arithmetic Operations:
+ – Adds two matrices element-wise.

- – Subtracts two matrices element-wise.

* – Matrix multiplication: each element is computed by the dot product of row and column.

/ – Divides each element of the matrix by a scalar or another matrix (element-wise division).

% – Applies modulus operation either element-wise (matrix % matrix) or by a scalar using fmod.

All these operations check size compatibility (i.e., same dimension) and throw exceptions for invalid inputs.

Unary - – Negates all values in the matrix.

Prefix/Postfix ++ – Increments every element in the matrix by 1.

Prefix/Postfix -- – Decrements every element in the matrix by 1.

~ – Transposes the matrix (swaps rows and columns).

! – Computes the determinant of the matrix using recursive minor expansion.

Comparison Operators:
==, !=, <, <=, >, >=

These operators do not compare individual elements directly, but instead compare the sum of all matrix elements, as defined in the assignment. Two matrices are considered equal if their total sums are equal.

Power Operator:
^ – Raises the matrix to a non-negative integer power using repeated multiplication. Power 0 returns the identity matrix.

Compound Assignment Operators:
+=, -=, *=, /=, %= – Modify the current matrix by performing the corresponding operation with another matrix or scalar.

Stream Output:
<< – Overloaded as a friend function to print the matrix in a formatted, readable way and to acsess the matrix fields


Testing: 

Automated testing is implemented using the doctest framework in test.cpp. The tests cover:

Construction and destruction of matrices

Arithmetic operations with valid and invalid input sizes

Edge cases like zero division and index out of bounds

Matrix increment/decrement (both prefix and postfix)

Logical comparisons and power operation

Determinant calculation and transpose

