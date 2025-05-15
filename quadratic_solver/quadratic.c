#include "quadratic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int sign(long double x) { return (x > 0) - (x < 0); }

long double round_to_n_decimal_places(long double value, int n) {
  long double factor = pow(10, n);
  return round(value * factor) / factor;
}

long double *FindRootsQuadraticSolver(long double a, long double b,
                                      long double c, long double eps,
                                      int roundEps) {
  long double *roots = (long double *)malloc(2 * sizeof(long double));
  if (roots == NULL) {
    return NULL;
  }

  if (fabs(a) <= eps) {
    free(roots);
    return NULL;
  }

  long double D = b * b - 4 * a * c;

  if (D <= -eps) {
    free(roots);
    return NULL;
  }

  if (fabs(D) <= eps) {
    long double root = -b / (2 * a);
    roots[0] = round_to_n_decimal_places(root, roundEps);
    roots[1] = roots[0];
    return roots;
  }

  long double sqrt_D = sqrt(D);

  long double x1, x2;
  if (b >= 0) {
    x1 = (-b - sqrt_D) / (2 * a);
  } else {
    x1 = (-b + sqrt_D) / (2 * a);
  }

  x2 = c / (a * x1);

  roots[0] = round_to_n_decimal_places(x1, roundEps);
  roots[1] = round_to_n_decimal_places(x2, roundEps);

  if (roots[0] > roots[1]) {
    long double temp = roots[0];
    roots[0] = roots[1];
    roots[1] = temp;
  }

  return roots;
}