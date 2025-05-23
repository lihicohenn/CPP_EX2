//lihicohen1123@gmail.com
#include "SquareMat.hpp"
#include <stdexcept>
#include <cmath>
#include "Row.hpp"

namespace matrix
{
    // constructor
    SquareMat::SquareMat(int size)
    {
        if (size <= 0)
        {
            throw std::invalid_argument("size of matrix must be positive");
        }
        if (size > 100)
        {
            throw std::invalid_argument("size of matrix must be less than 100");
        }

        n = size; 
        sqrmat = new double *[n]; 

        for (int i = 0; i < n; ++i)
        {
            sqrmat[i] = new double[n];
        }
    }

    // copy constructor
    SquareMat::SquareMat(const SquareMat &other)
    {
        copy_other(other);
    }
    // assignment operator
    SquareMat& SquareMat::operator=(const SquareMat &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < n; ++i)
            {
                delete[] sqrmat[i];
            }
            delete[] sqrmat;

            copy_other(other);
        }
        return *this;
    }
    // copy the other matrix
    void SquareMat::copy_other(const SquareMat &other)
    {
        n = other.n;
        sqrmat = new double *[n];
        for (int i = 0; i < n; ++i)
        {
            sqrmat[i] = new double[n];
            for (int j = 0; j < n; ++j)
            {
                sqrmat[i][j] = other.sqrmat[i][j];
            }
        }
    }

    // destructor
    SquareMat::~SquareMat()
    {
        for (int i = 0; i < n; ++i)
        {
            delete[] sqrmat[i];
        }
        delete[] sqrmat;
    }

    int SquareMat::getSize()
    {
        return n;
    }

    // add two matrixes
    SquareMat SquareMat::operator+(const SquareMat &other) const
    {
        if (n != other.n)
        {
            throw std::invalid_argument("both matrixes must be of the same size");
        }

        SquareMat ans(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans.sqrmat[i][j] = (*this)[i][j] + other.sqrmat[i][j];
            }
        }

        return ans;
    }
    // enable to use the [] operator- access the matrix
    Row SquareMat::operator[](int index) const
    {
        if (n <= 0)
        {
            throw std::invalid_argument("size of matrix must be positive");
        }
        if (index < 0 || index >= n)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return Row(sqrmat[index], n);
    }

    // // enable to use the [] operator- can change elements of the matrix
    // const double* SquareMat::operator[](int index) const
    // {
    //     if (index < 0 || index >= n)
    //     {
    //         throw std::out_of_range("Index out of bounds");
    //     }
    //     return sqrmat[index];
    // }

   

    // subtract two matrixes
    SquareMat SquareMat::operator-(const SquareMat &other) const
    {
        if (n != other.n)
        {
            throw std::invalid_argument("both matrixes must be of the same size");
        }

        SquareMat ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans.sqrmat[i][j] = (*this)[i][j] - other.sqrmat[i][j]; // insert the result in the new matrix
            }
        }
        return ans;
    }

    // negation
    SquareMat SquareMat::operator-() const
    {
        SquareMat ans(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans[i][j] = -sqrmat[i][j]; // insert the result in the new matrix
            }
        }
        return ans;
    }

    // multiplication of two matrixes
    SquareMat SquareMat::operator*(const SquareMat &other) const
    {
        if (n != other.n)
        {
            throw std::invalid_argument("Both matrices must be of the same size");
        }

        SquareMat ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = 0; // initialize the result to sero to prevent garbage values
                for (int k = 0; k < n; k++)
                {
                    ans[i][j] += (*this)[i][k] * other[k][j]; // multiply the elements
                }
            }
        }

        return ans;
    }

    // multiplication of matrix by scalar
    SquareMat SquareMat::operator*(double scalar) const
    {
        SquareMat result(n);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                result.sqrmat[i][j] = this->sqrmat[i][j] * scalar; //insert the result in the new matrix
            }}

        return result;
    }
    // multiplication of scalar by matrix
    // this is a friend function because it is not a member of the class
    SquareMat operator*(double scalar, const SquareMat &mat)
    {
        SquareMat result(mat.n);
        for (int i = 0; i < mat.n; ++i)
        {
            for (int j = 0; j < mat.n; ++j)
            {
                result.sqrmat[i][j] = scalar * mat.sqrmat[i][j]; // insert the result in the new matrix
            }
        }

        return result;
    }

    // multiplication of two matrixes - element by element
    SquareMat SquareMat::operator%(const SquareMat &other) const
    {
        if (n != other.n)
        {
            throw std::invalid_argument("Both matrices must be of the same size");
        }
        SquareMat ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = (*this)[i][j] * other.sqrmat[i][j]; // mul elemnt by elemnt
            }
        }
        return ans;
    }

    // Modulo by scalar
    SquareMat SquareMat::operator%(double mod) const
    {
        if (mod == 0) {
            throw std::invalid_argument("Modulo by zero is not allowed");
        }
        SquareMat ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = fmod((*this)[i][j], mod); //fmod is used to get the remainder of the division- function of <cmath>
            }
        }
        return ans;
    }

    // division of matrix by scalar
    SquareMat SquareMat::operator/(double scalar) const
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Cannot divide by zero");
        }
        SquareMat ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = (*this)[i][j] / scalar;
            }
        }
        return ans;
    }

    // power of matrix
    SquareMat SquareMat::operator^(int pow) const
    {
        if (pow < 0)
        {
            throw std::invalid_argument("Power must be non-negative");
        }

        if (pow == 0)
        {
            // creating the unit matrix
            SquareMat result(n);
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    result[i][j] = (i == j) ? 1 : 0;
                }
            }
            return result;
        }

        // multipy the matrix by itself pow times
        SquareMat result = *this;
        for (int i = 1; i < pow; ++i)
        {
            result = result * (*this);
        }

        return result;
    }

    // prefix
    SquareMat& SquareMat::operator++() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sqrmat[i][j] += 1;
            }
        }
        return *this;
    }

    // postfix
    SquareMat SquareMat::operator++(int)
    {
        SquareMat temp = *this;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sqrmat[i][j] += 1;
            }
        }
        return temp; // returning the origin value
    }

    // prefix
    SquareMat& SquareMat::operator--() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sqrmat[i][j] -= 1;
            }
        }
        return *this;
    }
    

    // postfix
    SquareMat SquareMat::operator--(int)
    {
        SquareMat temp = *this;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sqrmat[i][j] -= 1;
            }
        }
        return temp; // returning the origin value
    }

    // transpose
    SquareMat SquareMat::operator~()
    {
        SquareMat ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = (*this)[j][i]; // transpose the matrix- the cross stay the same and [i][]] = [j][i]
            }
        }
        return ans;
    }

    // sum of all elements in the matrix help function for the comparison operators
    // this function is private because it is not part of the API
    double SquareMat::sum() const
    {
        double total = 0.0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                total += (*this)[i][j];
            }
        }
        return total;
    }

    // comparison operators
    // all the comparison operators are based on the sum of the elements in the matrix
    bool SquareMat::operator==(const SquareMat &other) const
    {
        return this->sum() == other.sum();
    }

    bool SquareMat::operator!=(const SquareMat &other) const
    {
        return !(*this == other);
    }

    bool SquareMat::operator<(const SquareMat &other) const
    {
        return this->sum() < other.sum();
    }

    bool SquareMat::operator<=(const SquareMat &other) const
    {
        return this->sum() <= other.sum();
    }

    bool SquareMat::operator>(const SquareMat &other) const
    {
        return this->sum() > other.sum();
    }

    bool SquareMat::operator>=(const SquareMat &other) const
    {
        return this->sum() >= other.sum();
    }

    // determinant of the matrix
    double SquareMat::operator!() const
    {
        if (n == 1)
        {
            return (*this)[0][0]; // determinant of 1x1 matrix is the only element
        }
        if (n == 2)
        {
            return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0]; // determinant of 2x2 matrix is ad-bc
        }
        double det = 0;
        for (int j = 0; j < n; ++j)
        {
            // Create the minor matrix
            SquareMat minor(n - 1);

            for (int i = 1; i < n; ++i)
            { // start from row 1 skip row 0
                int sub_col = 0;
                for (int k = 0; k < n; ++k)
                {
                    if (k == j)
                        continue; // skip the current column j
                    minor[i - 1][sub_col] = (*this)[i][k];
                    ++sub_col;
                }
            }

            // Add signed expansion component to total determinant
            det += ((j % 2 == 0 ? 1 : -1) * (*this)[0][j] * !minor);
        }

        return det;
    }
    // +=, -=, *=, /=, %= operators
    // += operator
    // this operator is used to add two matrixes
    // the result is stored in the first matrix
    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        if (n != other.n){
            throw std::invalid_argument("matrixes must be in the same size");
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                (*this)[i][j] += other[i][j];
            }
        }
        return *this;
    }

    // -= operator
    // this operator is used to subtract two matrixes
    // the result is stored in the first matrix
    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        if (n != other.n){
            throw std::invalid_argument("matrixes must be in the same size");
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                (*this)[i][j] -= other[i][j];
            }
        }
        return *this;
    }
    // /= operator
    // this operator is used to divide two matrixes
    SquareMat& SquareMat::operator/=(const SquareMat& other) {
        if (n != other.n){
            throw std::invalid_argument("matrixes must be in the same size");
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j) {
                if (other[i][j] == 0){
                    throw std::invalid_argument("Can not divide by zero");
                }
                (*this)[i][j] /= other[i][j];
        } }
        return *this;
    }

    // *= operator
    // this operator is used to multiply matrix and scalar
    SquareMat& SquareMat::operator*=(double scalar) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                (*this)[i][j] *= scalar;
            }
        }
        return *this;
    }

    // *= operator
    // this operator is used to multiply two matrixes
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        if (n != other.n) {
            throw std::invalid_argument("matrixes must be in the same size");
        }
    
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = 0;
                for (int k = 0; k < n; ++k) {
                    result[i][j] += (*this)[i][k] * other[k][j];
                }
            }
        }
        *this = result;
        return *this;
    }

    // %= operator
    // this operator is used to modulo two matrixes
    // the result is stored in the first matrix
    SquareMat& SquareMat::operator%=(const SquareMat& other) {
        if (n != other.n) {
            throw std::invalid_argument("Matrix sizes must match for %= operator");
        }
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                (*this)[i][j] = fmod((*this)[i][j], other[i][j]);
            }
        }
    
        return *this;
    }

    // %= operator
    // this operator is used to modulo matrix by scalar
    // the result is stored in the first matrix
    SquareMat& SquareMat::operator%=(double scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Modulo by zero is not allowed");
        }
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                (*this)[i][j] = fmod((*this)[i][j], scalar);
            }
        }
    
        return *this;
    }
    

    

    // friend func to print the matrix
    std::ostream &operator<<(std::ostream &os, const SquareMat &mat)
    {
        for (int i = 0; i < mat.n; ++i)
        {
            for (int j = 0; j < mat.n; ++j)
            {
                os << mat[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

}
