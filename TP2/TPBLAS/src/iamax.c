#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>

float mncblas_samax(const int N, const float *X, const int incX)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  float max = X[0] ;
  int index = 0 ;
  
  for (i = 1 ; i < N ; i += incX)
    {
      if (X[i]>max){
      	max = X[i];
      	index = i;
      }
 
    }

  return index;
}

double mncblas_damax(const int N, const double *X, const int incX)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  double max = X[0] ;
  int index = 0 ;
  
  for (i = 1 ; i < N ; i += incX)
    {
      if (X[i]>max){
      	max = X[i];
      	index = i;
      }
 
    }

  return index;
}

void   mncblas_camax(const int N, const void *X, const int incX,
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

void   mncblas_zamax(const int N, const void *X, const int incX,
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