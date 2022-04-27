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
int mnblas_samin(const int N, const float *X, const int incX, void* min)
int mnblas_damin(const int N, const double *X, const int incX, void* min)
int mnblas_camin(const int N, const void *X, const int incX, void* min)
int mnblas_zamin(const int N, const void *X, const int incX, void* min)
*/


int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 int res = 0;
/*
 * 
 * 
 * Tests fonction mnblas_samin (avec des float)
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
        res = mnblas_samin (VECSIZE, vfloat1, (const int)1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_samin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vfloat1[i] = 3.0 + i;
        }
     
     TOP_MICRO(start) ;
        res = mnblas_samin (VECSIZE, vfloat1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_samin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;



/*
 * 
 * 
 * Tests fonction mnblas_damin (avec des double)
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
        res = mnblas_damin (VECSIZE, vdouble1,(const int)1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_damin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vdouble1[i] = 3.0 + i;
        }
     
     TOP_MICRO(start) ;
        res = mnblas_damin (VECSIZE, vdouble1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_damin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mnblas_camin (avec des complexe_float_t)
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
        res = mnblas_camin (VECSIZE, vcomplexefloat1, (const int)1) ;
     end_tsc = _rdtsc ();
     
     calcul_flop_tsc ("mnblas_camin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        res = mnblas_camin (VECSIZE, vcomplexefloat1, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_camin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mnblas_zamin (avec des complexe_double_t)
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
        res = mnblas_zamin (VECSIZE, vcomplexedouble1, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_zamin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        res = mnblas_zamin (VECSIZE, vcomplexedouble1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_zamin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;

}