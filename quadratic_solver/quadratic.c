#include "quadratic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int sign(long double x) { return (x > 0) - (x < 0); }

long double *FindRootsQuadraticSolver(long double a, long double b,
                                      long double c, long double eps) {
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
    roots[0] = root;
    roots[1] = roots[0];
    return roots;
  }

  long double sqrt_D = sqrt(D);

  long double x1, x2;
  if (b >= eps) {
    x1 = (-b - sqrt_D) / (2 * a);
  } else {
    x1 = (-b + sqrt_D) / (2 * a);
  }
  x2 = c / (a * x1);

  roots[0] = x1;
  roots[1] = x2;

  if ((roots[0] - roots[1]) > eps) {
    long double temp = roots[0];
    roots[0] = roots[1];
    roots[1] = temp;
  }

  return roots;
}
