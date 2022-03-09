#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct {
  int nbMonome ;
  float *coeff;
  int *degre;
} polyf_creux_t, *p_polyf_creux_t;

p_polyf_creux_t creer_polynome (int degre) ;

void init_polynome (p_polyf_creux_t p, float x) ;

void detruire_polynome (p_polyf_creux_t p) ;

p_polyf_creux_t lire_polynome_float (char *nom_fichier) ;

void ecrire_polynome_float (p_polyf_creux_t p) ;

int egalite_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2) ;

p_polyf_creux_t addition_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2) ;

p_polyf_creux_t multiplication_polynome_scalaire (p_polyf_creux_t p, float alpha) ;

float puiss_float(float x, int deg ) ;

float eval_polynome (p_polyf_creux_t p, float x) ;


