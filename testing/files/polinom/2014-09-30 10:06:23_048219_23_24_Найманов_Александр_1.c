
#include <stdio.h>

int main() {
  
  int i, N, L; 
  
  scanf("%d", &N);
  
  long a[N + 1], P, Pp, x;
  
  scanf("%ld", &x);
  
  for(i = 0; i <= N; i = i + 1) 
    scanf("%ld", &a[i]);
  
  P = a[0];
  Pp = a[0]*N;
  
  for(i = 0; i <= N - 1; i = i + 1)
    P = P * x + a[i+1];
  
  L = N-1;
  
  for(i = 0; i <= N - 2; i = i + 1) { 
    Pp = Pp * x + a[i+1]*L;
    L = L-1;
  }
  printf("\n %ld\n %ld\n", P, Pp);
  
  return 0;
}
