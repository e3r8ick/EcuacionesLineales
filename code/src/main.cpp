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
//#define cimg_display 0
//#include "CImg.h"
#include "Pivot.hpp"
#include "RobotLegendario.hpp"
#include "SolveLU.hpp"
//using namespace cimg_library;
int main()
{
  CImg <unsigned char> image;
  image.assign("image.bmp"); //carga la imagen como un arrary de chars

  int iin, ifin, jin, jfin;
  iin = 0; //fila de inicio
  jin = 2; //columna de inicio 
  ifin = 1; //fila de fin 
  jfin = 1; // columna de fin
  int n = image.width(); //columnas
  int m = image.height(); //filas

  anpi::Matrix<double> A = anpi::Matrix<double>(2*m*n-(m+n), 2*m*n-(m+n), 0.0);
  std::vector<int> resistors = anpi::getResistors(image);  //crea el vector de resistencias
  std::vector<double> b(2*m*n-(m+n),0.0);
  anpi::nodos(m, n, A, iin, jin, ifin, jfin, b); //le da a b los valores de inicio y final que deben ser
  anpi::mallas(m, n, A, resistors);
  std::vector<double> x;
  anpi::solveLU(A, x, b);
 
  return 0 ;

}
