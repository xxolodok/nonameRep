#include "definite_integral.h"
#include <stdio.h>
#include <float.h>

double trapezoidalRule(Func integrand, double lower_limit, double upper_limit, int num_trapezoids) {
    double dx = fabs(upper_limit - lower_limit) / num_trapezoids;
    double eps = 1E-7;
    double integral_approximation = 0.0;
    double num_intervals;
    int i;

    if (dx <= eps || upper_limit < lower_limit || !isfinite(lower_limit + upper_limit + dx)) {
        fprintf(stderr, "Error: Invalid input data.\n");
        return NAN;
    }

    if (fabs(upper_limit - lower_limit) < eps) {
        return 0.0;
    }

    integral_approximation = (integrand(lower_limit) + integrand(upper_limit)) / 2.0;
    num_intervals = fabs(upper_limit - lower_limit) / dx;

    for (i = 1; i < num_intervals; i++) {
        integral_approximation += integrand(lower_limit + i * dx);
    }

    integral_approximation = integral_approximation * dx;
    return integral_approximation;
}
