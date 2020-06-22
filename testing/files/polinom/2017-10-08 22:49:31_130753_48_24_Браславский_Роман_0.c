#include <stdio.h>
int main (int argc, char **argv)
{
long degree;
long x;
int i;

scanf("%ld", &degree);
scanf("%ld", &x);

long a[degree];
for (i = 0; i < degree+1; i++){
    scanf("%ld", &a[i]);
}

long poly = a[0];
long der = 0;

for (i = 1; i <= degree; i++){
    poly = x*poly + a[i];
    der = x*der + a[i-1] * (degree - i + 1);
}

printf ("%ld %ld", poly, der);
}
