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
#include "LUCrout.hpp"
#include "Pivot.hpp"

int main() {

  // Some example code
   // Some example code
  //anpi::Matrix<float> A = { {-1,-2,1,2},
    //                        { 2, 0,1,2},
      //                      {-1,-1,0,1},
        //                    { 1, 3,-1,1} };
  //anpi::Matrix<float> A = {{0, 0,2},{-1, 5 ,-2},{3,6,7}};
  anpi::Matrix<float> LU;
  anpi::Matrix<float> A = {{1, 3, 5},{-2, 4 ,6},{5,0,3}};

  std::vector<size_t> p;
  //anpi::luDoolittle(A,LU,p);
  anpi::Matrix<float> U, L;
  std::cout << "crout" << std::endl;
  anpi::Matrix<float> LUC;
  std::vector<size_t> pC;
  anpi::luCrout(A,LUC,pC);
  anpi::unpackCrout(LUC, L, U );

















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
  
