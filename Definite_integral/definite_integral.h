#ifndef DEFINITE_INTEGRAL_H
#define DEFINITE_INTEGRAL_H

#include <math.h>
#include <stdio.h>

typedef double (*Func)(double);

double calculateTrapezoidalRule(Func integrand, double lower_limit, double upper_limit, 
                                int num_trapezoids, double eps);

#endif
