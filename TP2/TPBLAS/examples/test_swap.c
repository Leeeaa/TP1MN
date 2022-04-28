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
vfloat vfloat2;
vdouble vdouble1;
vdouble vdouble2;
vcomplexe_double_t vcomplexedouble1;
vcomplexe_double_t vcomplexedouble2;
vcomplexe_float_t vcomplexefloat1;
vcomplexe_float_t vcomplexefloat2;



/*
void mncblas_sswap
void mncblas_dswap
void mncblas_cswap
void mncblas_zswap
*/


int main (int argc, char **argv)
{
    struct timeval start, end ;
    unsigned long long int start_tsc, end_tsc ;
    int incr = 1;
    for (int i = 0; i < VECSIZE; i++){
        vfloat1[i] = (float)i;
        vfloat2[i] = VECSIZE - (float)i;
        vdouble1[i] = (double)i;
        vdouble2[i] = VECSIZE - (double)i;
        vcomplexefloat1[i] = (complexe_float_t){i, i};
        vcomplexefloat2[i] = (complexe_float_t){VECSIZE - i, VECSIZE - i};
        vcomplexedouble1[i] = (complexe_double_t){i, i};
        vcomplexedouble2[i] = (complexe_double_t){VECSIZE - i, VECSIZE - i};
    }


/*
 * 
 * 
 * Tests fonction mncblas_sswap (avec des float)
 * 
 * 
 */

 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
     start_tsc = _rdtsc () ;
        mncblas_sswap(VECSIZE, vfloat1 , 1, vfloat2, 1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_sswap nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
     
     TOP_MICRO(start) ;
        mncblas_sswap(VECSIZE, vfloat1 , 1, vfloat2, 1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_sswap micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("==========================================================\n") ;



/*
 * 
 * 
 * Tests fonction mncblas_dswap (avec des double)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
     start_tsc = _rdtsc () ;
    mncblas_dswap (VECSIZE, vdouble1, 1, vdouble2, 1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_dswap nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }

 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
     
     TOP_MICRO(start) ;
    mncblas_dswap (VECSIZE, vdouble1, 1, vdouble2, 1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_dswap micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mncblas_cswap (avec des complexe_float_t)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
    {
   
    
     start_tsc = _rdtsc () ;
     mncblas_cswap (VECSIZE, vcomplexefloat1, 1, vcomplexefloat2, 1) ;
     end_tsc = _rdtsc ();
     
     calcul_flop_tsc ("mncblas_cswap nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {

     
     TOP_MICRO(start) ;
    mncblas_cswap (VECSIZE, vcomplexefloat1, 1, vcomplexefloat2, 1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_cswap micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mncblas_zswap (avec des complexe_double_t)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {    
     start_tsc = _rdtsc () ;
     mncblas_zswap (VECSIZE, vcomplexedouble1, 1, vcomplexedouble2, 1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_zswap nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
     TOP_MICRO(start) ;
        mncblas_zswap (VECSIZE, vcomplexedouble1, 1, vcomplexedouble2, 1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_zswap micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("==========================================================\n") ;

}