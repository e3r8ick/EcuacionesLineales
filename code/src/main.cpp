
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

int main() {
/*
    anpi::Matrix<float> A = { {-1,-2,1},
                          { 2, 0,1},
                          {-1,-1,0}
                          };
  anpi::InitializationType init=anpi::InitializationType::DoNotInitialize;
  anpi::Matrix<float> Q=anpi::Matrix<float>(A.rows(),A.cols(),init);
  anpi::Matrix<float> R=anpi::Matrix<float>(A.rows(),A.cols(),init);
  anpi::qr(A,Q,R);

  bool test =false;

  anpi::Matrix<float> Qt=anpi::Matrix<float>(A.rows(),A.cols(),init);
  anpi::Matrix<float> I=anpi::Matrix<float>(A.rows(),A.cols(),init);
  for(int i=0;i<A.rows();i++){
    for(int j=0;j<A.cols();j++){
      Qt(j,i)=Q(i,j);
    }
  }

  for(int i=0;i<A.rows();i++){
    for(int j=0;j<A.cols();j++){
      I(i,j)=0;
      I(i,i)=1;
    }
  }

  anpi::Matrix<float> tmp=anpi::Matrix<float>(A.rows(),A.cols(),init);
  tmp=Qt*R;


  test= (I==tmp);

  std::cout << "A" << std::endl;
  printM(A);
  std::cout << "Q" << std::endl;
  printM(Q);
  std::cout << "R" << std::endl;
  printM(R);
  std::cout << "I" << std::endl;
  printM(I);
  std::cout << "QT" << std::endl;
  printM(Qt);
  std::cout << "tmp" << std::endl;
  printM(tmp);

  std::cout<<"Q*Qt ? =I : "<<test<<std::endl;
  return 1;
  */
  anpi::Matrix<float> A = { {3,2,1},
                          { 5, 3,4},
                          {1,1,-1}
                          };

  std::vector<float> b={1,2,1};

  std::vector<float> x{0,0,0};
                          
  anpi::solveQR(A,x,b);

  std::cout<<"x: "<< x[0]<<"  "<<x[1]<<"  "<<x[2]<<std::endl;



}