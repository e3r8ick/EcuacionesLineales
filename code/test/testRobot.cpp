/**
 * Copyright (C) 2017 
 * Área Académica de Ingeniería en Computadoras, TEC, Costa Rica
 *
 * This file is part of the CE3102 Numerical Analysis lecture at TEC
 *
 * @Author: Pablo Alvarado
 * @Date  : 10.02.2018
 */

#include <boost/test/unit_test.hpp>

#include "RobotLegendario.hpp"

#include <iostream>
#include <exception>
#include <cstdlib>
#include <complex>

#include <functional>

#include <cmath>

namespace anpi {
  namespace test {
    
    /// Test the given closed root finder
    template<typename T>
    void robotTest() {

      
        //test mapeo indice menor a cero
        {
            int m = 5;
            int n = 6;
            int i1 = -1; 
            int i2 = 1; 
            int j1 = 4;
            int j2 = 2;
            int result;

            result = mapeo(i1, j1, i2, j2, m, n);
            BOOST_CHECK(result == 0);
        }

        //test mapeo indice mayor a m o n 
        {
            int m = 5;
            int n = 6;
            int i1 = 1; 
            int i2 = 1; 
            int j1 = 4;
            int j2 = 152;
            int result;

            result = mapeo(i1, j1, i2, j2, m, n);
            BOOST_CHECK(result == 0);
        }

        //test completo
        {
            int m = 5;
            int n = 6;
            int i1 = 1; 
            int i2 = 3; 
            int j1 = 2;
            int j2 = 4;
            int result;

            result = mapeo(i1, j1, i2, j2, m, n);
            BOOST_CHECK(result == 29);
        }


        //mapeo inverso 
        {
          int mapeado = 5;
          int m = 6;
          int n = 8;

          mapeoInverso(mapeado,m,n);
          BOOST_CHECK();
        }
    }

  } // test
}  // anpi

BOOST_AUTO_TEST_SUITE( Robot )

BOOST_AUTO_TEST_CASE(mapeo) 
{
  anpi::test::robotTest<int>();
}



BOOST_AUTO_TEST_SUITE_END()
