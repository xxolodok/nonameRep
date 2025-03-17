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
    double lower_limit1 = 0.0;
    double upper_limit1 = 5.0;
    int num_trapezoids1 = 1000; 
    double expected_result1 = 25.0; 
    double tolerance1 = 0.001;

    double actual_result1 = trapezoidalRule(constant_function, lower_limit1, upper_limit1, num_trapezoids1);
    printf("Test 1: Expected = %lf, Actual = %lf, Difference = %lf\n", expected_result1, actual_result1, fabs(actual_result1 - expected_result1));
    assert(fabs(actual_result1 - expected_result1) < tolerance1);
    printf("Test 1 passed (Constant function)!\n");

    double lower_limit2 = 0.0;
    double upper_limit2 = 3.0;
    int num_trapezoids2 = 1000;  
    double expected_result2 = 36.0; 
    double tolerance2 = 0.01;    

    double actual_result2 = trapezoidalRule(example_function, lower_limit2, upper_limit2, num_trapezoids2);
    printf("Test 2: Expected = %lf, Actual = %lf, Difference = %lf\n", expected_result2, actual_result2, fabs(actual_result2 - expected_result2));
    assert(fabs(actual_result2 - expected_result2) < tolerance2);
    printf("Test 2 passed (Quadratic function)!\n");
}

int main() {
    test_trapezoidalRule();
    return 0;
}
