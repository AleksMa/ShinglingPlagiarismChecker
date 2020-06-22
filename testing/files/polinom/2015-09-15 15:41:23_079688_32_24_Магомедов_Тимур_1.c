#include <stdio.h>

int main() {
    long degree, x;
    scanf("%ld%ld", &degree, &x);
    long array[degree + 1];
    for (int i = 0; i <= degree; i++) {
        scanf("%ld", array + i);
    }
    long ans[] = { 0, 0 };
    for (int i = 0; i <= degree; i++) {
        ans[0] = ans[0] * x + array[i];
        if (i < degree) {
            ans[1] = ans[1] * x + array[i] * (degree - i);
        }
    }
    printf("%ld %ld\n", ans[0], ans[1]);
    return 0;
}