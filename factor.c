#include <stdio.h>
#include <gmp.h>

int primeFactors(mpz_t n,mpz_t p[]) { 
 int c=0;  
 while (mpz_divisible_ui_p(n,2)){ 
  mpz_init(p[c]); 
  mpz_set_ui(p[c++],2);
  mpz_cdiv_q_ui(n,n,2);
 } 
    
 mpz_t i,sq;
 mpz_init(i);
 mpz_init(sq);
 mpz_set_ui(i,3);
 mpz_sqrt(sq,n);
    
 while(mpz_cmp(i,sq)<=0){  
  while (mpz_divisible_p(n,i)){ 
   mpz_init(p[c]);
   mpz_set(p[c++],i);
   mpz_cdiv_q(n,n,i);
  } 
  mpz_add_ui(i,i,2);
 } 
  
   
 if (mpz_cmp_ui(n,2)>0){
  mpz_init(p[c]);
  mpz_set(p[c++],n);
 }

 return c;
} 
  
 
