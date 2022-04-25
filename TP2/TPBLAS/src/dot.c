#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>

/*
float mncblas_sdot(const int N, const float *X, const int incX, 
                 const float *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  register float dot = 0.0 ;
  
  for (; ((i < N) && (j < N)) ; i += incX, j+=incY)
    {
      dot = dot + X [i] * Y [j] ;
    }

  return dot ;
}
*/

float mncblas_sdot(const int N, const float *X, const int incX, 
                 const float *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  float dot = 0.0 ;

  
  for (i = 0 ; i < N ; i += incX)
    {
      dot += X [i] * Y [j] ;
      j+=incY ;
    }

  return dot ;
}

double mncblas_ddot(const int N, const double *X, const int incX, 
                 const double *Y, const int incY)
{
  //done
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  double dot = 0.0 ;

  
  for (i = 0 ; i < N ; i += incX)
    {
      dot += X [i] * Y [j] ;
      j+=incY ;
    }

  return dot ;
}

void   mncblas_cdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  //todo
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;

  complexe_float_t sum = (complexe_float_t){0,0}; // ou (complexe_float_t){0,0} ?

  for (i = 0 ; i < N ; i += incX)
    {
      printf ("test");
      sum = add_complexe_float(((complexe_float_t*)X)[i],((complexe_float_t*)Y)[j]);

      *((complexe_float_t*)(dotu)) = add_complexe_float(sum,*((complexe_float_t*)dotu));
      j+=incY ;

    }
  
  return ;
}

void   mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  /* a completer */
  
  return ;
}

void   mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  /* a completer */
  
  return ;
}
  
void   mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  /* a completer */
  
  return ;
}




