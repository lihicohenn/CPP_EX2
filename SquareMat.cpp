#include "SquareMat.hpp"
#include <stdexcept>
#include <cmath>

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


    SquareMat SquareMat::operator+(const SquareMat& other) const {
        if (n != other.n) {
            throw std::invalid_argument("both matrixes must be of the same size");
        }
    
        SquareMat ans(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans.sqrmat[i][j] = ans[i][j] + other.sqrmat[i][j];
            }
        }
    
        return ans;
    }

    double* SquareMat::operator[](int index) {
        if (index < 0 || index >= n) {
            throw std::out_of_range("Index out of bounds");
        }
        return sqrmat[index];
    }
    
    const double* SquareMat::operator[](int index) const {
        if (index < 0 || index >= n) {
            throw std::out_of_range("Index out of bounds");
        }
        return sqrmat[index];
    }

    SquareMat SquareMat::operator-(const SquareMat& other) const {
        if (n != other.n) {
            throw std::invalid_argument("both matrixes must be of the same size");
        }

        SquareMat ans(n);
        for (int i=0; i<n ; i++){
            for (int j=0; j<n; j++){
                ans.sqrmat[i][j] = ans[i][j] - other.sqrmat[i][j];   
            }
        }
        return ans;
    }

    SquareMat SquareMat::operator-() const {
        SquareMat ans(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = -sqrmat[i][j];
            }
        }
        return ans;    
    }

    SquareMat SquareMat::operator*(const SquareMat& other) const {
        if (n != other.n) {
            throw std::invalid_argument("Both matrices must be of the same size");
        }
    
        SquareMat ans(n); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = 0; 
                for (int k = 0; k < n; k++) {
                    ans[i][j] += (*this)[i][k] * other[k][j];
                }
            }
        }
    
        return ans;
    }


    SquareMat SquareMat::operator*(double scalar) const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                result.sqrmat[i][j] = this->sqrmat[i][j] * scalar;
        return result;
        }

    SquareMat operator*(double scalar, const SquareMat& mat) {
        SquareMat result(mat.n);
        for (int i = 0; i < mat.n; ++i){
            for (int j = 0; j < mat.n; ++j){
                result.sqrmat[i][j] = scalar * mat.sqrmat[i][j]; }
            }
            
            return result;
        }
        
    SquareMat SquareMat::operator% (const SquareMat& other) const{
        if (n != other.n){
           throw std::invalid_argument("Both matrices must be of the same size"); 
        }
        SquareMat ans(n);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                ans[i][j] = (*this)[i][j] * other.sqrmat[i][j];
            }
        }
        return ans;
        }

    SquareMat SquareMat::operator% (int mod) const {
        SquareMat ans(n);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                ans[i][j] = fmod((*this)[i][j], mod);
            }
        }
            return ans;
        }

    SquareMat SquareMat::operator/(double scalar) const{
        if (scalar == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }
        SquareMat ans(n);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                ans[i][j] = (*this)[i][j] / scalar;
            }
        }
        return ans;
    }

    SquareMat SquareMat::operator^(int pow) const {
        if (pow < 0) {
            throw std::invalid_argument("Power must be non-negative");
        }
    
        if (pow == 0) {
            // creating the unit matrix
            SquareMat result(n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    result[i][j] = (i == j) ? 1 : 0;
                }
            }
            return result;
        }
    
        // multipy the matrix by itself pow times
        SquareMat result = *this; 
        for (int i = 1; i < pow; ++i) {
            result = result * (*this);
        }
    
        return result;
    }
    


    // prefix
    SquareMat SquareMat::operator++(){
        SquareMat ans(n);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                ans[i][j] = (*this)[i][j] + 1;
            }
        }
        return ans;
         }

        // prefix
        SquareMat SquareMat::operator--(){
            SquareMat ans(n);
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    ans[i][j] = (*this)[i][j] -1;
                }
            }
            return ans;
        }

        //postfix
        SquareMat SquareMat::operator++(int) {
            SquareMat temp = *this; 
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    sqrmat[i][j] += 1;
                }
            }
            return temp; // returning the origin value
        }
        //postfix
        SquareMat SquareMat::operator--(int) {
            SquareMat temp = *this; 
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    sqrmat[i][j] -= 1; 
                }
            }
            return temp; // returning the origin value
        }

        }

    
