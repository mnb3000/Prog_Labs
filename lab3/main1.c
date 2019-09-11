#include <stdio.h>
#include <string.h>
#include <math.h>

double inputDouble(char message[], int doNegativeCheck) {
    double out;
    char str[256];
    printf("%s", message);
    scanf("%lf", &out);
    fgets(str, sizeof(str), stdin);
    if (strlen(str) > 1) {
        printf("Invalid input! Try again!\n");
        return inputDouble(message, doNegativeCheck);
    }
    if (doNegativeCheck > 0 && out < 0) {
        printf("Input is negative! Try again!\n");
        return inputDouble(message, doNegativeCheck);
    }
    return out;
}

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
    k = inputDouble("Input k: ", 0);
    if (fmod(k, 2) == 0) {
        doXNegativeCheck = 1;
    }
    x = inputDouble("Input x: ", doXNegativeCheck);
    eps = inputDouble("Input epsilon: ", 1);
    printf("Y = %le", root(x, k, eps));
    return 0;
}