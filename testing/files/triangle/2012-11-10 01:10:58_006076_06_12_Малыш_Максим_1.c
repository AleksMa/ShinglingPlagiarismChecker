//100мс на моём ноутбуке с 1.6GHz!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <time.h>

#define true 1
#define false 0
 
#define max_n 3000
#define Leg_const 1 // http://en.wikipedia.org/wiki/Legendre's_constant



int prime_num = 0; // в дальнейшем используется как размер массива простых чисел 

int Factorisation(int number, int *Prime_list)
{
        int div_num = 1;
	int i;
	int pwr;
	int remainder = number;

	for (i = 0; i < prime_num; i++)
	{
		// Если есть остаток, то это тоже простой делитель
		// Степень этого делителя равна 1
		if (Prime_list[i] * Prime_list[i] > number)
			return div_num * 2;

		pwr = 1;
		while (remainder % Prime_list[i] == 0)
		{
			pwr++;
			remainder = remainder / Prime_list[i];
		}
		div_num *= pwr;
		// Если остатка нет, то возвращаем кол-во делителей.
		if (remainder == 1)
			return div_num;
	}
	return div_num;
}

int *Euclid(int top_limit)
{
	int i, j;
	int bound = (top_limit - 1) / 2;
	int sqrt_up = (sqrt(top_limit) - 1) / 2;
	int *Prime_list;
	char *Prime_bool;
	
	Prime_bool = (char *)malloc((bound + 1) * sizeof(char)); // Решето Евклида
	memset(Prime_bool, true, (bound + 1) * sizeof(char));	 // Заполняем его единцами
	Prime_list = (int *)malloc((top_limit / (log(top_limit) - Leg_const)) * sizeof(int));
	// Строчкой выше - массив, в котором будут все простые делители
	
        // Тут находим простые числа
	for (i = 1; i <= sqrt_up; i++)
		if (Prime_bool[i] == true)
			for (j = 2 * i * (i + 1); j <= bound; j += 2 * i + 1)
				Prime_bool[j] = false;
	
        // Тут их вносим в новый массив
	Prime_list[0] = 2;
	j = 0;
	for (i = 1; i <= bound; i++)
		if (Prime_bool[i] == true)
		{
			j++;
			Prime_list[j] = (2 * i + 1);
		}
	prime_num = j;
	free(Prime_bool);
	return Prime_list;
}

void main()
{
//	clock_t start = clock();
	unsigned long long number = 1;
	unsigned long long i = 2;
	int Euc_sqr;
	int current_n = 0;
	int F_i0 = 2;						 
	int F_i1 = 2;						
	int *Prime_list;
	
	Euc_sqr = sqrt(max_n)*0.7;
	Prime_list = Euclid(Euc_sqr);
	while (current_n < max_n)
	{
		if (i % 2 == 1)
		{
			F_i1 = Factorisation((i + 1) / 2, Prime_list);
			current_n = F_i0 * F_i1;
		}
		else
		{
			F_i0 = Factorisation(i + 1, Prime_list);
			current_n = F_i0 * F_i1;
		}
		i++;
	}
	number = i * (i - 1) / 2;
	printf("%lld", number);
	free(Prime_list);
//	printf ( "\n%f\n", ( (double)clock() - start ) / CLOCKS_PER_SEC );
}