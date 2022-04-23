#include "dot.c"
#include <stdio.h>

int main()
{
	/*dot : The dot functions compute the dot product dot of two distributed REAL vectors
	 res = I1*J1+I2*J2+...+In*Jn
	*/

    // ------------ test fonction sdot --------------- 

    float Xf[10] = {0,1,2,3,4,5,6,7,8,9};
    //float Xfbis[20] = {0,1,2,3,4,5,6,7,8,9,20,21,22,23,24,25,26,27,28,29};
    float Yf[10] = {10,11,12,13,14,15,16,17,18,19};

        
    printf("resultat test sdot : %f \n", mncblas_sdot(10,Xf,1,Yf,1));
    //printf ("resultat: %f \n", mncblas_sdot(10,Xfbis,2,Yf,1));
	

	// ------------ test fonction ddot --------------- 	

	double Xd[10] = {0,1,2,3,4,5,6,7,8,9};
    double Yd[10] = {10,11,12,13,14,15,16,17,18,19};

    printf("resultat test ddot : %f \n", mncblas_ddot(10,Xd,1,Yd,1));


    /*dotu : The dot functions compute the dot product dot of two distributed COMPLEX vectors
	 res = I1*J1+I2*J2+...+In*Jn
	*/



	return 0;

}