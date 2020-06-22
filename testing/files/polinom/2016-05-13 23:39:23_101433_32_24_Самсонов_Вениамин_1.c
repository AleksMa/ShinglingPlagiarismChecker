#include <stdio.h>

int main(int argc, const char * argv[]) {
    long int n = 0, x0 = 0, i = 0, polynom = 0, derivative = 0, a = 0;
    scanf("%ld\n", &n);
    scanf("%ld\n", &x0);
    for (i = 0; i < n; i++) {
        scanf("%ld", &a);
        polynom += a;
        polynom *= x0;
        derivative += a * (n - i);
        if (i != n - 1) {
            derivative *= x0;
        }
    }
    scanf("%ld", &a);
    polynom += a;
    printf("%ld\n", polynom);
    printf("%ld\n", derivative);
    return 0;
}
