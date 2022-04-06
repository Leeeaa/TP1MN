#include "swap.c"

int main()
{

    float X[10] = {0,1,2,3,4,5,6,7,8,9};
    float Y[10];

    mncblas_sswap(10,X,1,Y,1);
    for (int i = 0; i < 10; i++)
    {
        printf("Valeur %d : %d", i, Y[i]);
    }
    
    return 0;
}