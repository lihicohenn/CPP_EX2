#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
using namespace matrix;

TEST_CASE("Constructor") {

    CHECK_THROWS(SquareMat(0));
    CHECK_THROWS(SquareMat(-5));

    SquareMat matrix(4);
    CHECK(matrix.getSize() == 4);

    CHECK_NOTHROW(matrix[0][1] = 1);
    CHECK_NOTHROW(matrix[2][0] = 5);
    CHECK_THROWS(matrix[4][1] = 2);
    CHECK_THROWS(matrix[-1][0] = 1);
}

TEST_CASE("Operator +/-") {
    SquareMat matrix1(2), matrix2(2);
    matrix1[0][0] = 5; matrix1[0][1] = 6; matrix1[1][0] = 7; matrix1[1][1] = 8;
    matrix2[0][0] = 1; matrix2[0][1] = 2; matrix2[1][0] = 3; matrix2[1][1] = 4;

    SquareMat sum = matrix1 + matrix2;
    CHECK(sum[0][0] == 6);
    CHECK(sum[1][0] == 10);

    SquareMat sub = matrix1 - matrix2;
    CHECK(sub[0][1] == 4);
    CHECK(sub[1][0] == 4);

    CHECK_THROWS(matrix1 + SquareMat(3));
    CHECK_THROWS(matrix2 - SquareMat(10));
}

TEST_CASE("Operator Unary-/Transpose~") {
    SquareMat matrix(2);
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[1][0] = 3; matrix[1][1] = 4;

    SquareMat neg = -matrix;
    CHECK(neg[0][0] == -1);
    CHECK(neg[0][1] == -2);

    SquareMat transpose = ~matrix;
    CHECK(transpose[0][1] == 3);
    CHECK(transpose[1][0] == 2);
}

TEST_CASE("Operator* - Matrix*Matrix") {
    SquareMat matrix1(3), matrix2(3);
    matrix1[0][0] = 1; matrix1[0][1] = 1; matrix1[0][2] = 2;
    matrix1[1][0] = 0; matrix1[1][1] = 1; matrix1[1][2] = 3; 
    matrix1[2][0] = 1; matrix1[2][1] = 0; matrix1[2][2]= 5;
    matrix2[0][0] = 1; matrix2[0][1] = 2; matrix2[0][2] = 3 ;
    matrix2[1][0] = 1; matrix2[1][1] = 2; matrix2[1][2] = 3;
    matrix2[2][0] = 1; matrix2[2][1] = 2; matrix2[2][2]= 3;


    SquareMat mul = matrix1 * matrix2;
    CHECK(mul[0][0] == 4);
    CHECK(mul[0][1] == 8);

    CHECK_THROWS(matrix1 * SquareMat(4));
    CHECK_THROWS(matrix2 * SquareMat(10));
}

TEST_CASE("Operator* - Matrix*Scalar and Scalar*Matrix"){
    SquareMat mul(2);
    double scalar = 2.0;
    mul[0][0] = 1; mul[0][1] = 2; mul[1][0] =3; mul[1][1] = 4;
    SquareMat ans = scalar*mul;
    CHECK(ans[0][0] == 2.0);
    CHECK(ans[0][1] == 4.0);

    SquareMat ans2 = mul*scalar;
    CHECK(ans[0][0] == 2.0);
    CHECK(ans[0][1] == 4.0);
    
}

TEST_CASE("Operator% -Multipation of elements"){
    SquareMat matrix1(3), matrix2(3);
    matrix1[0][0] = 1; matrix1[0][1] = 1; matrix1[0][2] = 2;
    matrix1[1][0] = 0; matrix1[1][1] = 1; matrix1[1][2] = 3; 
    matrix1[2][0] = 1; matrix1[2][1] = 0; matrix1[2][2]= 5;
    matrix2[0][0] = 1; matrix2[0][1] = 2; matrix2[0][2] = 3 ;
    matrix2[1][0] = 1; matrix2[1][1] = 2; matrix2[1][2] = 3;
    matrix2[2][0] = 1; matrix2[2][1] = 2; matrix2[2][2]= 3;

    SquareMat mulmod = matrix1 % matrix2;
    CHECK(mulmod[0][0] == 1);
    CHECK(mulmod[0][1] == 2);
    CHECK(mulmod[1][0] == 0);

    CHECK_THROWS(matrix1 * SquareMat(4));
    CHECK_THROWS(matrix2 * SquareMat(10));


}

