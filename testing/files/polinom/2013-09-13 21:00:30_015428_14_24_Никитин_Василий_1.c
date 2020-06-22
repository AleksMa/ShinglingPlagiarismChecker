#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int x,S=0,a;
    int n;
    scanf("%d \n %lli \n",&n, &x);
    long long int Sp=0;
    int i=n;
    for (i;i>=1;i--) {
        scanf("%lli",&a);
        S=(S+a)*x;
        if (i>1) {
          Sp=(Sp+a*i)*x;
        }
        else Sp=Sp+a;
    }
    scanf("%lli",&a);
    S=S+a;
    printf("%lli %lli",S,Sp);
    return 0;
}
