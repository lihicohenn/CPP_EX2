//lihicohen1123@gmail.com
#pragma once
#include <iostream>
#include <stdexcept>

namespace matrix
{
    class Row
    {
    private:
        double* row;
        int size;
    public:
        Row(double* row, int size) : row(row), size(size) {}

        double& operator[](int index)
        {
            if (index < 0 || index >= size)
            {
                throw std::out_of_range("Index out of bounds");
            }
            return row[index];
        }

        const double& operator[](int index) const
        {
            if (index < 0 || index >= size)
            {
                throw std::out_of_range("Index out of bounds");
            }
            return row[index];
        }
    };  
    }
