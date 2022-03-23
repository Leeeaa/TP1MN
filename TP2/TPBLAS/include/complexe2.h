
typedef struct {
  float real ;
  float imaginary ;
} complexe_float_t ;

typedef struct {
  double real ;
  double imaginary ;
} complexe_double_t ;

inline complexe_float_t add_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}

inline complexe_double_t add_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}


inline complexe_float_t mult_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
complexe_float_t r ;

  /* 
     a implementer
  */

  r.real = 0.0 ;
  r.imaginary = 0.0 ;

  r.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
  r.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
  
  return r ;
}

inline complexe_double_t mult_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
   complexe_double_t r ;

  /* 
     a implementer
  */
  
  r.real = 0.0 ;
  r.imaginary = 0.0 ;
  
  r.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
  r.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;

  return r ;

}


inline complexe_float_t div_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{

   //fait 

   complexe_float_t r ;

  /*if ((float)c2.real == 0 && (float)c2.imaginary == 0){
    return ;
  }*/ 


  r.real = 0.0 ;
  r.imaginary = 0.0 ;


  float denum = c2.real*c2.real + c2.imaginary*c2.imaginary;
  r.real = (c1.real*c2.real + c1.imaginary*c2.imaginary)/ denum;
  r.imaginary = (c1.imaginary*c2.real - c1.real*c2.imaginary)/denum;
  
  return r ;

}

inline complexe_double_t div_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
   complexe_double_t r ;

  /* 
     a implementer
  */

  r.real = 0.0 ;
  r.imaginary = 0.0 ;
  
  double denum = c2.real*c2.real + c2.imaginary*c2.imaginary;
  r.real = (c1.real*c2.real + c1.imaginary*c2.imaginary)/ denum;
  r.imaginary = (c1.imaginary*c2.real - c1.real*c2.imaginary)/denum;

  return r ;
}



