#include "SquareMat.hpp"
#include <stdexcept>

namespace matrix {

    SquareMat::SquareMat(int size) {
        if (size <= 0) {
            throw std::invalid_argument("size must be positive");
        }

        n = size;
        sqrmat = new double*[n];

        for (int i = 0; i < n; ++i) {
            sqrmat[i] = new double[n];
            
        }
    }

    SquareMat::SquareMat(const SquareMat& other) {
        copy_other(other);
    }

    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this != &other) {
            for (int i = 0; i < n; ++i) {
                delete[] sqrmat[i];
            }
            delete[] sqrmat;

            copy_other(other);
        }
        return *this;
    }

    void SquareMat::copy_other(const SquareMat& other) {
        n = other.n;
        sqrmat = new double*[n];
        for (int i = 0; i < n; ++i) {
            sqrmat[i] = new double[n];
            for (int j = 0; j < n; ++j) {
                sqrmat[i][j] = other.sqrmat[i][j];
            }
        }
    }

    SquareMat::~SquareMat() {
        for (int i = 0; i < n; ++i) {
            delete[] sqrmat[i];
        }
        delete[] sqrmat;
    }

    int SquareMat::getSize(){
        return n;
    } 


    SquareMat SquareMat::operator+(SquareMat matrix1, SquareMat matrix2){
        int n = matrix1.getSize();
        int m = matrix2.getSize();
        if (m != n){
            throw std::invalid_argument("both matrix should be in the same size");
        }

        SquareMat ans(n);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                ans[i][j] = matrix1[i][j] + matrix2[i][j];
            }  
        }

        return ans;

    }

}
