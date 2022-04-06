#include <stdio.h>
#include <stdlib.h>
#include "mnblas.h"
#include "complexe2.h"


#define    NB_FOIS        512

#include "flop.h"

int main (int argc, char **argv)
{
 complexe_double_t cd1 ;
 complexe_double_t cd2 ;
 unsigned long long int start, end  ;
 init_flop_tsc () ;



 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;
 start = _rdtsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
     cd1 = add_complexe_double (cd1, cd2) ;
   }
 end = _rdtsc () ;
 printf ("apres boucle cd1.real %f cd1.imaginary %f %Ld cycles \n", cd1.real, cd1.imaginary, end-start) ;
 calcul_flop_tsc("calcul complexe nano ", NB_FOIS*2, end-start) ;


 //-----------------------------------------------
 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;
start = _rdtsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
    cd1 = mult_complexe_double(cd1, cd2);
   }
end = _rdtsc () ;
 printf ("apres boucle cd1.real %f cd1.imaginary %f %Ld cycles \n", cd1.real, cd1.imaginary, end-start) ;
 calcul_flop_tsc("calcul complexe nano ", NB_FOIS*2, end-start) ;
 //-----------------------------------------------

 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;
start = _rdtsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
     cd1 = div_complexe_double(cd1,cd2);
   }
end = _rdtsc () ;
 printf ("apres boucle cd1.real %f cd1.imaginary %f %Ld cycles \n", cd1.real, cd1.imaginary, end-start) ;
 calcul_flop_tsc("calcul complexe nano ", NB_FOIS*2, end-start) ;
 //-----------------------------------------------

 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;
 start = _rdtsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      cd1 = mult_complexe_double(cd1,cd2);
   }
end = _rdtsc () ;
 printf ("apres boucle cd1.real %f cd1.imaginary %f %Ld cycles \n", cd1.real, cd1.imaginary, end-start) ;
 calcul_flop_tsc("calcul complexe nano ", NB_FOIS*2, end-start) ;

 //-----------------------------------------------
 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;
 start = _rdtsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      cd1 = div_complexe_double(cd1,cd2);
   }
end = _rdtsc () ;
 printf ("apres boucle cd1.real %f cd1.imaginary %f %Ld cycles \n", cd1.real, cd1.imaginary, end-start) ;
 calcul_flop_tsc("calcul complexe nano ", NB_FOIS*2, end-start) ;



 //-----------------------------------------------
 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;
 start = _rdtsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
     cd1 = add_complexe_double (cd1, cd2) ;
   }
end = _rdtsc () ;
 printf ("apres boucle cd1.real %f cd1.imaginary %f %Ld cycles \n", cd1.real, cd1.imaginary, end-start) ;
 calcul_flop_tsc("calcul complexe nano ", NB_FOIS*2, end-start) ;
 
 exit(0);
}


