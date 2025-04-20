#include <iostream>
#include "SquareMat.hpp"
#pragma once

namespace matrix {

    SquareMat::SquareMat(int size){
        if (size==0 || size<0 ){
            throw std::invalid_argument("value must be non-negative");
        }

        int n = size;
        double sqrmat = new double *[n]; 
        for (int i = 0; i < n; ++i) {
            sqrmat[i] = new double[n];  // dynamic allocation
            
        }

    SquareMat::~SquareMat() {
        for (int i = 0; i < n; ++i) {
            delete[] sqrmat[i];}

            delete[] sqrmat;
        }
    }
    


}