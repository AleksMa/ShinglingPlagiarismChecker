#include <stdio.h>

int main(int argc, char *argv[])
{
        long long n, x,a, g=0,y=0;
	int i;
	scanf("%lld %lld", &n, &x);
	for(i=n;i>0;i--)
	{
		scanf("%lld", &a);
		g = (g + a)* x;
		if(i>1)
			y = (y+a*i)*x;
		else
			y+=a;
	}
	scanf("%lld", &a);
	g+=a;
	printf("%lld %lld", g, y);
    return 0;
}