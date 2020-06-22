#include <stdio.h>

int main(int argc, char* argv[])
{
        int i , n;
	long x, a, p = 0, p2 = 0;
//	printf("\nVvedite dva chisla ");
	scanf("%d %ld", &n, &x);
//	printf("\nVvedite %d chisel ", (n+1));
	for(i = 0; i < n + 1; i++)
	{
//		printf("\nVvedite chislo nomer %d ", (i+1));
		scanf("%ld", &a);
		if(i == (n))
		{
			p = p + a;
		}
		else
		{
			p = (p + a) * x;
		}
		if (i == (n-1))
		{
			p2 = p2 + a;
		}
		else 
		{
			if(i < (n - 1))
			{
				p2 = (p2 + a * (n -i)) * x;
			}
		}
	}

	printf("%ld %ld", p, p2);
//	printf("%d ", p2);
//	printf("\nPress any key ...");
//	getch();
	return 0;
}