#include <stdio.h>

int main()
{
        int n;
	long long x;
	scanf("%d%lld", &n, &x);
	long long a[n + 1];
	int even = 0;
	for (int i = n; i >= 0; i--)
	{
		scanf("%lld", &a[i]);
	}
	unsigned long long b = 0, t1, t2;
	// polinom
	if (n > 0)
	{
		if ((a[n] >= 0 && x >= 0) || (a[n] < 0 && x < 0))
		{
			t1 = a[n];
			t2 = x;
			b = t1 * t2;
			even = 1;
		}
		else
		{
			t1 = (a[n] >= 0) ? a[n] : -a[n];
			t2 = (x >= 0) ? x : -x;
			b = t1 * t2;
		}
		for (int i = n - 1; i > 0; i--)
		{
			if (even)
			{
				if (a[i] >= 0)
				{
					t1 = a[i];
					b += t1;
				}
				else
				{
					t1 = -a[i];
					if (t1 <= b)
					{
						b -= t1;
					}
					else
					{
						b = t1 - b;
						even = 0;
					}
				}
				if (x >= 0)
				{
					t1 = x;
				}
				else
				{
					t1 = -x;
					even = 1 - even;
				}
				b *= t1;
			}
			else
			{
				if (a[i] <= 0)
				{
					t1 = -a[i];
					b += t1;
				}
				else
				{
					t1 = a[i];
					if (t1 <= b)
					{
						b -= t1;
					}
					else
					{
						b = t1 - b;
						even = 1;
					}
				}
				if (x >= 0)
				{
					t1 = x;
				}
				else
				{
					t1 = -x;
					even = 1 - even;
				}
				b *= t1;
			}
		}
	}
	if (even)
	{
		if (a[0] >= 0)
		{
			t1 = a[0];
			b += t1;
		}
		else
		{
			t1 = -a[0];
			if (t1 <= b)
			{
				b -= t1;
			}
			else
			{
				b = t1 - b;
				even = 0;
			}
		}
	}
	else
	{
		if (a[0] <= 0)
		{
			t1 = -a[0];
			b += t1;
		}
		else
		{
			t1 = a[0];
			if (t1 <= b)
			{
				b -= t1;
			}
			else
			{
				b = t1 - b;
				even = 1;
			}
		}
	}
	if (!(even) && b)
	{
		printf("-");
	}
	printf("%llu ", b);
	// proizvodnaia
	even = 0, b = 0;
	if (n > 1)
	{
		if ((a[n] >= 0 && x >= 0) || (a[n] < 0 && x < 0))
		{
			t1 = a[n];
			t2 = x;
			b = t1 * t2;
			t1 = n;
			b *= t1;
			even = 1;
		}
		else
		{
			t1 = (a[n] >= 0) ? a[n] : -a[n];
			t2 = (x >= 0) ? x : -x;
			b = t1 * t2;
			t1 = n;
			b *= t1;
		}
		for (int i = n - 1; i > 1; i--)
		{
			if (even)
			{
				if (a[i] >= 0)
				{
					t1 = a[i];
					t1 *= i;
					b += t1;
				}
				else
				{
					t1 = -a[i];
					t1 *= i;
					if (t1 <= b)
					{
						b -= t1;
					}
					else
					{
						b = t1 - b;
						even = 0;
					}
				}
				if (x >= 0)
				{
					t1 = x;
				}
				else
				{
					t1 = -x;
					even = 1 - even;
				}
				b *= t1;
			}
			else
			{
				if (a[i] <= 0)
				{
					t1 = -a[i];
					t1 *= i;
					b += t1;
				}
				else
				{
					t1 = a[i];
					t1 *= i;
					if (t1 <= b)
					{
						b -= t1;
					}
					else
					{
						b = t1 - b;
						even = 1;
					}
				}
				if (x >= 0)
				{
					t1 = x;
				}
				else
				{
					t1 = -x;
					even = 1 - even;
				}
				b *= t1;
			}
		}
	}
	if (n)
	{
		if (even)
		{
			if (a[1] >= 0)
			{
				t1 = a[1];
				b += t1;
			}
			else
			{
				t1 = -a[1];
				if (t1 <= b)
				{
					b -= t1;
				}
				else
				{
					b = t1 - b;
					even = 0;
				}
			}
		}
		else
		{
			if (a[1] <= 0)
			{
				t1 = -a[1];
				b += t1;
			}
			else
			{
				t1 = a[1];
				if (t1 <= b)
				{
					b -= t1;
				}
				else
				{
					b = t1 - b;
					even = 1;
				}
			}
		}
	}
	else
	{
		b = 0;
	}
	if (!(even) && b)
	{
		printf("-");
	}
	printf("%llu ", b);
	return 0;
}