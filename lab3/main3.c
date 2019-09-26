#include <stdio.h>
#include <math.h>
#include "input_lib/input_lib.h"

int main() {
    double a = inputDouble("Enter a: ", 0, 0);
    double b = inputDouble("Enter b: ", 0, 0);
    double c = inputDouble("Enter c: ", 0, 0);
    double p = b - (pow(a, 2) / 3);
    double q = ((2 * pow(a, 3)) / 27) - ((a * b) / 3) + c;
    double d = (pow(p, 3) / 27) + (pow(q, 2) / 4);
    if (d > 0) {
        double u = cbrt(-(q / 2) + sqrt(d));
        double v = -(p / (3 * u));
        double y1 = u + v;
        double complexYRealPart = -((u + v) / 2);
        double complexYImagPart = (sqrt(3) * (u - v)) / 2;
        printf("y1 = %lf\ny2 = %lf + i * %lf\ny3 = %lf - i * %lf\n", y1, complexYRealPart, complexYImagPart, complexYRealPart, complexYImagPart);
        double x1 = y1 - a / 3;
        printf("x1 = %lf\n\n", x1);
        double check = pow(y1, 3) + (p * y1) + q;
        printf("Check:\n%lf ^ 3 + %lf * %lf + %lf = %lf\n", y1, p, y1, q, check);
    } else if (d == 0) {
        double y1 = 3 * q / p;
        double y2 = -((3 * q) / (2 * p));
        printf("y1 = %lf\ny2 = %lf\ny3 = %lf\n\n", y1, y2, y2);
        double x1 = y1 - a / 3;
        double x2 = y2 - a / 3;
        printf("x1 = %lf, x2 = %lf\n\n", x1, x2);
        double check1 = pow(y1, 3) + (p * y1) + q;
        double check2 = pow(y2, 3) + (p * y2) + q;
        printf("Check 1:\n%lf ^ 3 + %lf * %lf + %lf = %lf\n", y1, p, y1, q, check1);
        printf("Check 2:\n%lf ^ 3 + %lf * %lf + %lf = %lf\n", y2, p, y2, q, check2);
    } else {
        double r = sqrt(-pow(p, 3) / 27);
        double fi = acos(-q / (2 * r));
        double y1 = 2 * fabs(cbrt(r)) * cos(fi / 3);
        double y2 = 2 * fabs(cbrt(r)) * cos((fi + 2 * M_PI) / 3);
        double y3 = 2 * fabs(cbrt(r)) * cos((fi + 4 * M_PI) / 3);
        printf("y1 = %lf\ny2 = %lf\ny3 = %lf\n\n", y1, y2, y3);
        double x1 = y1 - a / 3;
        double x2 = y2 - a / 3;
        double x3 = y3 - a / 3;
        printf("x1 = %lf, x2 = %lf, x3 = %lf\n\n", x1, x2, x3);
        double check1 = pow(y1, 3) + (p * y1) + q;
        double check2 = pow(y2, 3) + (p * y2) + q;
        double check3 = pow(y3, 3) + (p * y3) + q;
        printf("Check 1:\n%lf ^ 3 + %lf * %lf + %lf = %lf\n", y1, p, y1, q, check1);
        printf("Check 2:\n%lf ^ 3 + %lf * %lf + %lf = %lf\n", y2, p, y2, q, check2);
        printf("Check 3:\n%lf ^ 3 + %lf * %lf + %lf = %lf\n", y3, p, y3, q, check3);
    }
    printf("Checks are possible only for real solutions");
    return 0;
}