#include "quadratic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Функция для округления до n знаков после запятой

long double *FindRootsQuadraticSolver(long double a, long double b,
                                      long double c, long double eps,
                                      int roundEps) {
  // Выделяем память для хранения корней
  long double *roots = (long double *)malloc(2 * sizeof(long double));
  if (roots == NULL) {
    printf("Ошибка выделения памяти\n");
    return NULL;
  } 

  // Проверка, что коэффициент a не равен нулю
  if (fabs(a) < eps) {
    printf("Коэффициент a не может быть равным нулю\n");
    free(roots);
    return NULL;
  }

  // Вычисление дискриминанта
  long double D = b * b - 4 * a * c;

  if (D < -eps) {
    // Нет вещественных корней
    free(roots);
    return NULL;
  } else if (D > eps) {
    // Два корня
    long double sqrt_D = sqrt(D);
    long double root1 = (-b + sqrt_D) / (2 * a);
    long double root2 = (-b - sqrt_D) / (2 * a);

    // Округляем корни
    roots[0] = round_to_n_decimal_places(root1, roundEps);
    roots[1] = round_to_n_decimal_places(root2, roundEps);

    // Убедимся, что корни отсортированы по возрастанию
    if (roots[0] > roots[1]) {
      long double temp = roots[0];
      roots[0] = roots[1];
      roots[1] = temp;
    }
  } else {
    // Один корень (D близок к нулю)
    roots[0] = round_to_n_decimal_places(-b / (2 * a), roundEps);
    roots[1] = roots[0];
  }
  if (roots[0] > roots[1]) {
    long double temp = roots[0];
    roots[0] = roots[1];
    roots[1] = temp;
  }
  return roots;
}
long double round_to_n_decimal_places(long double value, int n) {
  long double factor = pow(10, n); // 10^n
  return round(value * factor) / factor;
}