TEST_CASE("Operator% -Modulo with scalar"){
    SquareMat mod(2);
    double scalar = 2.0;
    mod[0][0] = 4; mod[0][1] = 6; mod[1][0] =8; mod[1][1] = 9;


    SquareMat ans = mod%scalar;
    CHECK(ans[0][0] == 0.0);
    CHECK(ans[0][1] == 0.0);
    CHECK(ans[1][1] == 1.0);

    double scalar2 = 0.0;
    CHECK_THROWS(mod%scalar2);
    
}


TEST_CASE("Operator/") {
    SquareMat div(2);
    double scalar = 2.0;
    div[0][0] = 1; div[0][1] = 2; div[1][0] =3; div[1][1] = 4;

    SquareMat ans = div/scalar;
    CHECK(ans[0][0] == 0.5);
    CHECK(ans[0][1] == 1.0);

    double scalar2 = 0.0;
    CHECK_THROWS(div/scalar2);
 
}

TEST_CASE("Operator^") {
    SquareMat matrix(2);
    matrix[0][0] = 1; matrix[0][1] = 1; matrix[1][0] = 1; matrix[1][1] = 0;

    SquareMat ans = matrix ^ 3;
    CHECK(ans[0][0] == 3);
    CHECK(ans[1][0] == 2);
    CHECK(ans[1][1] == 1);

    CHECK_THROWS(matrix ^ -2);
}

TEST_CASE("Operator++ prefix") {
    SquareMat matrix(2);
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[1][0] = 3; matrix[1][1] = 4;

    SquareMat ans = ++matrix;
    CHECK(ans[0][0] == 2);
    CHECK(ans[0][1] == 3);
    CHECK(matrix[0][1] == 3);
}

TEST_CASE("Operator++ postfix") {
    SquareMat matrix(2);
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[1][0] = 3; matrix[1][1] = 4;

    SquareMat ans = matrix++;
    CHECK(ans[0][0] == 1);
    CHECK(ans[0][1] == 2);
    CHECK(matrix[0][1] == 3);
}

TEST_CASE("Operator-- prefix"){
    SquareMat matrix(2);
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[1][0] = 3; matrix[1][1] = 4;

    SquareMat ans = --matrix;
    CHECK(ans[0][0] == 0);
    CHECK(ans[0][1] == 1);
    CHECK(matrix[0][1] == 1);

}

TEST_CASE("Operator-- postfix"){
    SquareMat matrix(2);
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[1][0] = 3; matrix[1][1] = 4;

    SquareMat ans = matrix--;
    CHECK(ans[0][0] == 1);
    CHECK(matrix[0][0] == 0);
    CHECK(ans[0][1] == 2);

}


// TEST_CASE("Comparison Operators") {
//     SquareMat m1(2), m2(2);
//     m1[0][0] = 1; m1[0][1] = 2; m1[1][0] = 3; m1[1][1] = 4;
//     m2[0][0] = 4; m2[0][1] = 3; m2[1][0] = 2; m2[1][1] = 1;

//     CHECK(m1 == m2);
//     m2[1][1] += 1;
//     CHECK(m1 != m2);
//     CHECK(m1 < m2);
//     CHECK(m2 > m1);
//     CHECK(m1 <= m2);
//     CHECK(m2 >= m1);
// }

// TEST_CASE("Determinant Operator") {
//     SquareMat m(3);
//     m[0][0] = 6; m[0][1] = 1; m[0][2] = 1;
//     m[1][0] = 4; m[1][1] = -2; m[1][2] = 5;
//     m[2][0] = 2; m[2][1] = 8; m[2][2] = 7;

//     double det = !m;
//     CHECK(det == doctest::Approx(-306));
// }

// TEST_CASE("Assignment Operators") {
//     SquareMat m1(2), m2(2);
//     m1[0][0] = 1; m1[0][1] = 1; m1[1][0] = 1; m1[1][1] = 1;
//     m2[0][0] = 2; m2[0][1] = 2; m2[1][0] = 2; m2[1][1] = 2;

//     m1 += m2;
//     CHECK(m1[0][0] == 3);

//     m1 -= m2;
//     CHECK(m1[0][0] == 1);

//     m1 *= m2;
//     CHECK(m1[0][0] == 4);

//     m1 /= m2;
//     CHECK(m1[0][0] == 2);

//     m1 %= 3;
//     CHECK(m1[0][0] == doctest::Approx(fmod(2,3)));
// }
