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
int mncblas_samin(const int N, const float *X, const int incX, void* min)
int mncblas_damin(const int N, const double *X, const int incX, void* min)
int mncblas_camin(const int N, const void *X, const int incX, void* min)
int mncblas_zamin(const int N, const void *X, const int incX, void* min)
*/


int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 int res = 0;
 void* min;
/*
 * 
 * 
 * Tests fonction mncblas_samin (avec des float)
 * 
 * 
 */

 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vfloat1[i] = 3.0 + i;
       }
     start_tsc = _rdtsc () ;
        res = mncblas_samin (VECSIZE, vfloat1, (const int)1, min);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_samin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("min at index %d : %f\n", res, *((float*)min));
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vfloat1[i] = 3.0 + i;
        }
     
     TOP_MICRO(start) ;
        res = mncblas_samin (VECSIZE, vfloat1, (const int)1, min);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_samin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("min at index %d : %f\n", res, *((float*)min));
 printf ("==========================================================\n") ;



/*
 * 
 * 
 * Tests fonction mncblas_damin (avec des double)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vdouble1[i] = 3.0 + i;
       }
    
     start_tsc = _rdtsc () ;
        res = mncblas_damin (VECSIZE, vdouble1,(const int)1, min);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_damin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("min at index %d : %lf\n", res, *((double*)min));
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vdouble1[i] = 3.0 + i;
        }
     
     TOP_MICRO(start) ;
        res = mncblas_damin (VECSIZE, vdouble1, (const int)1, min);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_damin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("min at index %d : %lf\n", res, *((double*)min));
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mncblas_camin (avec des complexe_float_t)
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
        res = mncblas_camin (VECSIZE, vcomplexefloat1, (const int)1, min) ;
     end_tsc = _rdtsc ();
     
     calcul_flop_tsc ("mncblas_camin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("min at index %d : (%f, %f)\n", res, ((complexe_float_t*)min)->real,((complexe_float_t*)min)->imaginary );
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        res = mncblas_camin (VECSIZE, vcomplexefloat1, (const int)1, min) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_camin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("min at index %d : (%f, %f)\n", res, ((complexe_float_t*)min)->real,((complexe_float_t*)min)->imaginary );
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mncblas_zamin (avec des complexe_double_t)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0 + i,4.5 + i};
       }
    
     start_tsc = _rdtsc () ;
        res = mncblas_zamin (VECSIZE, vcomplexedouble1, (const int)1, min) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_zamin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("min at index %d : (%lf, %lf)\n", res, ((complexe_double_t*)min)->real,((complexe_double_t*)min)->imaginary );
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        res = mncblas_zamin (VECSIZE, vcomplexedouble1, (const int)1, min);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_zamin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("min at index %d : (%lf, %lf)\n", res, ((complexe_double_t*)min)->real,((complexe_double_t*)min)->imaginary );
 printf ("==========================================================\n") ;

}