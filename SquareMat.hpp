#pragma once
#include <iostream>

namespace matrix {

    class SquareMat {
    private:
        int n;
        double** sqrmat;

    public:
        SquareMat(int size);
        SquareMat(const SquareMat& other); 
        SquareMat& operator=(const SquareMat& other);
        ~SquareMat();
        void copy_other(const SquareMat& other); 
        int getSize();

        SquareMat operator+(const SquareMat& other) const;
        SquareMat operator-(const SquareMat& other) const;
        double* operator[](int index);
        const double* operator[](int index) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat& other) const;
        SquareMat operator*(double scalar) const;
        friend SquareMat operator*(double scalar, const SquareMat& mat);
        SquareMat operator% (const SquareMat& other) const;
        SquareMat operator% (int mod) const;
        SquareMat operator/(double scalar) const;
        SquareMat operator^(int pow) const;
        SquareMat operator++(); //prefix
        SquareMat operator--(); // prefix
        SquareMat operator++(int);  // postfix
        SquareMat operator--(int);  // postfix

       };

}
