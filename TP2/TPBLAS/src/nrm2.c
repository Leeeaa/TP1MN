#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>
#include <math.h>

//The p?nrm2 functions compute the Euclidean norm of a distributed vector sub(x)

float mncblas_snrm2(const int N, const float *X, const int incX)
{
  //done
  register unsigned int i = 0 ;
  float sum = 0.0;

  
  for (i = 0 ; i < N ; i += incX)
    {
      sum += X[i]*X[i];
      }
  float norm2 = pow (sum,0.5);

  return norm2;
}

double mncblas_dnrm2(const int N, const double *X, const int incX)
{
  //done
  register unsigned int i = 0 ;
  double sum = 0.0;

  
  for (i = 0 ; i < N ; i += incX)
    {
      sum += X[i]*X[i];
      }
  double dnorm2 = pow (sum,0.5);

  return dnorm2;
}

float mncblas_scnrm2(const int N, const void *X, const int incX)
{
  //done
  register unsigned int i = 0 ;
  float sum = 0.0;


  for (i = 0; i < N ; i += incX)
     {
        sum = pow( (((complexe_float_t*)X)[i].real) * (((complexe_float_t*)X)[i].real) + (((complexe_float_t*)X)[i].imaginary) * (((complexe_float_t*)X)[i].imaginary), 0.5 );
     }
    float cnorm2 = pow (sum,0.5);

  return cnorm2;
}

double mncblas_dznrm2(const int N, const void *X, const int incX)
{
   //done
  register unsigned int i = 0 ;
  double sum = 0.0;


  for (i = 0; i < N ; i += incX)
     {
        sum = pow( (((complexe_double_t*)X)[i].real) * (((complexe_double_t*)X)[i].real) + (((complexe_double_t*)X)[i].imaginary) * (((complexe_double_t*)X)[i].imaginary), 0.5 );
     }
    float znorm2 = pow (sum,0.5);

  return znorm2;
}