#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
using namespace matrix;

TEST_CASE("Constructor and Access") {
    CHECK_THROWS(SquareMat(0));
    CHECK_THROWS(SquareMat(-5));

    SquareMat m(3);
    CHECK(m.getSize() == 3);

    CHECK_NOTHROW(m[0][0] = 1);
    CHECK_NOTHROW(m[2][2] = 5);
    CHECK_THROWS(m[3][1]);
    CHECK_THROWS(m[-1][0]);
}

TEST_CASE("Addition and Subtraction") {
    SquareMat m1(2), m2(2);
    m1[0][0] = 1; m1[0][1] = 2; m1[1][0] = 3; m1[1][1] = 4;
    m2[0][0] = 4; m2[0][1] = 3; m2[1][0] = 2; m2[1][1] = 1;

    SquareMat sum = m1 + m2;
    CHECK(sum[0][0] == 5);
    CHECK(sum[1][1] == 5);

    SquareMat diff = m1 - m2;
    CHECK(diff[0][0] == -3);
    CHECK(diff[1][1] == 3);

    CHECK_THROWS(m1 + SquareMat(3));
}

TEST_CASE("Unary minus and Transpose") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2; m[1][0] = 3; m[1][1] = 4;

    SquareMat neg = -m;
    CHECK(neg[0][0] == -1);

    SquareMat trans = ~m;
    CHECK(trans[0][1] == 3);
    CHECK(trans[1][0] == 2);
}

TEST_CASE("Scalar Multiplication and Division") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2; m[1][0] = 3; m[1][1] = 4;

    SquareMat res = m * 2;
    CHECK(res[1][1] == 8);

    res = 2 * m;
    CHECK(res[0][1] == 4);

    res = m / 2;
    CHECK(res[1][0] == doctest::Approx(1.5));

    CHECK_THROWS(m / 0);
}

TEST_CASE("Matrix Multiplication") {
    SquareMat m1(2), m2(2);
    m1[0][0] = 1; m1[0][1] = 2; m1[1][0] = 3; m1[1][1] = 4;
    m2[0][0] = 2; m2[0][1] = 0; m2[1][0] = 1; m2[1][1] = 2;

    SquareMat res = m1 * m2;
    CHECK(res[0][0] == 4);
    CHECK(res[1][1] == 8);

    CHECK_THROWS(m1 * SquareMat(3));
}

TEST_CASE("Modulo") {
    SquareMat m1(2);
    m1[0][0] = 5.5; m1[0][1] = 4.1; m1[1][0] = 7.9; m1[1][1] = 2.5;

    SquareMat res = m1 % 2;
    CHECK(res[0][0] == doctest::Approx(fmod(5.5, 2)));

    SquareMat m2(2);
    m2[0][0] = 1; m2[0][1] = 2; m2[1][0] = 3; m2[1][1] = 4;

    res = m1 % m2;
    CHECK(res[1][0] == doctest::Approx(fmod(7.9, 3)));
}

TEST_CASE("Power Operator") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 1; m[1][0] = 1; m[1][1] = 0;

    SquareMat res = m ^ 3;
    CHECK(res[0][0] == 3);
    CHECK(res[1][0] == 2);

    CHECK_THROWS(m ^ -1);
}

TEST_CASE("Increment/Decrement Operators") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2; m[1][0] = 3; m[1][1] = 4;

    SquareMat res = ++m;
    CHECK(res[0][0] == 2);

    res = m++;
    CHECK(res[0][0] == 2);
    CHECK(m[0][0] == 3);

    res = --m;
    CHECK(res[0][0] == 2);

    res = m--;
    CHECK(res[0][0] == 2);
    CHECK(m[0][0] == 1);
}

TEST_CASE("Comparison Operators") {
    SquareMat m1(2), m2(2);
    m1[0][0] = 1; m1[0][1] = 2; m1[1][0] = 3; m1[1][1] = 4;
    m2[0][0] = 4; m2[0][1] = 3; m2[1][0] = 2; m2[1][1] = 1;

    CHECK(m1 == m2);
    m2[1][1] += 1;
    CHECK(m1 != m2);
    CHECK(m1 < m2);
    CHECK(m2 > m1);
    CHECK(m1 <= m2);
    CHECK(m2 >= m1);
}

TEST_CASE("Determinant Operator") {
    SquareMat m(3);
    m[0][0] = 6; m[0][1] = 1; m[0][2] = 1;
    m[1][0] = 4; m[1][1] = -2; m[1][2] = 5;
    m[2][0] = 2; m[2][1] = 8; m[2][2] = 7;

    double det = !m;
    CHECK(det == doctest::Approx(-306));
}

TEST_CASE("Assignment Operators") {
    SquareMat m1(2), m2(2);
    m1[0][0] = 1; m1[0][1] = 1; m1[1][0] = 1; m1[1][1] = 1;
    m2[0][0] = 2; m2[0][1] = 2; m2[1][0] = 2; m2[1][1] = 2;

    m1 += m2;
    CHECK(m1[0][0] == 3);

    m1 -= m2;
    CHECK(m1[0][0] == 1);

    m1 *= m2;
    CHECK(m1[0][0] == 4);

    m1 /= m2;
    CHECK(m1[0][0] == 2);

    m1 %= 3;
    CHECK(m1[0][0] == doctest::Approx(fmod(2,3)));
}
