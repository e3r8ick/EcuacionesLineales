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
  std::cout << anpi::mapeo(1,2,2,2,5) << std::endl;
  std::cout << anpi::mapeo(1,1,1,2,5) << std::endl;
  std::cout << anpi::mapeo(0,2,1,2,5) << std::endl;
  std::cout << anpi::mapeo(0,2,0,3,5) << std::endl;
}
