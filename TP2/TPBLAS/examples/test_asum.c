#include <stdio.h>
#include "mnblas.h"
#include "complexe.h"
#include "flop.h"

#define VECSIZE    65536
#define NB_FOIS    10
typedef float vfloat [VECSIZE] ;
typedef double vdouble [VECSIZE];
typedef complexe_double_t vcomplexe_double_t [VECSIZE];
typedef complexe_float_t vcomplexe_float_t [VECSIZE];

vfloat vfloat1, vfloat2 ;
vdouble vdouble1, vdouble2;
vcomplexe_double_t vcomplexedouble1, vcomplexedouble2;
vcomplexe_float_t vcomplexefloat1, vcomplexefloat2;


/*
float   mnblas_sasum(const int N, const float *X, const int incX, 
                 const float *Y, const int incY)
double  mnblas_dasum(const int N, const double *X, const int incX, 
                 const double *Y, const int incY)
float   mnblas_scasum(const int N, const void *X, const int incX,
                       const void *Y, const int incY)
double   mnblas_dzasum(const int N, const void *X, const int incX,
                       const void *Y, const int incY)
*/


int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 

/*
 * 
 * 
 * Tests fonction mnblas_sasum (avec des float)
 * 
 * 
 */

 float res1 = 0.0 ;
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vfloat1[i] = 3.0;
           vfloat2[i] = 2.0;
       }
    
     start_tsc = _rdtsc () ;
        res1 = mnblas_sasum (VECSIZE, vfloat1, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_sasum nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("res = %f\n", res1) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vfloat1[i] = 3.0;
            vfloat2[i] = 2.0;
        }
        res1 = 0.0 ;
     
     TOP_MICRO(start) ;
        res1 = mnblas_sasum (VECSIZE, vfloat1, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_sasum micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("res = %f\n", res1) ;
 printf ("==========================================================\n") ;



/*
 * 
 * 
 * Tests fonction mnblas_dasum (avec des double)
 * 
 * 
 */
double res2 = 0.0;
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vdouble1[i] = 3.0;
           vdouble2[i] = 2.0;
       }
    
     start_tsc = _rdtsc () ;
        res2 = mnblas_dasum (VECSIZE, vdouble1, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_dasum nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("res = %f\n", res2) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vdouble1[i] = 3.0;
            vdouble2[i] = 2.0;
        }
        res2 = 0.0 ;
     
     TOP_MICRO(start) ;
        res2 = mnblas_dasum (VECSIZE, vdouble1, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_dasum micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("res = %lf\n", res2) ;
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mnblas_scasum (avec des complexe_float_t)
 * 
 * 
 */
float res3 = 0.0 ;
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0,4.5};
            vcomplexefloat2[i] = (complexe_float_t){2.3,5.9};
       }
     res3 = 0.0 ;
    
     start_tsc = _rdtsc () ;
        res3 = mnblas_scasum (VECSIZE, vcomplexefloat1, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_scasum nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("res = %f\n", res3) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0,4.5};
            vcomplexefloat2[i] = (complexe_float_t){2.3,5.9};
       }
        res3 = 0.0 ;
     
     TOP_MICRO(start) ;
        res3 = mnblas_scasum (VECSIZE, vcomplexefloat1, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_scasum micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("res = %f\n", res3) ;
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mnblas_dzasum (avec des complexe_double_t)
 * 
 * 
 */
double res4 = 0.0;
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0,4.5};
            vcomplexedouble2[i] = (complexe_double_t){2.3,5.9};
       }
     res4 = 0.0 ;
    
     start_tsc = _rdtsc () ;
        res4 = mnblas_dzasum (VECSIZE, vcomplexedouble1, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_dzasum nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("res = %f\n", res4) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0,4.5};
            vcomplexedouble2[i] = (complexe_double_t){2.3,5.9};
       }
        res4 = 0.0 ;
     
     TOP_MICRO(start) ;
        res4 = mnblas_dzasum (VECSIZE, vcomplexedouble1, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_dzasum micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("res = %lf\n", res4) ;
 printf ("==========================================================\n") ;

}