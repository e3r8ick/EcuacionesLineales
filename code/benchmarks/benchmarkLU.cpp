/**
 * Copyright (C) 2017 
 * Área Académica de Ingeniería en Computadoras, TEC, Costa Rica
 *
 * This file is part of the CE3102 Numerical Analysis lecture at TEC
 *
 * @author Pablo Alvarado
 * @date   29.12.2017
 */


#include <boost/test/unit_test.hpp>


#include <iostream>
#include <exception>
#include <cstdlib>
#include <complex>

/**
 * Unit tests for the LU class
 */
#include "benchmarkFramework.hpp"
#include "Matrix.hpp"
#include "Allocator.hpp"
#include "LUDoolittle.hpp"
#include "LUCrout.hpp"

BOOST_AUTO_TEST_SUITE( LU )

/// Benchmark for addition operations
template<typename T>
class benchLU {
protected:
  /// Maximum allowed size for the square matrices
  const size_t _maxSize;

  /// A large matrix holding 
  anpi::Matrix<T> _data;

  /// State of the benchmarked evaluation
  anpi::Matrix<T> LU;
  anpi::Matrix<T> A = {{1,7,6,4},{2,17,27,17}};
  std::vector<size_t> p;
public:
  /// Construct
  benchLU(const size_t maxSize)
    : _maxSize(maxSize),_data(maxSize,maxSize,anpi::DoNotInitialize) {

    size_t idx=0;
    for (size_t r=0;r<_maxSize;++r) {
      for (size_t c=0;c<_maxSize;++c) {
        _data(r,c)=idx++;
      }
    }
  }

  /// Prepare the evaluation of given size
  void prepare(const size_t size) {
    assert (size<=this->_maxSize);
    this->A=std::move(anpi::Matrix<T>(size,size,_data.data()));
    this->LU=this->A;
  }
};

/// Provide the evaluation Doolittle method 
template<typename T>
class benchDoolittleFloat : public benchLU<T> {
public:
  /// Constructor
  benchDoolittleFloat(const size_t n) : benchLU<T>(n) { }
  
  // Evaluate Doolittle
  inline void eval() {
    anpi::luDoolittle(this->A,this->LU, this->p);
  }
};

/// Provide the evaluation Crout method 
template<typename T>
class benchCroutFloat : public benchLU<T> {
public:
  /// Constructor
  benchCroutFloat(const size_t n) : benchLU<T>(n) { }
  
  // Evaluate Crout
  inline void eval() {
    anpi::luCrout(this->A,this->LU, this->p);
  }
};

/// Provide the evaluation Doolittle method (Double)
template<typename T>
class benchDoolittleDouble : public benchLU<T> {
public:
  /// Constructor
  benchDoolittleDouble(const size_t n) : benchLU<T>(n) { }
  
  // Evaluate add in-place
  inline void eval() {
    anpi::luDoolittle(this->A,this->LU, this->p);
  }
};

/// Provide the evaluation Crout method 
template<typename T>
class benchCroutDouble : public benchLU<T> {
public:
  /// Constructor
  benchCroutDouble(const size_t n) : benchLU<T>(n) { }
  
  // Evaluate add on-copy
  inline void eval() {
    anpi::luCrout(this->A,this->LU, this->p);
  }
};

/**
 * Instantiate and test the methods of the Matrix class
 */
BOOST_AUTO_TEST_CASE( LU ) {

  std::vector<size_t> sizes = {  24,  32,  48,  64,
                                 96, 128, 192, 256,
                                384, 512};

  const size_t n=sizes.back();
  const size_t repetitions=100;
  std::vector<anpi::benchmark::measurement> times;

  {
    benchCroutFloat<float>  bcf(n);

    // Measure CroutFloat
    ANPI_BENCHMARK(sizes,repetitions,times,bcf);
    
    ::anpi::benchmark::write("Crout_float.txt",times);
    ::anpi::benchmark::plotRange(times,"Crout (float)","r");
  }

  {
    benchCroutDouble<double>  bcd(n);

    // Measure CroutSIMD
    ANPI_BENCHMARK(sizes,repetitions,times,bcd);
    
    ::anpi::benchmark::write("Crout_double.txt",times);
    ::anpi::benchmark::plotRange(times,"Crout (double) ","g");
  }
  
  {
    benchDoolittleFloat<float> bdf(n);

    // Measure in place add
    ANPI_BENCHMARK(sizes,repetitions,times,bdf);

    ::anpi::benchmark::write("Doolittle_float.txt",times);
    ::anpi::benchmark::plotRange(times,"Doolittle (float)","b");
  }

  {
    benchDoolittleDouble<double> bdd(n);

    // Measure in place add
    ANPI_BENCHMARK(sizes,repetitions,times,bdd);

    ::anpi::benchmark::write("Doolittle_double.txt",times);
    ::anpi::benchmark::plotRange(times,"Doolittle (double)","m");
  }
  
#if 0
  
  {
    benchCrout<double>  baoc(n);

    // Measure on-copy add
    ANPI_BENCHMARK(sizes,repetitions,times,baoc);
    
    ::anpi::benchmark::write("add_on_copy_double.txt",times);
    ::anpi::benchmark::plotRange(times,"On-copy (double)","g");
  }

  {
    benchDoolittle<double> baip(n);

    // Measure in place add
    ANPI_BENCHMARK(sizes,repetitions,times,baip);

    ::anpi::benchmark::write("add_in_place_double.txt",times);
    ::anpi::benchmark::plotRange(times,"In-place (double)","m");
  }
#endif
  
  ::anpi::benchmark::show();
}
  
BOOST_AUTO_TEST_SUITE_END()
