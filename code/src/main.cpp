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
#include "QRdecomp.hpp"
#include "Invert.hpp"
int main()
{

  anpi::Matrix<float> A = {{-1, -2, 1},
                           {2, 0, 1},
                           {-1, -1, 0}};
  anpi::Matrix<float> LU,L,U,LUC,LC,UC,Q,R,Qt, Ai;
  std::vector<float> x;
  std::vector<float> b = {1,0,-1};
  std::vector<size_t> permut, permutC;
  std::cout << "Doolittle" << std::endl;
  anpi::luDoolittle(A,LU,permut);
  std::cout << "LU: " << std::endl;
  printM(LU);
  anpi::unpackDoolittle(LU,L,U);
  std::cout << "L: " << std::endl;
  printM(L);
  std::cout << "U: " << std::endl;
  printM(U);
  std::cout << "L*U" <<std::endl;
  printM(L*U);
  std::cout << "Crout " << std::endl;
  anpi::luCrout(A,LUC, permut);
  std::cout << "LU: " << std::endl;
  printM(LUC);
  anpi::unpackCrout(LUC,LC,UC);
  std::cout << "L: " << std::endl;
  printM(LC);
  std::cout << "U: " << std::endl;
  printM(UC);
  std::cout << "L*U" <<std::endl;
  printM(LC*UC);
  std::cout << "Qr decomp" << std::endl;
  anpi::qr(A, Q, R);
  std::cout << "Q: " << std::endl;
  printM(Q);
  std::cout << "R: " << std::endl;
  printM(R);
  Qt = Q;
  for (int i = 0; i < (int) Q.rows(); ++i){
    for (int j = 0 ; j < (int) Q.rows(); ++j){
      Qt[j][i] = Q[i][j];
    }
  }
  std::cout << "Qt *R " <<std::endl;
  printM(Qt*R);
  std::cout << "Inversion " << std::endl;
  anpi::invert(A, Ai);
  std::cout << "Ai : " << std::endl;
  printM(Ai);
  std::cout << "Identity" << std::endl;
  printM(A*Ai);
  std::cout << "Solve B: LU" << std::endl;
  anpi::solveLU(A,x,b);
  std::cout << "x: " << std::endl;
  for (int i = 0; i < (int) x.size(); ++i){
    std::cout << x[i] << "\t";
  }
  std::cout << std::endl;
  x[0] = x[1] = x[2] = 0;
  std::cout << "Solve B: QR" << std::endl;
  anpi::solveQR(A, x, b);
  std::cout << "x: " << std::endl;
  for (int i = 0; i < (int) x.size(); ++i){
    std::cout << x[i] << "\t";
  }
  std::cout << std::endl;
  }
