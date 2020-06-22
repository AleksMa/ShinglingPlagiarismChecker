#include<stdio.h>
#include <math.h>

int main() 
{
long N;
scanf ("%ld", &N);

long x;
scanf ("%ld", &x);

long result = 0;
long diff = 0;
long k;
for (int i=0; i<N; i++)
{
scanf ("%ld", &k);
result = (result + k)*x;

if (i<N-1)
diff = (diff + k*(N-i))*x;
else
diff +=k*(N-i);
}
scanf ("%ld", &k);
result+=k;


printf("%ld\n", result);
printf("%ld", diff);
}