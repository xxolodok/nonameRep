#include "definite_integral.h"
#include <stdio.h>
#include <float.h>
#include <math.h> 

double trapezoidalRule(Func integrand, double lower_limit, double upper_limit, int num_trapezoids) {
    double dx;
    double integral_approximation = 0.0;
    int num_intervals;
    int i;
    double eps = 1E-7;

    if (!isfinite(lower_limit) || !isfinite(upper_limit)) {
        fprintf(stderr, "Error: Limits of integration must be finite.\n");
        return NAN;
    }

    if (upper_limit < lower_limit) {
        fprintf(stderr, "Error: Upper limit must be greater than or equal to lower limit.\n");
        return NAN;
    }

    dx = fabs(upper_limit - lower_limit) / num_trapezoids;

    if (num_trapezoids <= 0) {
        fprintf(stderr, "Error: Number of trapezoids must be positive.\n");
        return NAN;
    }
    
    if (fabs(upper_limit - lower_limit) < eps) {
        return 0.0;
    }

    num_intervals = (int)round(fabs(upper_limit - lower_limit) / dx);

    if (num_intervals <= 0) {
      fprintf(stderr, "Error: Number of trapezoids is too large, resulting in zero intervals.\n");
      return NAN;
    }


    integral_approximation = (integrand(lower_limit) + integrand(upper_limit)) / 2.0;

    for (i = 1; i < num_trapezoids; i++) {
        integral_approximation += integrand(lower_limit + i * dx);
    }

    integral_approximation = integral_approximation * dx;
    return integral_approximation;
}
