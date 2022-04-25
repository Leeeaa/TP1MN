#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>
#include <math.h>

float mncblas_sasum(const int N, const float *X, const int incX, 
                 const float *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  float sasum = 0.0 ;
  float sum = 0;
  
  for (i = 0 ; i < N ; i += incX)
    {
      sum = X[i]*X[i] + Y[j]*Y[j];
      sasum += Math.pow(sum,0.5) ;
      j+=incY ;
    }

  return sasum ;
}

double mncblas_dasum(const int N, const double *X, const int incX, 
                 const double *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  double dasum = 0.0 ;
  double sum = 0;
  
  for (i = 0 ; i < N ; i += incX)
    {
      sum = X[i]*X[i] + Y[j]*Y[j];
      sasum += Math.pow(sum,0.5) ;
      j+=incY ;
    }

  return dasum ;
}

void   mncblas_casum(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  //done
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  float casum = 0.0 ;
  float sum = 0;
  
  for (i = 0 ; i < N ; i += incX)
    {
      sum = mult_complexe_float(((complexe_float*)X)[i]), (((complexe_float_t*)Y)[j]);
      sasum += Math.pow(sum,0.5) ;
      j+=incY ;
    }

  return casum ;
}

void   mncblas_zasum(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  double zasum = 0.0 ;
  double sum = 0;
  
  for (i = 0 ; i < N ; i += incX)
    {
      sum = mult_complexe_float(((complexe_double*)X)[i]), (((complexe_double*)Y)[j]);
      sasum += Math.pow(sum,0.5) ;
      j+=incY ;
    }

  return zasum ;
 
}



  
