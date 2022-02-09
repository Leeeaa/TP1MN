#include <stdio.h>
#include <stdlib.h>

#include "poly.h"


int main (int argc, char **argv)
{
  /*p_polyf_t p1, p2 ;
  
  if (argc != 3)
    {
      fprintf (stderr, "deux paramètres (polynomes,fichiers) sont à passer \n") ;
      exit (-1) ;
    }
      
  p1 = lire_polynome_float (argv [1]) ;
  p2 = lire_polynome_float (argv [2]) ;

  ecrire_polynome_float (p1) ;
  ecrire_polynome_float (p2) ;*/

  /*test pour la fonction eval */
   p_polyf_t p;
   float val;
   p = creer_polynome (1);
   init_polynome(p, 1);
   val = eval_polynome(p, 1);
   if (val==2){
     printf("test eval passed\n");
   }
   else printf("test eval failed\n");
   

   /*test pour la fonction egalite_polynome*/
   p_polyf_t p1;
   p_polyf_t p2;
   p_polyf_t p3;
   p1 = creer_polynome (1);
   p2 = creer_polynome (1);
   p3 = creer_polynome (2);
   init_polynome(p1, 1);
   init_polynome(p2, 1);
   init_polynome(p3, 1);

   if(egalite_polynome(p1,p2)==1 && egalite_polynome(p1,p3)==0 && egalite_polynome(p2,p3)==0){
     printf("test egalite_polynome passed \n ");
     }
   else 
     printf("test egalite_polynome failed \n ");

   /*test pour multiplication_polynomes*/
    p_polyf_t q1;
    p_polyf_t q2;
    p_polyf_t res;
    q1 = creer_polynome (1);
    q2 = creer_polynome (1);
    res = creer_polynome (2);
    init_polynome(q1, 1);
    init_polynome(q2, 1);
    init_polynome(res, 1);
    res->coeff[1]=2;
    p_polyf_t ptest = multiplication_polynomes(q1, q2);
    printf( "%d", ptest->degre);
    printf( "%f",ptest->coeff[0]);
    printf( "%f",ptest->coeff[1]);
    printf( "%f",ptest->coeff[2]);
   /*
    if(res == multiplication_polynomes(q1, q2)){
       printf("test multiplication_polynome passed \n ");
    }
    else 
     printf("test multiplication_polynome failed \n ");
     */





   



   




}
