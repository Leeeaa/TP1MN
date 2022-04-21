#include "copy.c"
#include <stdio.h>

int main()
{
    // ------------ test fonction scopy --------------- 
    //float Xf[10] = {0,1,2,3,4,5,6,7,8,9};
    float Xfbis[20] = {0,1,2,3,4,5,6,7,8,9,20,21,22,23,24,25,26,27,28,29};
    float Yf[10] = {10,11,12,13,14,15,16,17,18,19};


    //mncblas_scopy(10,Xf,1,Yf,1);
    for (int i = 0; i < 10; i++)
    {
        //printf("Valeur %d : %lf \n", i, Xf[i]);
        //printf("Valeur %d : %lf \n", i, Yf[i]);
    }

    mncblas_scopy(10,Xfbis,2,Yf,1);
    for (int i = 0; i < 10; i++)
    {
        printf("Valeur %d : %lf \n", i, Xfbis[i*2]);
        printf("Valeur %d : %lf \n", i, Yf[i]);
    }

    /* affiche  Valeur 0 : 0.000000 
                Valeur 0 : 0.000000 
                Valeur 1 : 2.000000 
                Valeur 1 : 2.000000 
                Valeur 2 : 4.000000 
                Valeur 2 : 4.000000 
                Valeur 3 : 6.000000 
                Valeur 3 : 6.000000 
                Valeur 4 : 8.000000 
                Valeur 4 : 8.000000 
                Valeur 5 : 20.000000 
                Valeur 5 : 15.000000 
                Valeur 6 : 22.000000 
                Valeur 6 : 16.000000 
                Valeur 7 : 24.000000 
                Valeur 7 : 17.000000 
                Valeur 8 : 26.000000 
                Valeur 8 : 18.000000 
                Valeur 9 : 28.000000 
                Valeur 9 : 19.000000 
    -> problème ?
    */



   
    return 0;

}