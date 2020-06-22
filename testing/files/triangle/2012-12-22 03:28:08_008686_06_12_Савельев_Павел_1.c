#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM 3000
#define MIN 100

long TreugNum(int num);
int *resheto_E(int num);
int Razlozhenie(int num, int a, int b);

int main(){
  printf("%lld\n", TreugNum(NUM));
  return 0;
}
long TreugNum(int num){
        int sqrt_num = sqrt(num);
	long i, treug_num=0, kolvo_del=0, a, b;;
	
	if (num > sqrt_num*sqrt_num)
		sqrt_num++;
	sqrt_num++;
	for (i=1;kolvo_del<3000;i++){
		if (i%2==0){
			a = i/2;
			b = i+1;
		}
		else{
			a = i;
			b = (i+1)/2;
		}
		kolvo_del = Razlozhenie(num, a, b);
	}
	treug_num = a*b;
	return treug_num;
}
int *resheto_E(int num){ 
  int i, period, delitel;
  int *resheto = (int*)calloc(num+1, sizeof(int));

  for (i = 2; i <= num; i++)
    resheto[i] = 1;
  for (i = 2; i <= num; i++){
    if (resheto[i] != 0){
      delitel = i;
      for (period = 2; delitel*period <= num; period++)
        resheto[delitel*period] = 0;
    }
  }
  return resheto;
}
int Razlozhenie(int num, int a, int b){
	int i, deg, kolvo_del=1;
	int *resh = resheto_E(MIN);
	
	for (i = 2, deg=0; a!=1; i++){
		if (i>MIN)
		   return 0;
		while (resh[i]!=0 && a%i==0){
			a /= i;
			deg++;
		}
		kolvo_del*=deg+1;
		deg = 0;
	}
	for (i = 2, deg=0; b!=1; i++){
		if (i>MIN)
		   return 0;
		while (resh[i]!=0 && b%i==0){
			b /= i;
			deg++;
		}
		kolvo_del *= (deg+1);
		deg = 0;
	}
	return kolvo_del;
}