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
#include <algorithm>

#include "Exception.hpp"
#include "Matrix.hpp"

#ifndef ANPI_LU_DOOLITTLE_HPP
#define ANPI_LU_DOOLITTLE_HPP

namespace anpi
{

/**
   * Auxiliary method used to debug LU decomposition.
   *
   * It separates a packed LU matrix into the lower triangular matrix
   * L and the upper triangular matrix U, such that the diagonal of L
   * is composed by 1's.
   */
template <typename T>
void unpackDoolittle(const Matrix<T> &LU,
                     Matrix<T> &L,
                     Matrix<T> &U)
{

  throw anpi::Exception("To be implemented yet");
}

/**
   * Decompose the matrix A into a lower triangular matrix L and an
   * upper triangular matrix U.  The matrices L and U are packed into
   * a single matrix LU. 
   *
   * The L matrix will have in the Doolittle's LU decomposition a
   * diagonal of 1's
   *
   * @param[in] A a square matrix 
   * @param[out] LU matrix encoding the L and U matrices
   * @param[out] permut permutation vector, holding the indices of the
   *             original matrix falling into the corresponding element.
   *             For example if permut[5]==3 holds, then the fifth row
   *             of the LU decomposition in fact is dealing with the third
   *             row of the original matrix.
   *
   * @throws anpi::Exception if matrix cannot be decomposed, or input
   *         matrix is not square.
   */
template <typename T>
void pivot(const Matrix<T> &A,
           Matrix<T> &LU,
           std::vector<size_t> &permut)
{
  LU = A;
  int rows = A.rows();
  int columns = A.cols();
  T mayor;
  int index;
  bool setMayor;
  bool inPermutation;
  for (int j = 0; j < columns; ++j)
  {
    inPermutation = false;
    setMayor = false;
    for (int i = 0; i < rows; ++i)
    {

      for (int k = 0; k < j; ++k)
      {
        if (permut[k] == i)
        {
          inPermutation = true;
          break;
        }
      } //end iteración permutación
      if (!inPermutation)
      {
        if (!setMayor)
        {
          index = i;
          mayor = A[i][j];
          setMayor = true;
        }
        else if (std::abs(mayor) < std::abs(A[i][j]))
        {
          index = i;
          setMayor = true;
          mayor = A[i][j];
        }
      }
      else
      {
        inPermutation = false;
      }
      //not in permutation
    } //end rows A
    permut[j] = index;
    for (int n = 0; n < columns; ++n)
    {
      LU[j][n] = A[index][n];
    } //end for pivoting
  }   //end columns A
}

template <typename T>
void luDoolittle(const Matrix<T> &A,
                 Matrix<T> &LU,
                 std::vector<size_t> &permut)
{
  pivot(A, LU, permut);
  std::cout << "after pivot: " << std::endl;
  for (int i = 0; i < LU.rows(); ++i)
  {
    for (int j = 0; j < LU.cols(); ++j)
    {
      std::cout << LU[i][j] << "\t";
    }
    std::cout << std::endl;
  }

  //descomposicion LU
  int n = LU.rows();
  for (int k = 0; k < n - 1; ++k)
  {
    for (int i = k + 1; i < n; ++i)
    {
      T factor = LU[i][k] / LU[k][k];
      LU[i][k] = factor;
      for (int j = k + 1; j < n; ++j)
      {
        LU[i][j] -= factor * LU[k][j];
      }
    }
  }
  std::cout << "after LU " << std::endl;
  for (int m = 0; m < LU.rows(); ++m)
  {
    for (int x = 0; x < LU.cols(); ++x)
    {
      std::cout << LU[m][x] << "\tt";
    }
    std::cout << std::endl;
  }
}

} //anpi

#endif
