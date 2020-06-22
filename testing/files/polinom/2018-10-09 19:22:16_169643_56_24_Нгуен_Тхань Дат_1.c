#include <stdio.h>

int n,x0;
long long res1,res2;

int main() {
        	scanf("%d%d",&n,&x0); n++;
		int a[n+1];
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		long long x = 1;
		for (int i=n;i>=1;i--) {
			res1 = res1 + a[i]*x;
			x*=x0;
		}
		x=1;
		for (int i=n-1;i>=1;i--) res2 = res2 + a[i]*(n-i)*x,x*=x0;
		printf("%lld %lld",res1,res2);
}
