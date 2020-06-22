#include <stdio.h>

int main(int argc, int **argv) {

        int x, n, i;
        scanf ("%d", &n);
        int arr[n];
        scanf ("%d", &x);
        for (i = 0;i < n + 1; i++) {
                scanf ("%d", &arr[i]);
        }

        long int y = arr[0]*x;
        for (i = 1; i < n; i++){
                y = (y + arr[i]) * x;
        }
        y += arr[n];


        long int y1 = arr[0];
        if ( (n-1) >= 1 ) {
                y1 = arr[0] * (n) * x ;
                for (i = 1; i < n-1; i++) {
                        y1 = (y1 + (arr[i] * (n-i)) ) * x;
                }
                y1 += arr[n-1];
        }       

        printf ("%ld %ld", y, y1);
        return 0;
}