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

vfloat vfloat1;
vdouble vdouble1;
vcomplexe_double_t vcomplexedouble1;
vcomplexe_float_t vcomplexefloat1;

/*
float mncblas_snrm2(const int N, const float *X, const int incX)
double mncblas_dnrm2(const int N, const double *X, const int incX)
float mncblas_scnrm2(const int N, const void *X, const int incX)
double mncblas_dznrm2(const int N, const void *X, const int incX)
*/


int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 
 float resf = 0;
 double resd = 0;
/*
 * 
 * 
 * Tests fonction mncblas_snrm2 (avec des float)
 * 
 * 
 */

 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vfloat1[i] = 3.0+i;
       }
     start_tsc = _rdtsc () ;
        resf = mncblas_snrm2 (VECSIZE, vfloat1, (const int)1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_snrm2 nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("res = %f\n", resf);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vfloat1[i] = 3.0+i;
        }
     
     TOP_MICRO(start) ;
        resf = mncblas_snrm2 (VECSIZE, vfloat1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_snrm2 micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("res = %f\n", resf);
 printf ("==========================================================\n") ;



/*
 * 
 * 
 * Tests fonction mncblas_dnrm2 (avec des double)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vdouble1[i] = 3.0+i;
       }
    
     start_tsc = _rdtsc () ;
        resd = mncblas_dnrm2 (VECSIZE, vdouble1,(const int)1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_dnrm2 nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("res = %lf\n", resd);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vdouble1[i] = 3.0+i;
        }
     
     TOP_MICRO(start) ;
        resd = mncblas_dnrm2 (VECSIZE, vdouble1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_dnrm2 micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("res = %lf\n", resd);
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mncblas_scnrm2 (avec des complexe_float_t)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0+i,4.5+i};
       }
    
     start_tsc = _rdtsc () ;
        resf = mncblas_scnrm2 (VECSIZE, vcomplexefloat1, (const int)1) ;
     end_tsc = _rdtsc ();
     
     calcul_flop_tsc ("mncblas_scnrm2 nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("res = %f\n", resf);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        resf = mncblas_scnrm2 (VECSIZE, vcomplexefloat1, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_scnrm2 micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("res = %f\n", resf);
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mncblas_dznrm2 (avec des complexe_double_t)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0+i,4.5+i};
       }
    
     start_tsc = _rdtsc () ;
        resd = mncblas_dznrm2 (VECSIZE, vcomplexedouble1, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_dznrm2 nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("res = %lf\n", resd);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        resd = mncblas_dznrm2 (VECSIZE, vcomplexedouble1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_dznrm2 micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("res = %lf\n", resd);
 printf ("==========================================================\n") ;

}