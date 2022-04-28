#include <stdio.h>
#include "mnblas.h"
#include "complexe.h"
#include "flop.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;
typedef double vdouble [VECSIZE] ;
typedef complexe_float_t vcomplexefloat [VECSIZE] ;
typedef complexe_double_t vcomplexedouble [VECSIZE] ;

vfloat vfloat1, vfloat2 ;
vdouble vdouble1, vdouble2 ;
vcomplexefloat vcomplexefloat1, vcomplexefloat2 ;
vcomplexedouble vcomplexedouble1, vcomplexedouble2 ;

int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 
 float res ;
 int i ;

for (int i = 0; i < VECSIZE; i++)
{
  vfloat1[i] = 5;
  vfloat2[i] = 5;
  vdouble1[i] = 5;
  vdouble2[i] = 5;
  vcomplexefloat1[i] = (complexe_float_t){5,5};
  vcomplexefloat2[i] = (complexe_float_t){5,5};
  vcomplexedouble1[i] = (complexe_double_t){5,5};
  vcomplexedouble2[i] = (complexe_double_t){5,5};
}

    // ------------ test fonction mncblas_sdot --------------- 
 init_flop_tsc () ;
 for (i = 0 ; i < NB_FOIS; i++)
   {
     res = 0.0 ;
     start_tsc = _rdtsc () ;
        res = mncblas_sdot (VECSIZE, vfloat1, 1, vfloat1, 1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_sdot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     res = 0.0 ;
     TOP_MICRO(start) ;
        res = mncblas_sdot (VECSIZE, vfloat1, 1, vfloat1, 1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_sdot micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;




   // ------------ test fonction mncblas_ddot --------------- 
 init_flop_tsc () ;
     double resd = 0.0 ;
 for (i = 0 ; i < NB_FOIS; i++)
   {
     resd = 0.0 ;
     start_tsc = _rdtsc () ;
        resd = mncblas_ddot (VECSIZE, vdouble1, 1, vdouble2, 1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_ddot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }

 printf ("res = %f\n", resd) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     resd = 0.0 ;
     TOP_MICRO(start) ;
        resd = mncblas_ddot (VECSIZE, vfloat1, 1, vfloat1, 1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_ddot micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }

 printf ("res = %f\n", resd) ;
 printf ("==========================================================\n") ;


    // ------------ test fonction mncblas_cdotu_sub --------------- 
    void* dotu;
 init_flop_tsc () ;
 for (i = 0 ; i < NB_FOIS; i++)
   {
     start_tsc = _rdtsc () ;
     mncblas_cdotu_sub (VECSIZE, vcomplexefloat1, 1, vcomplexefloat2, 1, dotu) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_cdotu_sub nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     TOP_MICRO(start) ;
     mncblas_cdotu_sub (VECSIZE, vcomplexefloat1, 1, vcomplexefloat2, 1, dotu) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_cdotu_sub micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }

 printf ("==========================================================\n") ;


    // ------------ test fonction mncblas_cdotc_sub --------------- 
 init_flop_tsc () ;
 for (i = 0 ; i < NB_FOIS; i++)
   {
     start_tsc = _rdtsc () ;
     mncblas_cdotc_sub (VECSIZE, vcomplexefloat1, 1, vcomplexefloat2, 1, dotu) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_cdotc_sub nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     TOP_MICRO(start) ;
     mncblas_cdotc_sub (VECSIZE, vcomplexefloat1, 1, vcomplexefloat2, 1, dotu) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_cdotc_sub micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }

 printf ("==========================================================\n") ;




    // ------------ test fonction mncblas_zdotu_sub --------------- 
 init_flop_tsc () ;
 for (i = 0 ; i < NB_FOIS; i++)
   {
     res = 0.0 ;
     start_tsc = _rdtsc () ;
     mncblas_zdotu_sub (VECSIZE, vcomplexedouble1, 1, vcomplexedouble2, 1, dotu) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_zdotu_sub nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }

 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     res = 0.0 ;
     TOP_MICRO(start) ;
     mncblas_zdotu_sub (VECSIZE, vcomplexedouble1, 1, vcomplexedouble2, 1, dotu) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_zdotu_sub micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }

 printf ("==========================================================\n") ;




    // ------------ test fonction mncblas_zdotc_sub --------------- 
 init_flop_tsc () ;
 for (i = 0 ; i < NB_FOIS; i++)
   {
     start_tsc = _rdtsc () ;
     mncblas_zdotc_sub (VECSIZE, vcomplexedouble1, 1, vcomplexedouble2, 1, dotu) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_zdotc_sub nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }

 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     TOP_MICRO(start) ;
     mncblas_zdotc_sub (VECSIZE, vcomplexedouble1, 1, vcomplexedouble2, 1, dotu) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_zdotc_sub micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }

 printf ("==========================================================\n") ;


}