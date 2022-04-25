#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>
#include <math.h>

//Computes the global index of the element of a distributed vector with maximum absolute value.

int mncblas_siamin(const int N, const float *X, const int incX, void* minimum)
{
  //done
  register unsigned int i = 0 ;
  float min = X[0] ;
  int index = 0 ;
  
  for (i = 1 ; i < N ; i += incX)
    {
      if (X[i]<min){
      	min = X[i];
      	index = i;
      }
 
    }
    *((float*)minimum) = X[index];

  return index;
}

int mncblas_diamin(const int N, const double *X, const int incX, void* minimum)
{
  //done
  register unsigned int i = 0 ;
  double min = X[0] ;
  int index = 0 ;
  
  for (i = 1 ; i < N ; i += incX)
    {
      if (X[i]<min){
      	min = X[i];
      	index = i;
      }
 
    }
    *((double*)minimum) = X[index];

  return index;
}

int mncblas_ciamin(const int N, const void *X, const int incX, void* minimum)
{
  //done
  register unsigned int i = 0 ;
  float min = pow( (((complexe_float_t*)X)[0].real) * (((complexe_float_t*)X)[0].real) + (((complexe_float_t*)X)[0].imaginary) * (((complexe_float_t*)X)[0].imaginary), 0.5 );
  int index = 0 ;

  for (i = 1 ; i < N ; i += incX)
    {
      float len = pow( (((complexe_float_t*)X)[i].real) * (((complexe_float_t*)X)[i].real) + (((complexe_float_t*)X)[i].imaginary) * (((complexe_float_t*)X)[i].imaginary), 0.5 );
      if (len < min)
      {
        min = len;
        index = i;
      }
 
    }
    *((complexe_float_t*)minimum) = ((complexe_float_t*)X)[index];

  return index;
}

int mncblas_ziamin(const int N, const void *X, const int incX, void* minimum)
{
   //done
  register unsigned int i = 0 ;
  float min = pow( (((complexe_double_t*)X)[0].real) * (((complexe_double_t*)X)[0].real) + (((complexe_double_t*)X)[0].imaginary) * (((complexe_double_t*)X)[0].imaginary), 0.5 );
  int index = 0 ;

  for (i = 1 ; i < N ; i += incX)
    {
      double len = pow( (((complexe_double_t*)X)[i].real) * (((complexe_double_t*)X)[i].real) + (((complexe_double_t*)X)[i].imaginary) * (((complexe_double_t*)X)[i].imaginary), 0.5 );
      if (len > min)
      {
        min = len;
        index = i;
      }
 
    }
    *((complexe_double_t*)minimum) = ((complexe_double_t*)X)[index];

  return index;

 
}