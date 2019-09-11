#include <stdio.h>
#include <math.h>
#include "input_lib/input_lib.h"

int main() {
    double a = inputDouble("Enter a: ", 0);
    double b = inputDouble("Enter b: ", 0);
    double c = inputDouble("Enter c: ", 0);
    double p = b - (pow(a, 2) / 3);
    double q = ((2 * pow(a, 3)) / 27) - ((a * b) / 3) + c;
    double d = (pow(p, 3) / 27) + (pow(q, 2) / 4);
    if (d > 0) {
        double u = cbrt(-(q / 2) + sqrt(d));
        double v = -(p / (3 * u));
        double y1 = u + v;
        double complexYRealPart = -((u + v) / 2);
        double complexYImagPart = (sqrt(3) * (u - v)) / 2;
        printf("y1 = %lf, y2 = %lf + i * %lf, y3 = %lf - i * %lf", y1, complexYRealPart, complexYImagPart, complexYRealPart, complexYImagPart);
        return 0;
    } else if (d == 0) {
        double y1 = 3 * q / p;
        double y2 = -((3 * q) / (2 * p));
        printf("y1 = %lf, y2 = %lf, y3 = %lf", y1, y2, y2);
        return 0;
    } else {
        double r = sqrt(-pow(p, 3) / 27);
        double fi = acos(-q / (2 * r));
        double y1 = 2 * fabs(cbrt(r)) * cos(fi / 3);
        double y2 = 2 * fabs(cbrt(r)) * cos((fi + 2 * M_PI) / 3);
        double y3 = 2 * fabs(cbrt(r)) * cos((fi + 4 * M_PI) / 3);
        printf("y1 = %lf, y2 = %lf, y3 = %lf", y1, y2, y3);
        return 0;
    }
}