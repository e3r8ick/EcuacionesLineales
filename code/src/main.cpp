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

#include "RobotLegendario.hpp"
int main()
{
  
  anpi::Matrix<int> A = anpi::Matrix<int>(5*5, 4, 0);
  nodos(5,5,A,0);
  std::cout<<A[19][0]<<std::endl;
  std::cout<<A[19][1]<<std::endl;
  std::cout<<A[19][2]<<std::endl;
  std::cout<<A[19][3]<<std::endl;
}
