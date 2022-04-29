#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>
#include <math.h>

void mncblas_sgemv(const MNCBLAS_LAYOUT layout,
                 const MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const float alpha, const float *A, const int lda,
                 const float *X, const int incX, const float beta,
                 float *Y, const int incY)
{
    float sum;
    if(layout == MNCblasRowMajor) {             //cas row major 1
        if(TransA == MNCblasNoTrans) {              //cas 1.1
            for(register int i = 0, j; i < M ; i+= incY) {
                sum = 0;
                for(j = 0; j < N ; j+= incX) {
                    sum += *(A+i*N+j)*X[j];
                }
                Y[i] = alpha*sum + beta*Y[i];
            }
        } else if (TransA == MNCblasTrans || TransA == MNCblasConjTrans) {        //cas 1.2
            for(register int i = 0; i < N ; i+= incY) {
                sum = 0;
                for(register int j = 0; j < M ; j+= incX) {
                    sum += *(A+j*N+i)*X[j];
                }
                Y[i] = alpha*sum + beta*Y[i];
            }
        }
    } else if (layout == MNCblasColMajor){      //cas col major 2
        if(TransA == MNCblasNoTrans) {
            for(register int i = 0, j; i < M ; i+= incY) {
                sum = 0;
                for(j = 0; j < N ; j+= incX) {
                    sum += *(A+j*M+i)*X[j];
                }
                Y[i] = alpha*sum + beta*Y[i];
            }
        } else if (TransA == MNCblasTrans || TransA == MNCblasConjTrans) {
            for(register int i = 0, j; i < N ; i+= incY) {
                sum = 0;
                for(j = 0; j < M ; j+= incX) {
                    sum += *(A+i*M+j)*X[j];
                }
                Y[i] = alpha*sum + beta*Y[i];
            }
        }
    }
}

void mncblas_dgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const double alpha, const double *A, const int lda,
                 const double *X, const int incX, const double beta,
                 double *Y, const int incY)
{
    double sum;
    if(layout == MNCblasRowMajor) {
        if(TransA == MNCblasNoTrans) {
            for(register int i = 0, j; i < M ; i+= incY) {
                sum = 0;
                for(j = 0; j < N ; j+= incX) {
                    sum += *(A+i*N+j)*X[j];
                }
                Y[i] = alpha*sum + beta*Y[i];
            }
        } else if (TransA == MNCblasTrans || TransA == MNCblasConjTrans) {
            for(register int i = 0; i < N ; i+= incY) {
                sum = 0;
                for(register int j = 0; j < M ; j+= incX) {
                    sum += *(A+j*N+i)*X[j];
                }
                Y[i] = alpha*sum + beta*Y[i];
            }
        }
    } else if (layout == MNCblasColMajor){
        if(TransA == MNCblasNoTrans) {
            for(register int i = 0, j; i < M ; i+= incY) {
                sum = 0;
                for(j = 0; j < N ; j+= incX) {
                    sum += *(A+j*M+i)*X[j];
                }
                Y[i] = alpha*sum + beta*Y[i];
            }
        } else if (TransA == MNCblasTrans || TransA == MNCblasConjTrans) {
            for(register int i = 0, j; i < N ; i+= incY) {
                sum = 0;
                for(j = 0; j < M ; j+= incX) {
                    sum += *(A+i*M+j)*X[j];
                }
                Y[i] = alpha*sum + beta*Y[i];
            }
        }
    }
    
}

