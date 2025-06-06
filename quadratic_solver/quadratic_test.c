#include "math.h"
#include "quadratic.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void quadratic_sover_test() {
  long double eps = 1e-9;
  long double *roots = FindRootsQuadraticSolver(0, 1, 1, eps, 11);
  assert(roots == NULL);
  free(roots);
}
void quadratic_sover_test2() {
  long double eps = 1e-9;
  long double test_arg1 = -1;
  long double test_arg2 = 1;
  long double *roots = FindRootsQuadraticSolver(1, 0, -1, eps, 11);
  assert((fabs(roots[0] - test_arg1) < eps) &&
         (fabs(roots[1] - test_arg2) < eps));
  free(roots);
}
void quadratic_sover_test3() {
  long double eps = 1e-9;
  long double test_arg1 = 0;
  long double test_arg2 = 0;
  long double *roots = FindRootsQuadraticSolver(1, 0, -0, eps, 11);
  assert((fabs(roots[0] - test_arg1) < eps) &&
         (fabs(roots[1] - test_arg2) < eps));
  free(roots);
}
void quadratic_sover_test4() {
  long double eps = 1e-9;
  long double *roots = FindRootsQuadraticSolver(1, 0, 1, eps, 11);
  assert(roots == NULL); // null функция возвращает когда нет корней
  free(roots);
}

void quadratic_sover_test5() {
  long double eps = 1e-7;
  long double test_arg1 = -3e-4;
  long double test_arg2 = 3e-4;
  long double *roots = FindRootsQuadraticSolver(1, 0, -1e-7, eps, 4);
  assert((fabs(roots[0] - test_arg1) < eps) &&
         (fabs(roots[1] - test_arg2) < eps));
  free(roots);
}
void quadratic_sover_test6() {
  long double eps = 1e-9;
  long double test_arg1 = -1e-10;
  long double test_arg2 = 1e+10;
  long double *roots = FindRootsQuadraticSolver(1, -1e+10, -1, eps, 11);
  assert((fabs(roots[0] - test_arg1) < eps) &&
         (fabs(roots[1] - test_arg2) < eps));
  free(roots);
}
void quadratic_sover_test7() {
  long double eps = 1e-7;
  long double test_arg1 = 0;
  long double test_arg2 = 0;
  long double *roots = FindRootsQuadraticSolver(1, 0, -1e-8, eps, 7);
  assert((fabs(roots[0] - test_arg1) < eps) &&
         (fabs(roots[1] - test_arg2) < eps));
  free(roots);
}
int main() {
  quadratic_sover_test();
  quadratic_sover_test2();
  quadratic_sover_test3();
  quadratic_sover_test4();
  quadratic_sover_test5();
  quadratic_sover_test6();
  quadratic_sover_test7();

  return 0;
}
