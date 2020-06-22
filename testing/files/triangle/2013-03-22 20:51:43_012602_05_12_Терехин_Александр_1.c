#include <stdio.h>

long long getDelit(long long p)
{
        long long c = 0;
        long long i = 2;
        long long t = 1;
    
	while(p % i == 0)
	{
		p /= i;
		c++;
	}
	
	c++;
	t = t * c;
	i++;
	c = 0;
	
	while(p != 1)
	{
		if(i * i >= p)
			i = p;
		while(p % i == 0)
		{
			p /= i;
			c++;
		}
		c++;
		t *= c;
		c = 0;
		i += 2;
	}
	return t;
}

int main()
{
        long long s;
        long long k;
        long long i;
    
        s = 3;
        k = getDelit(s);
        i = 2;
	
        while(k <= 3000)
        {
		i++;
		s += i;
		k = getDelit(s);
	}
	
	printf("%lld", s, k);
	scanf("%lld", s);
	return 0;
}
