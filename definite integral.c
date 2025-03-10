#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Функция для численного интегрирования методом трапеций
double integrate(double (*f)(double), double a, double b, int n, double epsilon) {


    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }

    sum *= h;
    return sum;
}

// Функция-парабола для интегрирования (ax^2 + bx + c)
double parabola(double x) {
    double a = 1.0;
    double b = -2.0;
    double c = 1.0;
    return a * x * x + b * x + c; // (x-1)^2
}

int main(int argc, char *argv[]) {
    double a, b, epsilon;
    int n;

     if (argc == 5) {
        a = atof(argv[1]);
        b = atof(argv[2]);
        n = atoi(argv[3]);
         epsilon = atof(argv[4]); // Получаем значение эпсилон из командной строки
    } else {
        a = 0.0;
        b = 2.0;
        n = 100;
         epsilon = 1e-6; // Значение эпсилон по умолчанию (маленькое число)
         printf("Использование: %s <нижний_предел> <верхний_предел> <количество_подотрезков> <эпсилон>\n", argv[0]);
         printf("Будут использованы значения по умолчанию: a=%.2f, b=%.2f, n=%d, epsilon=%.1e\n", a, b, n, epsilon);
     }

     double result = integrate(parabola, a, b, n, epsilon);
     printf("Приблизительный интеграл от параболы (x-1)^2 от %.2f до %.2f равен: %.6f\n", a, b, result);

     return 0;
}