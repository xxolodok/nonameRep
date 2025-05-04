#ifndef DEFINITE_INTEGRAL_H
#define DEFINITE_INTEGRAL_H

#include <math.h>
#include <stdbool.h>

typedef double (*Func)(double);

double trapezoidalRule(Func integrand, double lower_limit, double upper_limit, int num_trapezoids);

#endif