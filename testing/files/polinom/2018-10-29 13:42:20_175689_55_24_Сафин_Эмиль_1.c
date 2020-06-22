#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>

// переобозначил название типа (для простоты работы с ним)
#define llint long long int

int main()
{
    int n;

    // ввод данных
    scanf("%i", &n);
    
    llint x;
    scanf("%lld", &x);
    
    // выделяем память, завершаем программу, если неудалось
    llint* ks = (llint*) malloc(sizeof(llint) * (n + 1));
    if (ks == NULL) {
        exit(EXIT_FAILURE);
    }
    
    int i;
    for (i = n; i >= 0; --i) {
        scanf("%lld", &ks[i]);
    }
    
    llint Pnx0 = 0, P_nx0 = 0;
    
    // вычисляем значение
    for (i = n; i >= 0; --i)
        Pnx0 = ks[i] + (x * Pnx0);
    
    // вычисляем значение от производной
    for (i = n; i >= 1; --i)
        P_nx0 = ks[i] * i + (x * P_nx0);
    
    printf("%lld %lld", Pnx0, P_nx0);
    
    // очистка выделенной памяти
    free(ks);
    
    return 0;
}

