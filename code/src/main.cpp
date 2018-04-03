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
//#include "Matrix.hpp"
int main() {

  // Some example code
   // Some example code
  //anpi::Matrix<float> A = { {-1,-2,1,2},
    //                        { 2, 0,1,2},
      //                      {-1,-1,0,1},
        //                    { 1, 3,-1,1} };
  //anpi::Matrix<float> A = {{0, 0,2},{-1, 5 ,-2},{3,6,7}};
  /*anpi::Matrix<float> LU;
  anpi::Matrix<float> A = {{1, 3, 5},{-2, 4 ,6},{5,0,3}};

  std::vector<size_t> p;
  //anpi::luDoolittle(A,LU,p);
  anpi::Matrix<float> U, L;
  std::cout << "crout" << std::endl;
  anpi::Matrix<float> LUC;
  std::vector<size_t> pC;
  anpi::luCrout(A,LUC,pC);
  anpi::unpackCrout(LUC, L, U );*/

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


  //QR tests
/*
  void printMtx(anpi::Matrix<T>& M){
    std::cout<<"----"<<std::endl;
    for(int i=0;i<A.rows();i++){
      for(int j=0;j<A.cols();j++){
        std::cout<<" "<< M(i,j) <<" ";
      }
      std::cout<<std::endl;
    }
    std::cout<<"----"<<std::endl;
    std::cout<<std::endl;
  }
*/



  anpi::Matrix<float> A = { {-1,-2,1},
                          { 2, 0,1},
                          {-1,-1,0},
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
  tmp=Q*Qt;


  test= I==tmp;

  anpi::Matrix<float>::printMtx(A);
  anpi::Matrix<float>::printMtx(Q);
  anpi::Matrix<float>::printMtx(R);
  anpi::Matrix<float>::printMtx(I);
  anpi::Matrix<float>::printMtx(Qt);
  anpi::Matrix<float>::printMtx(tmp);


  std::cout<<"Q*Qt ? =I : "<<test<<std::endl;

  return EXIT_FAILURE;
}
  