void mncblas_cgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY)
{
    complexe_float_t sum;
    if(layout == MNCblasRowMajor) {             //cas row major 1
        if(TransA == MNCblasNoTrans) {              //cas 1.1
            for(register int i = 0, j; i < M ; i+= incY) {
                sum = (complexe_float_t) {0.0,0.0};
                for(j = 0; j < N ; j+= incX) {
                    complexe_float_t temp = mult_complexe_float (((complexe_float_t*)A)[i*N+j],((complexe_float_t*)X)[j]);
                    sum = add_complexe_float(sum, temp);
                }
                *(complexe_float_t*)alpha = mult_complexe_float(*(complexe_float_t*)alpha, sum);
                *(complexe_float_t*)beta = mult_complexe_float(*(complexe_float_t*)beta,((complexe_float_t*)Y)[i]);
                ((complexe_float_t*)Y)[i] = add_complexe_float(*(complexe_float_t*)(alpha),*(complexe_float_t*)beta);
            }
        } else if (TransA == MNCblasTrans) {        //cas 1.2
            for(register int i = 0; i < N ; i+= incY) {
                sum = (complexe_float_t) {0,0};
                for(register int j = 0; j < M ; j+= incX) {
                    complexe_float_t temp = mult_complexe_float (((complexe_float_t*)A)[j*N+i],((complexe_float_t*)X)[j]);
                    sum = add_complexe_float(sum, temp);
                }
                *(complexe_float_t*)alpha = mult_complexe_float(*(complexe_float_t*)alpha, sum);
                *(complexe_float_t*)beta = mult_complexe_float(*(complexe_float_t*)beta,((complexe_float_t*)Y)[i]);
                ((complexe_float_t*)Y)[i] = add_complexe_float(*(complexe_float_t*)(alpha),*(complexe_float_t*)beta);
            }
        }
        else if (TransA == MNCblasConjTrans){
            for(register int i = 0, j; i < N ; i+= incY) {
                sum = (complexe_float_t) {0,0};
                for(j = 0; j < M ; j+= incX) {
                    complexe_float_t conjA = conj_complexe_float (((const complexe_float_t *)A)[j*N+i]);
                    //complexe_float_t conjA = (complexe_float_t){(((complexe_float_t*)A)[j*N+i]).real,(((complexe_float_t*)A)[j*N+i]).imaginary};
                    complexe_float_t temp = mult_complexe_float (conjA,((complexe_float_t*)X)[j]);
                    sum = add_complexe_float(sum, temp);
                }
                *(complexe_float_t*)alpha = mult_complexe_float(*(complexe_float_t*)alpha, sum);
                *(complexe_float_t*)beta = mult_complexe_float(*(complexe_float_t*)beta,((complexe_float_t*)Y)[i]);
                ((complexe_float_t*)Y)[i] = add_complexe_float(*(complexe_float_t*)(alpha),*(complexe_float_t*)beta);
            }
        }
    } else if (layout == MNCblasColMajor){      //cas col major 2
        if(TransA == MNCblasNoTrans) {
            for(register int i = 0, j; i < M ; i+= incY) {
                sum = (complexe_float_t) {0,0};
                for(j = 0; j < N ; j+= incX) {
                    complexe_float_t temp = mult_complexe_float (((complexe_float_t*)A)[j*M+i],(((complexe_float_t*)X)[j]));
                    sum = add_complexe_float(sum, temp);
                }
                *(complexe_float_t*)alpha = mult_complexe_float(*(complexe_float_t*)alpha, sum);
                *(complexe_float_t*)beta = mult_complexe_float(*(complexe_float_t*)beta,((complexe_float_t*)Y)[i]);
                ((complexe_float_t*)Y)[i] = add_complexe_float(*(complexe_float_t*)(alpha),*(complexe_float_t*)beta);
            }
        } else if (TransA == MNCblasTrans) {
            for(register int i = 0, j; i < N ; i+= incY) {
                sum = (complexe_float_t) {0,0};
                for(j = 0; j < M ; j+= incX) {
                    complexe_float_t temp = mult_complexe_float (((complexe_float_t*)A)[i*M+j],((complexe_float_t*)X)[j]);
                    sum = add_complexe_float(sum, temp);
                }
                *(complexe_float_t*)alpha = mult_complexe_float(*(complexe_float_t*)alpha, sum);
                *(complexe_float_t*)beta = mult_complexe_float(*(complexe_float_t*)beta,((complexe_float_t*)Y)[i]);
                ((complexe_float_t*)Y)[i] = add_complexe_float(*(complexe_float_t*)(alpha),*(complexe_float_t*)beta);
            }
        }
        else if (TransA == MNCblasConjTrans){
            for(register int i = 0, j; i < N ; i+= incY) {
                sum = (complexe_float_t) {0,0};
                for(j = 0; j < M ; j+= incX) {
                    complexe_float_t conjA = conj_complexe_float (((const complexe_float_t *)A)[i*M+j]);
                    //complexe_float_t conjA = (complexe_float_t){(((complexe_float_t*)A)[i*M+j]).real,(((complexe_float_t*)A)[i*M+j]).imaginary};
                    complexe_float_t temp = mult_complexe_float (conjA,((complexe_float_t*)X)[j]);
                    sum = add_complexe_float(sum, temp);
                }
                *(complexe_float_t*)alpha = mult_complexe_float(*(complexe_float_t*)alpha, sum);
                *(complexe_float_t*)beta = mult_complexe_float(*(complexe_float_t*)beta,((complexe_float_t*)Y)[i]);
                ((complexe_float_t*)Y)[i] = add_complexe_float(*(complexe_float_t*)(alpha),*(complexe_float_t*)beta);
            }
        }
    }
}

