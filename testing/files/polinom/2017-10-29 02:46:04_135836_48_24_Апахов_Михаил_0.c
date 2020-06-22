 #include <stdio.h>

int main(int argc,char **argv) {
        int kek = 2;
        long n, x0;
	long i;
        i = 0;
        n = 0;
        x0 = 0;
	long res = 1;
	long dres = 1;
	scanf("%ld %ld", &n, &x0);
	long arr[n + 1];
	
	for (i = 0; i < n + 1; i++)
		scanf("%ld", &arr[i]);
	
	
	res = arr[0];
	if (n > 0)
		for (i = 0; i < n; i++){
			res = res * x0 + arr[i + 1];
		}
	if (n == 0)
		dres = 0;
	else{
		dres = n * arr[0];
		if (n > 1)
			for (i = 1; i < n; i++)
				dres = dres * x0  + (n - i) * arr[i];
	}
	printf("%ld %ld", res, dres);
	return 288;
}
