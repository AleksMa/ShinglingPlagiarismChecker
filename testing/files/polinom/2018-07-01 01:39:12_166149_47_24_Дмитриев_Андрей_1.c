#include <stdio.h>

int main() //int argc, char *argv[]
{
    long int degree, point, i; 
    scanf("%ld %ld\n", &degree, &point);//Считываем со стандартного потока ввода степень полинома и заданную точку
    long int coefficients_polynomial[degree+1];
    for (i = 0; i < degree + 1; i++) scanf("%ld", &coefficients_polynomial[i]);//Заполняем массив коэффициентов полинома

//Вычисление значения полинома и значения производной полинома в заданной точке
    long int result_polynomial = coefficients_polynomial[0], result_derivative = 0;
    for (i = 1; i < degree + 1; i++) {
            result_polynomial = point * result_polynomial + coefficients_polynomial[i];
            result_derivative = point * result_derivative + coefficients_polynomial[i-1] * (degree - i + 1);
    }
    printf("%ld %ld\n", result_polynomial, result_derivative);
    
    return 0;
}