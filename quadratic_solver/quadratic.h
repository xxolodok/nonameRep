#ifndef QUADRATIC_H
#define QUADRATIC_H

long double *FindRootsQuadraticSolver(long double a, long double b,
                                      long double c, long double eps,
                                      int roundEps);
long double round_to_n_decimal_places(long double value, int n);

#endif

