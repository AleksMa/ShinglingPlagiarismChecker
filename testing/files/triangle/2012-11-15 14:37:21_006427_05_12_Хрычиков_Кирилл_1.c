#include <stdio.h>




int maxPower(int n, int divider)
{
        int j;
	j=0;
	while (n%divider==0)
	{
		j++;
		n=n/divider;
	}
	return j;
}


int main()
{
	const int maxPrimeCount=1000;
	unsigned long long currentTriangleNum; //òåêóùåå òðåóãîëüíîå ÷èñëî
	unsigned long i, j, currentDivCount; //ñ÷åò÷èêè è ÷èñëî äåëèòåëåé òåêóùåãî òðåóãîëüíîãî 
	unsigned int mp[maxPrimeCount], primes[maxPrimeCount], primesCount; //ìàññèâ äëÿ ðåøåòà Ýðàòîñôåíà, ìàññèâ ïðîñòûõ ÷èñåë äî 10000 è èõ êîëè÷åñòâî
	unsigned long factor1, factor2; //÷àñòè òðåóãîëüíîãî ÷èñëà äëÿ ïîäñ÷åòà êîëè÷åñòâà äåëèòåëåé
	for (i=0; i<maxPrimeCount; i++) mp[i]=i; //ðåøåòî ýðàòîñôåíà
	int factor1count, factor2count; 
	mp[1]=0;
	for (i=2; i<maxPrimeCount; i++)
		if (mp[i]!=0 ) 
		{
				j=2;
				while (i*j<maxPrimeCount) 
					{
						mp[i*j]=0;
						j++;
					}
		} //êîíåö ðåøåòà Ýðàòîñôåíà
    for (i=0; i<maxPrimeCount; i++) primes[i]=0;
	primesCount=0; //çàïîëíÿåì ìàññèâ ïðîñòûõ ÷èñåë
	for (i=0; i<maxPrimeCount; i++) if (mp[i]!=0) 
	{
		primesCount++;
		primes[primesCount-1]=i;
	}
    //òåïåðü åñòü ìàññèâ ïðîñòûõ ÷èñåë  
    
		
	for (i=1; ; i++)
	{
		currentTriangleNum=i*(i+1)/2;
		if ((i%2)==0)
		{
			factor1=(i/2);
			factor2=i+1;
		} else
		{
			factor1=i;
			factor2=(i+1)/2;
		}
		factor1count=1;
		factor2count=1;
		for (j=0; (j<primesCount)&&(primes[j]<=factor1); j++)
		{
			factor1count*=(1+maxPower(factor1,primes[j]));
		}
		for (j=0; (j<primesCount)&&(primes[j]<=factor2); j++)
		{
			factor2count*=(1+maxPower(factor2,primes[j]));
		}
		currentDivCount=factor1count*factor2count;
		
		if (currentDivCount>3000) 
			{
				printf("%ld\n", currentTriangleNum);
				break;
		}
			
	}
	return 0;
}
