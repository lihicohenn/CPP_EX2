//lihicohen1123@gmail.com
#include <iostream>
#include "SquareMat.hpp"

using namespace matrix;

int main() {
    SquareMat a(2), b(2);

    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    std::cout << "Matrix a:\n" << a;
    std::cout << "Matrix b:\n" << b;

    std::cout << "\nAddition (a + b):\n" << (a + b);
    std::cout << "Subtraction (a - b):\n" << (a - b);
    std::cout << "Negation (-a):\n" << -a;
    std::cout << "Multiplication (a * b):\n" << (a * b);
    std::cout << "Scalar multiplication (a * 2):\n" << (a * 2);
    std::cout << "Scalar multiplication (2 * a):\n" << (2 * a);
    std::cout << "Modulo by matrix (a % b):\n" << (a % b);
    std::cout << "Modulo by scalar (a % 3):\n" << (a % 3);
    std::cout << "Division by scalar (a / 2):\n" << (a / 2);
    std::cout << "Power (a ^ 2):\n" << (a ^ 2);
    std::cout << "Transpose (~a):\n" << ~a;
    std::cout << "Determinant (!a): " << !a << "\n";

    std::cout << "\nPrefix ++a:\n" << (++a);
    std::cout << "Postfix a++:\n" << (a++);
    std::cout << "After postfix a:\n" << a;

    std::cout << "\nPrefix --a:\n" << (--a);
    std::cout << "Postfix a--:\n" << (a--);
    std::cout << "After postfix a:\n" << a;

    std::cout << "\nComparison a == b: " << (a == b) << "\n";
    std::cout << "Comparison a != b: " << (a != b) << "\n";
    std::cout << "Comparison a < b:  " << (a < b) << "\n";
    std::cout << "Comparison a <= b: " << (a <= b) << "\n";
    std::cout << "Comparison a > b:  " << (a > b) << "\n";
    std::cout << "Comparison a >= b: " << (a >= b) << "\n";

    std::cout << "\nAssignment operators:\n";
    SquareMat c(2);
    c = a;
    c += b;
    std::cout << "c += b:\n" << c;

    c -= b;
    std::cout << "c -= b:\n" << c;

    c *= 2;
    std::cout << "c *= 2:\n" << c;

    c *= b;
    std::cout << "c *= b:\n" << c;

    c %= 3;
    std::cout << "c %= 3:\n" << c;

    c %= b;
    std::cout << "c %= b:\n" << c;

    return 0;
}
