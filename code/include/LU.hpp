/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @Author: 
 * @Date  : 03.03.2018
 */

#include <cmath>
#include <limits>
#include <functional>
#include <iostream>
#include <algorithm>

#include "LUCrout.hpp"
#include "LUDoolittle.hpp"
#include "Matrix.hpp"

#ifndef ANPI_LU_HPP
#define ANPI_LU_HPP

namespace anpi
{


template <typename T>
inline void lu(const anpi::Matrix<T> &A,
               anpi::Matrix<T> &LU,
               std::vector<size_t> &p)
{
    if(A.rows()<=4){
        anpi::luCrout(A, LU, p);
    }else{
        anpi::luDoolittle(A, LU, p);
    }
}

} //anpi

#endif
