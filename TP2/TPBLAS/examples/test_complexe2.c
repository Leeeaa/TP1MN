#include <stdio.h>
#include <stdlib.h>
#include "mnblas.h"
#include "complexe2.h"


#define    NB_FOIS        512

#include "flop.h"

int main (int argc, char **argv)
{
 struct timespec start, end ;
 int i ;
 init_flop_nano () ;

 complexe_float_t c1 = {1.0, 2.0} ;
 complexe_float_t c2 = {3.0, 6.0} ;
 complexe_float_t c3; 
 


 //-----------------------------------------------

TOP_NANO(start) ;
 for (i = 0 ; i < NB_FOIS; i++)
   {
    c3 = mult_complexe_float(c1,c2);
   }
 TOP_NANO(end) ;
 printf ("Test1 : duree %f \n", tdiff_nano (&start, &end)) ;
   

 if( c3.real== -9.0 && c3.imaginary==12.0){
   printf("true\n");
 }
 else printf("false\n");
 
 //-----------------------------------------------

 complexe_float_t c4;
 TOP_NANO(start) ;
 for (i = 0 ; i < NB_FOIS; i++)
   {
    c4 = div_complexe_float(c1,c2);
   }
 TOP_NANO(end) ;
 printf ("Test2 : duree %f \n", tdiff_nano (&start, &end)) ;


 if( c4.real== (float)1/3 && c4.imaginary==0.0 ){
   printf("true\n");
 }

 else printf("false\n");

 //-----------------------------------------------

 complexe_double_t cd1 ={1.00, 2.00};
 complexe_double_t cd2 ={1.00, 2.00};
 complexe_double_t cd3;
 TOP_NANO(start) ;
 for (i = 0 ; i < NB_FOIS; i++)
   {
     cd3 = mult_complexe_double(cd1,cd2);
   }
 TOP_NANO(end) ;

 printf ("Test3 : duree %f \n", tdiff_nano (&start, &end)) ;

 if( cd3.real== (double)-3.00 && cd3.imaginary==(double)4.00){
   printf("true\n");
 }
 else printf("false\n");



 //-----------------------------------------------

 complexe_double_t cd4;
 TOP_NANO(start);
 for (i = 0 ; i < NB_FOIS; i++)
   {
     cd4 = div_complexe_double(cd1,cd2);
   }

 TOP_NANO(end) ;

 printf ("Test4 : duree %f \n", tdiff_nano (&start, &end)) ;


 if( cd4.real== 1.00 && cd4.imaginary==0.00 ){
   printf("true\n");
 }
 else printf("false\n");
 //printf("reelle : %f, im : %f\n",cd4.real,c4.imaginary );


 //-----------------------------------------------



 
 c1 = add_complexe_float (c1, c2) ;

 printf ("c1.r %f c&.i %f\n", c1.real, c1.imaginary) ;

 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;


 TOP_NANO(start) ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     cd1 = add_complexe_double (cd1, cd2) ;
   }

 TOP_NANO(end) ;

 printf ("apres boucle cd1.real %f cd1.imaginary %f duree %f \n", cd1.real, cd1.imaginary, tdiff_nano (&start, &end)) ;

 calcul_flop_nano ("calcul complexe ", NB_FOIS*2, tdiff_nano(&start, &end)) ;
 exit (0) ;
}


