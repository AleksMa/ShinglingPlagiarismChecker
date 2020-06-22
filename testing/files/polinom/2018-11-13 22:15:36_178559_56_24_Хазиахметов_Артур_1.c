#include <stdlib.h>
#include <stdio.h>
 
char* str(int64_t x) {
    int n = 0;
    int64_t z;
    z = x;
    while (z != 0) {
        n++;
        z /= 10;
    }
    if (n == 0) n++;
    z = x;
    n += (z < 0 ? 1 : 0);
    char* c = (char*)malloc(n + 1);
    c[n] = 0;
    if (z != 0) {
        while (z != 0) {
            n--;
            c[n] = abs(z % 10) + 0x30;
            z /= 10;
        }
        if (x < 0) {
            c[0] = '-';
        }
    }
    else c[0] = '0';
    return c;
}
 
void calc_poly()
{
    int n;
    int x0;
    scanf("%d", &n);
    scanf("%d", &x0);
    int* a;
    a = (int*)malloc((n + 1) * sizeof(int));
    int64_t r = 0;
    int64_t s = 0;
    for (int i = n; i >= 0; i--) {
        scanf("%d", &(a[i]));
        r *= x0;
        r += a[i];
        if (i>0) {
            s *= x0;
            s += i * a[i];
        }
    }
    free(a);
    char* rr = str(r);
    char* rs = str(s);
    printf("%s %s", rr,rs);
    free(rr);
    free(rs);
 
}
int main()
{
    calc_poly();
        return 0;
}
