#include <stdio.h>
main (int argc, char **argv)
{
  long int  P = 0, a, n, f,L=0, i, k, R;
  scanf ("%ld%ld",  &n , &f); 
  i = 0;
  k = n ;
  while (  n > i ) 
  {
    scanf ( "%ld", &a) ;
    P =   P * f + a ; 
    L = L * f + a*k ;
    i++ ;
    k--;
  } 
  scanf ("%ld" , &R ) ;
  P = P*f + R ;
  printf ( "%ld %ld\n", P, L) ;
  return 0 ;
}  