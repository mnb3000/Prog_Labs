#include <math.h>
#include <stdio.h>
#include "input_lib/input_lib.h"

double equation1(double t, double x) {
    return (cos(t / x) - 2 * sin(1 / x) + (1 / x));
}

double equation2(double t, double x) {
    return (sin(log(x)) - cos(log(x)) + t * log(x));
}

/**
 * Calculates solution via half-split method
 * @param a First starting boundary
 * @param b Second starting boundary
 * @param equation Pointer to equation function
 * @param t T parameter for the equation
 * @param eps Maximum error gap
 * @return Computed value of X with deviation less than eps
 */
double half(double a, double b, double (*equation)(double, double), double t, double eps) {
    double x;
    do {
        x = (a + b) / 2;
        if (equation(a, t) * equation(x, t) > 0) {
            a = x;
        } else {
            b = x;
        }
    } while (fabs(b - a) > fabs(eps));
    return x;
}

int main() {
    /*
     * Equation and method function pointer array init
     */
    double (*equations[2])(double t, double x) = {equation1, equation2};
    double (*methods[1])(double a, double b, double (*equation)(double, double), double t, double eps) = {half};

    /*
     * Equation and method picker
     */
    int chosenEquation = inputIntMinMax("Choose the equation:\n[1] cos(t/x) - 2*sin(1/x + 1/x)\n[2] sin(log(x)) - cos(log(x)) + t*log(x)\n", 1, 2);
    int chosenMethod = inputIntMinMax("Choose solve method:\n[1] Half Division\n[2] Newton's\n", 1, 2);

    /*
     * Method and equation pointer init
     */
    double (*equation)(double t, double x) = equations[chosenEquation];
    double (*method)(double a, double b, double (*equation)(double, double), double t, double eps) = methods[chosenMethod];

    /*
     * Data input
     */
    char *a1String = "Enter a1: ";
    char *a2String = "Enter a2: ";
    double a1, a2;
    if (chosenEquation == 2) {
        printf("In equation 2 a1 and a2 should be positive\n");
        a1 = inputDouble(a1String, 1, 1);
        a2 = inputDouble(a2String, 1, 1);
    } else {
        a1 = inputDouble(a1String, 0, 0);
        a2 = inputDouble(a2String, 0, 0);
    }
    double t = inputDouble("Enter t: ", 0, 0);
    double eps = inputDouble("Enter eps (between 0 and 1): ", 1, 1);

    /*
     * Calculation and output
     */
    double x = method(a1, a2, equation, t, eps);
    printf("X = %lf", x);
}