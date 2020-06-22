int main()
{
    long n, x0, k;
    long long pol, pol_dif;
    scanf("%ld %ld %ld", &n, &x0, &k);
    pol = k * x0;
    if (n > 1) pol_dif = k*n*x0;
    else pol_dif = k;
    int i;
    for (i = n-1; i >= 0; i--) {
        scanf("%ld", &k);
        if (i != 0) pol = (pol + k) * x0;
        else pol += k;
        if (i > 1) pol_dif = (pol_dif + k*i) * x0;
        else if (i == 1) pol_dif += k;
    }
    printf("\n%lld %lld", pol, pol_dif);
    return 0;
}