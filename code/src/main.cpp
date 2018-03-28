/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, TEC, Costa Rica
 *
 * This file is part of the CE3102 Numerical Analysis lecture at TEC
 *
 * @Author: 
 * @Date  : 24.02.2018
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "LUDoolittle.hpp"

int main() {

  // Some example code
   // Some example code
  anpi::Matrix<float> A = { {-1,-2,1,2},
                            { 2, 0,1,2},
                            {-1,-1,0,1},
                            { 1, 3,-1,1} };
  anpi::Matrix<float> LU;
  
  std::vector<size_t> p = {0,0,0,0};
  anpi::luDoolittle(A,LU,p);

















  //Ejemplo de producto vector matrix;
  /*anpi::Matrix<float> A = { {-1,1},
                            { 0,1},
                            {-1,0},
                            };
  anpi::Matrix<float> LU = {{1 , 2 , 3 },  {2, 1, 3}, {0, 2, -3}};
  
  std::vector<float> p = {1 , 3, -2};
  std::vector<float> m = p*A;
  for (int i=0; i<m.size(); ++i){
    std::cout << m[i] << "\t"  << std::endl;
  }

  */
  //anpi::luDoolittle(A,LU,p);






  /*
  Ejemplo multi matrices:

  anpi::Matrix<float> A = { {-1,-2,1},
                            { 2, 0,1},
                            {-1,-1,0},
                            };
  anpi::Matrix<float> LU = {{1 , 2 , 3 },  {2, 1, 3}, {0, 2, -3}};
  
  anpi::Matrix<float> m = A * LU;
  for (int i = 0; i < m.rows(); i++){
    for (int j = 0; j< m.cols(); ++j){
      std::cout << m[i][j] << "\t"; 
    }
    std::cout << std::endl;
  }
  */

  return EXIT_FAILURE;
}
  
