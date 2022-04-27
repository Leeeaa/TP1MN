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
int mnblas_isamin(const int N, const float *X, const int incX, void* min)
int mnblas_idamin(const int N, const double *X, const int incX, void* min)
int mnblas_icamin(const int N, const void *X, const int incX, void* min)
int mnblas_izamin(const int N, const void *X, const int incX, void* min)
*/


int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 int res = 0;
/*
 * 
 * 
 * Tests fonction mnblas_isamin (avec des float)
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
        res = mnblas_isamin (VECSIZE, vfloat1, (const int)1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_isamin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
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
        res = mnblas_isamin (VECSIZE, vfloat1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_isamin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;



/*
 * 
 * 
 * Tests fonction mnblas_idamin (avec des double)
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
        res = mnblas_idamin (VECSIZE, vdouble1,(const int)1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_idamin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
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
        res = mnblas_idamin (VECSIZE, vdouble1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_idamin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mnblas_icamin (avec des complexe_float_t)
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
        res = mnblas_icamin (VECSIZE, vcomplexefloat1, (const int)1) ;
     end_tsc = _rdtsc ();
     
     calcul_flop_tsc ("mnblas_icamin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
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
        res = mnblas_icamin (VECSIZE, vcomplexefloat1, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_icamin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mnblas_izamin (avec des complexe_double_t)
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
        res = mnblas_izamin (VECSIZE, vcomplexedouble1, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_izamin nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
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
        res = mnblas_izamin (VECSIZE, vcomplexedouble1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_izamin micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("min at index %d\n", res);
 printf ("==========================================================\n") ;

}