#include<stdio.h>
#include "factor.c"
#include "gcd.c"
#include <gmp.h>
#include <time.h>

int main()
{
 clock_t start, end;
 double cpu_time_used;
 
 int c=0;
 mpz_t n,p[1024],g,a,b;
 mpz_init(g);
 mpz_init(a); 
 mpz_init(b);
 mpz_init(n);
 mpz_set_ui(n,0);
 char sa[1024],sb[1024],inputStr[1024];
 printf ("Enter your numbers: ");
 scanf("%1023s" , inputStr);
 //scanf("%1023s" ,sa);
 //scanf("%1023s" ,sb);
 //mpz_set_str(a,sa, 10);
 //mpz_set_str(b,sb, 10);
 mpz_set_str(n,inputStr, 10);
 start = clock();
 c=primeFactors(n,p); 
 end = clock();
 for (int i=0;i<c;i++)
  gmp_printf ("%Zd ",p[i]);
 //start = clock();
 //gcd(a,b,g);
 //end = clock();
 //gmp_printf ("%Zd ",g);
 cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
 printf("fun() took %f seconds to execute \n", cpu_time_used);
 printf ("\n"); 
 return 0;
}
 

