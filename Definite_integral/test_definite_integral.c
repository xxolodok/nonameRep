#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "definite_integral.h"

double example_function(double x) {
    return -x * x + 9;
}

double constant_function(double x) {
    return 5.0;
}


void test_trapezoidalRule() {

    double lower_limit2 = 0.0;
    double upper_limit2 = 5.0;
    int num_trapezoids2 = 1000;
    double expected_result2 = 25.0;
    double tolerance2 = 0.001;

    double actual_result2 = trapezoidalRule(constant_function, lower_limit2, upper_limit2, num_trapezoids2);

    assert(fabs(actual_result2 - expected_result2) < tolerance2);
    printf("Test passed (Constant function)!\n");

}

int main() {
    test_trapezoidalRule();
    return 0;
}
