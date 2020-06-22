#include <stdio.h>
long int  n, a, x, p = 0, p1 = 0;

int main( int argc, char **argv )
{ 
    scanf ( "%ld",  &n);
    scanf ( "%ld",  &x);
  
    while (n > 0) { // цикл для вычисления одновременно значения полинома и его производной
   
      scanf ( "%ld", &a );
      p = ( p + a )*x; 
      if (n > 1) p1 = (p1 + a*n)*x; 
      else p1 = p1 + a;
      n--;
    }
    
    scanf ( "%ld", &a );
    p = p + a; 
  
    printf("%ld %ld \n", p, p1);
    return 0;
}