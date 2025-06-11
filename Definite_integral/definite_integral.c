#include "definite_integral.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

double integrandFunc(double x) { return x * x; }

double calculateTrapezoidalRule(Func integrand, double lower_limit,
                                double upper_limit, int num_trapezoids,
                                double eps) {
  double dx = fabs(upper_limit - lower_limit) / num_trapezoids;
  double integral_approximation = 0.0;
  double num_intervals;
  int i;

  if (dx <= eps || upper_limit < lower_limit ||
      !isfinite(lower_limit + upper_limit + dx)) {
    return NAN;
  }

  if (fabs(upper_limit - lower_limit) < eps) {
    return 0.0;
  }

  integral_approximation =
      (integrand(lower_limit) + integrand(upper_limit)) / 2.0;
  num_intervals = fabs(upper_limit - lower_limit) / dx;

  for (i = 1; i < num_intervals; i++) {
    integral_approximation += integrand(lower_limit + i * dx);
  }

  integral_approximation *= dx;
  return integral_approximation;
}

int main() {
  double eps_value = 1E-7;
  double result =
      calculateTrapezoidalRule(integrandFunc, 0.0, 1.0, 100, eps_value);

  printf("Result: %f\n", result);
  return 0;
}
