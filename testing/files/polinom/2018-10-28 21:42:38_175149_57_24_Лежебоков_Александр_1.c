#include <stdio.h>

int main()
{
    int n,x;
    scanf("%d", &n);
    int arr[n];
    scanf("%d", &x);
    for (int i = 0; i <= n; i++)
    {
        scanf("%i", &arr[i]);
    }
    long int c;
    long int b = arr[0];
    for (int i = 1; i <= n; i++)
    {
        c=b;
        b = c*x+arr[i];
    }
    int q = n;
    long int d = q*arr[0];
    q--;
    for (int i = 1; i < n; i++)
    {
        c=d;
        d = d*x + q*arr[i];
        q--;
    }
    printf("%ld %ld" ,b,d);
    
        return 0;
}
