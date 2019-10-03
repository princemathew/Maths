// condition : a>b, a!=0, b!=0

#include <stdio.h> 
#include <gmp.h>

void gcd(mpz_t a, mpz_t b,mpz_t g){
 mpz_t c;
 mpz_init(c);
 mpz_mod(c,a,b);
 if(mpz_cmp_ui(c,0)==0)
  mpz_set(g,b);
 else
  gcd(b,c,g); 
} 
