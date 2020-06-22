#include <stdio.h>

int main() {
    int grade;  /* grade - степень полинома n */
    int x;
    scanf("%d%d", &grade, &x);
    int i;
    int k[grade + 1]; /* k - множество коэфициентов полинома n */
    for (i = 0; i < grade + 1; i++) {
        scanf("%d", &k[i]);
    }
    long poly = k[0]; /* определяем полином n и находим его значение */
    for (i = 0; i < grade; i++) {
            poly = poly * x + k[i+1];
    }
    int gradefall = grade; /* определяем вспомогательную переменную равную степени полинома для
                             более удобного нахождения производной */
    long derpoly = k[0] * gradefall;
    for (i = 0; i < grade - 1; i++) {
        gradefall -= 1; /*понижаем степень с каждой инициализацией цикла */
        derpoly = (derpoly * x) + (k[i+1] * gradefall);
    }
    printf("%ld %ld", poly, derpoly);
    return 0;
}