#include <stdio.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;

vfloat vec1, vec2 ;

void vector_init (vfloat V, float x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

  return ;
}

void vector_print (vfloat V)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    printf ("%f ", V[i]) ;
  printf ("\n") ;
  
  return ;
}

int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 
 float res ;
 int i ;

 init_flop_tsc () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_init (vec1, 1.0) ;
     vector_init (vec2, 2.0) ;
     res = 0.0 ;
     
     start_tsc = _rdtsc () ;
        res = mncblas_sdot (VECSIZE, vec1, 1, vec2, 1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("sdot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }


  /*dot : The dot functions compute the dot product dot of two distributed REAL vectors
   res = I1*J1+I2*J2+...+In*Jn
  

    // ------------ test fonction sdot --------------- 

    float Xf[10] = {0,1,2,3,4,5,6,7,8,9};
    //float Xfbis[20] = {0,1,2,3,4,5,6,7,8,9,20,21,22,23,24,25,26,27,28,29};
    float Yf[10] = {10,11,12,13,14,15,16,17,18,19};

        
    printf("resultat test sdot : %f \n", mncblas_sdot(10,Xf,1,Yf,1));
    //printf ("resultat: %f \n", mncblas_sdot(10,Xfbis,2,Yf,1));
    */

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_init (vec1, 1.0) ;
     vector_init (vec2, 2.0) ;
     res = 0.0 ;
     
     TOP_MICRO(start) ;
        res = mncblas_sdot (VECSIZE, vec1, 1, vec2, 1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("sdot micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;

 init_flop_tsc () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_init (vec1, 1.0) ;
     vector_init (vec2, 2.0) ;
     res = 0.0 ;
     
     start_tsc = _rdtsc () ;
        res = mncblas_sdot (VECSIZE, vec1, 1, vec2, 1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_nano ("sdot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;

}

    /*
    // ------------ test fonction ddot ---------------  

    double Xd[10] = {0,1,2,3,4,5,6,7,8,9};
    double Yd[10] = {10,11,12,13,14,15,16,17,18,19};

    printf("resultat test ddot : %f \n", mncblas_ddot(10,Xd,1,Yd,1));

    */


    /*dotu : The dotu functions compute the dot product dot of two distributed COMPLEX vectors
   res = I1*J1+I2*J2+...+In*Jn
  

    // ------------ test fonction dotu --------------- 
                         
    complexe_float_t c1= (complexe_float_t){1.0, 1.0} ;
    complexe_float_t c2= (complexe_float_t){2.0, 2.0} ;
    complexe_float_t c3= (complexe_float_t){3.0, 4.0} ;
    complexe_float_t d = (complexe_float_t){0.0, 0.0} ;
    
    complexe_float_t Xc[3] = {c1, c2, c3};
    complexe_float_t Yc[3] = {c3, c2, c1};

    void* dotu = &d;

    mncblas_cdotu_sub(3, Xc, 1, Yc, 1, dotu);
    for (int i = 0; i < 3; i++)
    {
  
    }
    */

    /*dotc : The dotc functions compute the dot product dotc of two COMPLEX vectors one of them is CONJUGATED
    res = conj(I1)*J1+conj(I2)*J2+...+conj(In)*Jn
    */

    /*
    const complexe_float_t c1= (complexe_float_t){1.0, 1.0} ;
    const complexe_float_t c2= (complexe_float_t){2.0, 2.0} ;
    const complexe_float_t c3= (complexe_float_t){3.0, 4.0} ;
    const complexe_float_t d = (complexe_float_t){0.0, 0.0} ;

    const complexe_float_t Xc[3] = {c1, c2, c3};
    const complexe_float_t Yc[3] = {c3, c2, c1};

    void* dotc = &d;

    const int N = 3;
    const int M = 1;

    mncblas_cdotc_sub(N, (void*)Xc, M, (void*)Yc, M, dotc);
    printf("Valeur %f, %f \n",  (*((complexe_float*)dotc)).real, (*((complexe_float*)dotc)).imaginary);
    */  