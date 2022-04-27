#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>
#include <math.h>


//The functions p?asum compute the sum of the magnitudes of elements of a distributed vector sub(x),

float mnblas_sasum(const int N, const float *X, const int incX)
{
  register unsigned int i = 0 ;
  float sasum = 0.0 ;
  float sum = 0;
  
  for (i = 0 ; i < N ; i += incX)
    {
      sum = X[i]*X[i] ;
      sasum += pow(sum,0.5) ;
    }

  return sasum ;
}

double mnblas_dasum(const int N, const double *X, const int incX)
{
  register unsigned int i = 0 ;
  double dasum = 0.0 ;
  double sum = 0;
  
  for (i = 0 ; i < N ; i += incX)
    {
      sum = X[i]*X[i];
      dasum += pow(sum,0.5) ;
    }

  return dasum ;
}

float mnblas_scasum(const int N, const void *X, const int incX)
{
  //done
  register unsigned int i = 0 ;
  float casum = 0.0 ;
  float sum = 0;
  
  for (i = 0 ; i < N ; i += incX)
    {
      sum = (((complexe_float_t*)X)[0].real) * (((complexe_float_t*)X)[0].real) + (((complexe_float_t*)X)[0].imaginary) * (((complexe_float_t*)X)[0].imaginary);
      casum += pow(sum,0.5) ;
    }

  return casum ;
}

double mnblas_dzasum(const int N, const void *X, const int incX)
{
  
  register unsigned int i = 0 ;
  double zasum = 0.0 ;
  double sum = 0;
  
  for (i = 0 ; i < N ; i += incX)
    {
      sum = (((complexe_double_t*)X)[0].real) * (((complexe_double_t*)X)[0].real) + (((complexe_double_t*)X)[0].imaginary) * (((complexe_double_t*)X)[0].imaginary);
      zasum += pow(sum,0.5) ;
    }

  return zasum ;
 
}



  
