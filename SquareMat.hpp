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
        SquareMat operator+(SquareMat matrix1, SquareMat matrix2);

       };

}
