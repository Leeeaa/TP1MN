#include <stdio.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

/*
mncblas_saxpy(const int N, const float a, const float *X, const int incX, 
                 float *Y, const int incY)
mncblas_daxpy(const int N, const double a, const double *X, const int incX, 
                 double *Y, const int incY)
mncblas_caxpy(const int N, const void* a, const void *X, const int incX, 
		                    void *Y, const int incY)
mncblas_zaxpy(const int N, const void* a, const void *X, const int incX, 
		                    void *Y, const int incY)
*/
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


int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 float res ;
 

/*
 * 
 * 
 * Tests fonction mncblas_saxpy (avec des float)
 * 
 * 
 */

 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vfloat1[i] = 3.0;
           vfloat2[i] = 2.0;
       }
     const float a = 5.5;
     res = 0.0 ;
    
     start_tsc = _rdtsc () ;
        res = mncblas_saxpy (VECSIZE, a, vfloat1, (const int)1, vfloat2, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("sdot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vfloat1[i] = 3.0;
            vfloat2[i] = 2.0;
        }
        const float a = 5.5;
        res = 0.0 ;
     
     TOP_MICRO(start) ;
        res = mncblas_saxpy (VECSIZE, a, vfloat1, (const int)1, vfloat2, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("sdot micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;




/*
 * 
 * 
 * Tests fonction mncblas_daxpy (avec des double)
 * 
 * 
 */


 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vdouble1[i] = 3.0;
           vdouble2[i] = 2.0;
       }
     const float a = 5.5;
     res = 0.0 ;
    
     start_tsc = _rdtsc () ;
        res = mncblas_daxpy (VECSIZE, a, vdouble1, (const int)1, vdouble2, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("sdot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vdouble1[i] = 3.0;
            vdouble2[i] = 2.0;
        }
        const float a = 5.5;
        res = 0.0 ;
     
     TOP_MICRO(start) ;
        res = mncblas_daxpy (VECSIZE, a, vdouble1, (const int)1, vdouble2, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("sdot micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;





/*
 * 
 * 
 * Tests fonction mncblas_caxpy (avec des complexe_float_t)
 * 
 * 
 */

 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0,4.5};
            vcomplexefloat2[i] = (complexe_float_t){2.3,5.9};
       }
     const float a = 5.5;
     res = 0.0 ;
    
     start_tsc = _rdtsc () ;
        res = mncblas_caxpy (VECSIZE, a, vcomplexefloat1, (const int)1, vcomplexefloat2, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("sdot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vcomplexefloat1[i] = (complexe_float_t){3.0,4.5};
            vcomplexefloat2[i] = (complexe_float_t){2.3,5.9};
        }
        const float a = 5.5;
        res = 0.0 ;
     
     TOP_MICRO(start) ;
res = mncblas_caxpy (VECSIZE, a, vcomplexefloat1, (const int)1, vcomplexefloat2, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("sdot micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;




/*
 * 
 * 
 * Tests fonction mncblas_zaxpy (avec des complexe_double_t)
 * 
 * 
 */

 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0,4.5};
            vcomplexedouble2[i] = (complexe_double_t){2.3,5.9};
       }
     const float a = 5.5;
     res = 0.0 ;
    
     start_tsc = _rdtsc () ;
        res = mncblas_zaxpy (VECSIZE, a, vcomplexedouble1, (const int)1, vcomplexedouble2, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("sdot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vcomplexedouble1[i] = (complexe_double_t){3.0,4.5};
            vcomplexedouble2[i] = (complexe_double_t){2.3,5.9};
        }
        const float a = 5.5;
        res = 0.0 ;
     
     TOP_MICRO(start) ;
 res = mncblas_zaxpy (VECSIZE, a, vcomplexedouble1, (const int)1, vcomplexedouble2, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("sdot micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;

}