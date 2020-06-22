int main() 
{ 
    long a, n, x0, b, c; 
    scanf("%ld", &n); 
    scanf("%ld", &x0); 
    scanf("%ld", &a); 
    b = a * x0; 
    if (n != 1) c = a * n * x0; 
    else c = a; 
    for (long i = (n - 1); i > 0; i--) 
    { 
       scanf("%ld ", &a); 
       b = (b + a) * x0; 
       if (i != 1) c = (c + a * i) * x0; 
       else c = c + a; 
    } 
    scanf("%ld ", &a); 
    b = b + a; 
    printf("%ld %ld", b, c); 
    return 0; 
}