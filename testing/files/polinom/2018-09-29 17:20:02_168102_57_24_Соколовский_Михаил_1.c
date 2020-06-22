#include <stdio.h>

int main(int argc, char **argv) {
    long n, x0;
    scanf("%li %li ", &n, &x0);
    long res1 = 0;
    long res2 = 0;
    long cur;
    for (int i = n; i > 0; --i) {
        scanf("%li", &cur);
        res1 = (res1 + cur) * x0;
        if (i == 1) {
            res2 += cur;
            break;
        }
        res2 = (res2 + cur * i) * x0;
    }
    scanf("%li", &cur);
    printf("%li %li", res1 + cur, res2);  
    return 0;
}
