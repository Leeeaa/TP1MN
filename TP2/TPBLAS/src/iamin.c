#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>
#include <math.h>

//Computes the global index of the element of a distributed vector with minimum absolute value.

int mnblas_isamin(const int N, const float *X, const int incX)
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

  return index;
}

int mnblas_idamin(const int N, const double *X, const int incX)
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

  return index;
}

int mnblas_icamin(const int N, const void *X, const int incX)
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

  return index;
}

int mnblas_izamin(const int N, const void *X, const int incX)
{
   //done
  register unsigned int i = 0 ;
  float min = pow( (((complexe_double_t*)X)[0].real) * (((complexe_double_t*)X)[0].real) + (((complexe_double_t*)X)[0].imaginary) * (((complexe_double_t*)X)[0].imaginary), 0.5 );
  int index = 0 ;

  for (i = 1 ; i < N ; i += incX)
    {
      double len = pow( (((complexe_double_t*)X)[i].real) * (((complexe_double_t*)X)[i].real) + (((complexe_double_t*)X)[i].imaginary) * (((complexe_double_t*)X)[i].imaginary), 0.5 );
      if (len < min)
      {
        min = len;
        index = i;
      }
 
    }


  return index;

 
}