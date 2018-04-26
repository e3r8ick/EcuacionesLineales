/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, TEC, Costa Rica
 *
 * This file is part of the CE3102 Numerical Analysis lecture at TEC
 *
 * @Author: 
 * @Date  : 24.02.2018
 */

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#define cimg_display 0
#include "CImg.h"
#include "Pivot.hpp"
#include "RobotLegendario.hpp"
using namespace cimg_library;
int main()
{
  CImg <unsigned char> image;
  int iin, ifin, jin, jfin;
  iin = 0;
  jin = 2;
  ifin = 1;
  jfin = 1;
  image.assign("image.bmp");
  int n = image.width();
  int m = image.height();
  anpi::Matrix<int> A = anpi::Matrix<int>(2*m*n-(m+n), 2*m*n-(m+n), 0);
  std::vector<int> resistors = anpi::getResistors(image);
  std::vector<int> b(2*m*n-(m+n),0);
  anpi::nodos(m, n, A, iin, jin, ifin, jfin, b);
  anpi::mallas(m, n, A, resistors);
  return 0 ;

}