void mncblas_zgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY)
{
    complexe_double_t sum;
    if(layout == MNCblasRowMajor) {             //cas row major 1
        if(TransA == MNCblasNoTrans) {              //cas 1.1
            for(register int i = 0, j; i < M ; i+= incY) {
                sum = (complexe_double_t) {0.0,0.0};
                for(j = 0; j < N ; j+= incX) {
                    complexe_double_t temp = mult_complexe_double(((complexe_double_t*)A)[i*N+j],((complexe_double_t*)X)[j]);
                    sum = add_complexe_double(sum, temp);
                }
                *(complexe_double_t*)alpha = mult_complexe_double(*(complexe_double_t*)alpha, sum);
                *(complexe_double_t*)beta = mult_complexe_double(*(complexe_double_t*)beta,((complexe_double_t*)Y)[i]);
                ((complexe_double_t*)Y)[i] = add_complexe_double(*(complexe_double_t*)(alpha),*(complexe_double_t*)beta);
            }
        } else if (TransA == MNCblasTrans) {        //cas 1.2
            for(register int i = 0; i < N ; i+= incY) {
                sum = (complexe_double_t) {0,0};
                for(register int j = 0; j < M ; j+= incX) {
                    complexe_double_t temp = mult_complexe_double (((complexe_double_t*)A)[j*N+i],((complexe_double_t*)X)[j]);
                    sum = add_complexe_double(sum, temp);
                }
                *(complexe_double_t*)alpha = mult_complexe_double(*(complexe_double_t*)alpha, sum);
                *(complexe_double_t*)beta = mult_complexe_double(*(complexe_double_t*)beta,((complexe_double_t*)Y)[i]);
                ((complexe_double_t*)Y)[i] = add_complexe_double(*(complexe_double_t*)(alpha),*(complexe_double_t*)beta);
            }
        }
        else if (TransA == MNCblasConjTrans){
            for(register int i = 0, j; i < N ; i+= incY) {
                sum = (complexe_double_t) {0,0};
                for(j = 0; j < M ; j+= incX) {
                    complexe_double_t conjA = conj_complexe_double (((const complexe_double_t *)A)[j*N+i]);
                    //complexe_double_t conjA = (complexe_double_t){(((complexe_double_t*)A)[j*N+i]).real, (((complexe_double_t*)A)[j*N+i]).imaginary};
                    complexe_double_t temp = mult_complexe_double (conjA,((complexe_double_t*)X)[j]);
                    sum = add_complexe_double(sum, temp);
                }
                *(complexe_double_t*)alpha = mult_complexe_double(*(complexe_double_t*)alpha, sum);
                *(complexe_double_t*)beta = mult_complexe_double(*(complexe_double_t*)beta,((complexe_double_t*)Y)[i]);
                ((complexe_double_t*)Y)[i] = add_complexe_double(*(complexe_double_t*)(alpha),*(complexe_double_t*)beta);
            }
        }
    } else if (layout == MNCblasColMajor){      //cas col major 2
        if(TransA == MNCblasNoTrans) {
            for(register int i = 0, j; i < M ; i+= incY) {
                sum = (complexe_double_t) {0,0};
                for(j = 0; j < N ; j+= incX) {
                    complexe_double_t temp = mult_complexe_double (((complexe_double_t*)A)[j*M+i],((complexe_double_t*)X)[j]);
                    sum = add_complexe_double(sum, temp);
                }
                  *(complexe_double_t*)alpha = mult_complexe_double(*(complexe_double_t*)alpha, sum);
                *(complexe_double_t*)beta = mult_complexe_double(*(complexe_double_t*)beta,((complexe_double_t*)Y)[i]);
                ((complexe_double_t*)Y)[i] = add_complexe_double(*(complexe_double_t*)(alpha),*(complexe_double_t*)beta);
            }
        } else if (TransA == MNCblasTrans) {
            for(register int i = 0, j; i < N ; i+= incY) {
                sum = (complexe_double_t) {0,0};
                for(j = 0; j < M ; j+= incX) {
                    complexe_double_t temp = mult_complexe_double (((complexe_double_t*)A)[i*M+j],((complexe_double_t*)X)[j]);
                    sum = add_complexe_double(sum, temp);
                }
                *(complexe_double_t*)alpha = mult_complexe_double(*(complexe_double_t*)alpha, sum);
                *(complexe_double_t*)beta = mult_complexe_double(*(complexe_double_t*)beta,((complexe_double_t*)Y)[i]);
                ((complexe_double_t*)Y)[i] = add_complexe_double(*(complexe_double_t*)(alpha),*(complexe_double_t*)beta);
            }
        }
        else if (TransA == MNCblasConjTrans){
            for(register int i = 0, j; i < N ; i+= incY) {
                sum = (complexe_double_t) {0,0};
                for(j = 0; j < M ; j+= incX) {
                    complexe_double_t conjA = conj_complexe_double (((const complexe_double_t *)A)[i*M+j]);
                    //complexe_double_t conjA = (complexe_double_t){(((complexe_double_t*)A)[i*M+j]).real, (((complexe_double_t*)A)[i*M+j]).imaginary};
                    complexe_double_t temp = mult_complexe_double (conjA,((complexe_double_t*)X)[j]);
                    sum = add_complexe_double(sum, temp);
                }
                *(complexe_double_t*)alpha = mult_complexe_double(*(complexe_double_t*)alpha, sum);
                *(complexe_double_t*)beta = mult_complexe_double(*(complexe_double_t*)beta,((complexe_double_t*)Y)[i]);
                ((complexe_double_t*)Y)[i] = add_complexe_double(*(complexe_double_t*)(alpha),*(complexe_double_t*)beta);
            }
        }
    }
}


