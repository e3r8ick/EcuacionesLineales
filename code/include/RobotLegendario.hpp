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

#include "Exception.hpp"
#include "Matrix.hpp"
#include "Pivot.hpp"

#ifndef ANPI_ROBOTLEGENDARIO_HPP
#define ANPI_ROBOTLEGENDARIO_HPP

namespace anpi
{

/**
 * 
 * 
 * 
 **/
int mapeo(int i1, int j1, int i2, int j2, int n)
{
    int iMayor, iMenor, jMenor;

    //sacamos el mayor y menor de i 
    if(i1 > i2){
        iMayor = i1;
        iMenor = i2;
    }else{
        iMayor = i2;
        iMenor = i1;
    }

    //sacamos el menor de j
    if(j1 > j2){
        jMenor = j2;
    }else{
        jMenor = j1;
    }


    int result = 2 * iMayor * (n-1) + jMenor + iMenor;

    if(iMayor == iMenor){
        return result;

    }
    return result-(n-1);

}

/**
 * 
 * 
 * 
 * */
void mapeoInverso(int mapeado, int m, int n)
{
    int iMayor, iMenor, jMayor, jMenor;
    int mn = 2*m-1;
    int tmp = mapeado % mn;
    int tmp2 = mapeado/mn;
    std::cout << tmp << std::endl;
    std::cout << tmp2 << std::endl;

    //sacamos j e i mayor y menor
    if(tmp > 3){ //horizontal
        tmp -= 4;
        jMenor = jMayor = tmp;
        iMenor = tmp2;
        iMayor = tmp2 + 1;
    }else{ //vertical
        jMenor = tmp;
        jMayor = tmp + 1;
        iMenor = iMayor = tmp2;
    }


}

void nodos(int m, int n, Matrix<int> &A, int index){
    int m1, m2, m3, m4;
    for(int i = 0; i < m; ++i){
        for(int j =0; j<n; ++j){
            m1 = m2 = m3 = m4 = (2*n*m - (m + n));//out of bounds
            if(i==0){
                m3=mapeo(i+1, j, i,j,n);
                if(j!=0){
                    m4=mapeo(i, j-1, i ,j,n);
                }if(j!=n-1){
                    m2=mapeo(i, j, i,j+1,n);
                }
            }else if(i == m-1){
                m1=mapeo(i-1, j, i ,j,n);
                if(j!=0){
                    m4=mapeo(i, j-1, i ,j,n);
                }if(j!=n-1){
                    m2=mapeo(i, j, i,j+1,n);
                }
            }else if(j==0){
                m1=mapeo(i-1, j, i ,j,n);
                m2=mapeo(i, j, i,j+1,n);
                m3=mapeo(i+1, j, i,j,n);
            }else if(j==4){
                m1=mapeo(i-1, j, i ,j,n);
                m4=mapeo(i, j-1, i ,j,n);
                m3=mapeo(i+1, j, i,j,n);
            }else{
                m1=mapeo(i-1, j, i ,j,n);
                m4=mapeo(i, j-1, i ,j,n);
                m3=mapeo(i+1, j, i,j,n);
                m2=mapeo(i, j, i,j+1,n);

            }
            A[index][0] = m4;
            A[index][1] = m1;
            A[index][2] = -m2;
            A[index][3] = -m3;
            ++index;
            
        }
    }
}

} //anpi

#endif
