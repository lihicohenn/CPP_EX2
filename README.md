//lihicohen1123@gmail.com

Assignment 2 - Operation Loading in c++

Run Example:
make
./Main

to compile the project and run the tests:
make test
./Test

* to clean the objects files:
make clean

to run memory leak analysis:
for main:make valgrind_main
for test:make valgrind_test

Project strcture:

├── CCP_files/          
│   ├── main.cpp
│   ├── SquareMat.cpp
|   └── test.cpp
├── HPP_files/        
│   ├── doctest.h
│   ├── SquareMat.hpp
|   └── Row.hpp
├── Makefile       
└── README.md

General Explanation of the Code:

This project focuses on implementing a custom matrix class SquareMat in C++, using operator overloading. The class SquareMat represents square matrixes and supports a set of functionalities detailed below:

 Arithmetic Operations:

operator + – Adds two matrices element-wise.

operator - - Subtracts two matrices element-wise.

operator * – Matrix multiplication: each element is computed by the dot product of row and column.

operator / – Divides each element of the matrix by a scalar or another matrix (element-wise division).

operator % – Applies modulus operation either element-wise (matrix % matrix) or by a scalar using fmod.

All these operations check size compatibility (i.e., same dimension) and throw exceptions for invalid inputs.

operator unary - – Negates all values in the matrix.

operator prefix/postfix ++ – Increments every element in the matrix by 1.

operator prefix/postfix -- – Decrements every element in the matrix by 1.

operator ~ – Transposes the matrix (swaps rows and columns).

operator ! – Computes the determinant of the matrix using recursive minor expansion.

operator comparison operators:
==, !=, <, <=, >, >=

These operators do not compare individual elements directly, but instead compare the sum of all matrix elements, as defined in the assignment. Two matrices are considered equal if their total sums are equal.

Power Operator:
^ – Raises the matrix to a non-negative integer power using repeated multiplication. Power 0 returns the identity matrix.

Compound Assignment Operators:
+=, -=, *=, /=, %= – Modify the current matrix by performing the corresponding operation with another matrix or scalar.

Stream Output:
<< – Overloaded as a friend function to print the matrix in a formatted, readable way and to acsess the matrix fields

I also added a class named: Row
I chose to add that class to solve the problem of creating elements in the matrix (with operator []) that the row is out of bounds (else i needed to return pointer to double and it was difficult to control this problem)

Testing: 

Automated testing is implemented using the doctest framework in test.cpp. The tests cover:

Construction and destruction of matrices

Arithmetic operations with valid and invalid input sizes

Edge cases like zero division and index out of bounds

Matrix increment/decrement (both prefix and postfix)

Logical comparisons and power operation

Determinant calculation and transpose

