#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>
#include <math.h>

//Computes the global index of the element of a distributed vector with maximum absolute value.

int mncblas_isamax(const int N, const float *X, const int incX, void* maximum)
{
  //done
  register unsigned int i = 0 ;
  float max = X[0] ;
  int index = 0 ;
  
  for (i = 1 ; i < N ; i += incX)
    {
      if (X[i]>max){
      	max = X[i];
      	index = i;
      }
 
    }
    *((float*)maximum) = X[index];

  return index;
}

int mncblas_isamax(const int N, const double *X, const int incX, void* maximum)
{
  //done
  register unsigned int i = 0 ;
  double max = X[0] ;
  int index = 0 ;
  
  for (i = 1 ; i < N ; i += incX)
    {
      if (X[i]>max){
      	max = X[i];
      	index = i;
      }
 
    }
    *((double*)maximum) = X[index];

  return index;
}

int mncblas_icamax(const int N, const void *X, const int incX, void* maximum)
{
  //done
  register unsigned int i = 0 ;
  float max = pow( (((complexe_float_t*)X)[0].real) * (((complexe_float_t*)X)[0].real) + (((complexe_float_t*)X)[0].imaginary) * (((complexe_float_t*)X)[0].imaginary), 0.5 );
  int index = 0 ;

  for (i = 1 ; i < N ; i += incX)
    {
      float len = pow( (((complexe_float_t*)X)[i].real) * (((complexe_float_t*)X)[i].real) + (((complexe_float_t*)X)[i].imaginary) * (((complexe_float_t*)X)[i].imaginary), 0.5 );
      if (len > max)
      {
        max = len;
        index = i;
      }
 
    }
    *((complexe_float_t*)maximum) = ((complexe_float_t*)X)[index];

  return index;
}

int mncblas_izamax(const int N, const void *X, const int incX, void* maximum)
{
   //done
  register unsigned int i = 0 ;
  float max = pow( (((complexe_double_t*)X)[0].real) * (((complexe_double_t*)X)[0].real) + (((complexe_double_t*)X)[0].imaginary) * (((complexe_double_t*)X)[0].imaginary), 0.5 );
  int index = 0 ;

  for (i = 1 ; i < N ; i += incX)
    {
      double len = pow( (((complexe_double_t*)X)[i].real) * (((complexe_double_t*)X)[i].real) + (((complexe_double_t*)X)[i].imaginary) * (((complexe_double_t*)X)[i].imaginary), 0.5 );
      if (len > max)
      {
        max = len;
        index = i;
      }
 
    }
    *((complexe_double_t*)maximum) = ((complexe_double_t*)X)[index];

  return index;

 
}