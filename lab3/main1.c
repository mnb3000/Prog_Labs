#include <stdio.h>
#include <math.h>
#include "input_lib/input_lib.h"

double root(double x, double k, double eps) {
    double y = 1;
    double delta = 1;
    while (fabs(delta) > eps) {
        delta = (1 / k) * ((x / pow(y, (k - 1))) - y);
        y += delta;
    }
    return y;
}

int main() {
    double x;
    double k;
    double eps;
    int doXNegativeCheck = 0;
    k = inputDouble("Input k: ", 0, 1);
    if (fmod(k, 2) == 0) {
        doXNegativeCheck = 1;
    }
    x = inputDouble("Input x: ", doXNegativeCheck, 1);
    do {
        eps = inputDouble("Input epsilon (between 1e-10 and 1): ", 1, 1);
    } while (eps < 1e-10);
    printf("Y = %le", root(x, k, eps));
    return 0;
}