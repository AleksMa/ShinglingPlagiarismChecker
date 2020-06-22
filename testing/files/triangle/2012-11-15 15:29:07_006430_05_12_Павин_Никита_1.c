#include<stdio.h>

#define N 100

unsigned long prm[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,
        79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,
	181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,
	283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,
	409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,
	523,541};

unsigned long koldel(unsigned long a)
{
	unsigned long k = 0, i, cnt1 = 1, cnt2 = 1;
	if (a == 1 || a == 2)
		return a;
	while (a & 1 == 0) {
		k++;
		a >>= 1;
	}
	if (a == 1)
		return k + 1;
	else
		cnt1 = k + 1;
	for (i = 0; i < N && prm[i] * prm[i] <= a; i++) {
		k = 1;
		while(a % prm[i] == 0) {
			k++;
			a /= prm[i];
		}
		cnt1 *= k;
	}
	if (a == 1)
		return cnt1;
	if (i < N)
		return cnt1 << 1;
	for (i = prm[N - 1] + 2; i * i <= a; i += 2) {
		k = 0;
		while(a % i == 0) {
			k++;
			a /= i;
		}
		cnt2 *= (k + 1);
	}
	if (a > 1)
	cnt2 <<= 1;
return cnt1 * cnt2;
}

int main()
{
	int n, K2, K1 = 1;
	unsigned long X, i;
	for (i = 2; ; i += 2) {
		K2 = koldel(i / 2);
		if (K1 * K2 > 3000) {
			X = (i - 1) * i / 2;
			printf("%lu\n", X);
			return 0;
		}
		K1 = koldel(i + 1);
		if (K1 * K2 > 3000) {
			X = (i + 1) * i / 2;
			printf("%lu\n", X);
			return 0;
		}
	}
}