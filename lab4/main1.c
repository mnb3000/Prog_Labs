#include <stdio.h>
#include <math.h>
#include "input_lib/input_lib.h"

/**
 * Converts deg to rad
 * @param deg Angle in deg
 * @return Angle in rad
 */
double degToRad(double deg) {
    return deg * M_PI / 180;
}

/**
 * Calculates sin of x via Taylor series
 * @param x Radian angle
 * @param eps Error gap
 * @return Approximated sin
 */
double taylorSin(double x, double eps) {
    double delta = 1;
    double out = 1;
    int n = 1;
    while (fabs(delta) > eps) {
        delta *= -pow(x, 2) / ((n + 1) * (n + 2));
        out += delta;
        n += 2;
    }
    return out;
}

/**
 * Calculates cos of x via Taylor series
 * @param x Radian angle
 * @param eps Error gap
 * @return Approximated cos
 */
double taylorCos(double x, double eps) {
    double delta = 1;
    double out = 1;
    int n = 1;
    while (fabs(delta) > eps) {
        delta *= -pow(x, 2) / (2 * n * ((2 * n) - 1));
        out += delta;
        n += 1;
    }
    return out;
}

/**
 * Prints line separator with fixed length
 * @param columns Number of columns
 */
void printTableSeparator(int columns) {
    for (int i = 0; i < columns; ++i) {
        putchar('+');
        for (int j = 0; j < 10; ++j) {
            putchar('-');
        }
    }
    printf("%s", "+\n");
}

/**
 * Prints table header
 * @param headers Array of header names
 * @param columns Number of columns
 */
void printTableHeader(char **headers, int columns) {
    printTableSeparator(columns);
    for (int i = 0; i < columns; ++i) {
        printf("|%10s", headers[i]);
    }
    printf("%s", "|\n");
    printTableSeparator(columns);
}

/**
 * Prints table line with unfixed length
 * @param values Array of values to print
 */
void printTableLine(double *values) {
    for (int i = 0; i < sizeof(values) - 1; ++i) {
        printf("|%10lf", values[i]);
    }
    printf("%s", "|\n");
}

int main() {
    char *headers[] = {"Argument", "Taylor sin", "Sin", "Sin diff", "Taylor cos", "Cos", "Cos diff"};
    printf("Input all values IN DEGREES!\n");
    double x1 = inputDouble("Enter x1: ", 0, 0);
    double x2 = inputDouble("Enter x2: ", 0, 0);
    double dx = inputDouble("Enter dx: ", 0, 0);
    double eps = inputDouble("Enter epsilon: ", 0, 0);
    printTableHeader(headers, 7);
    double x = x1;
    while (x < x2) {
        double radX = degToRad(x);
        double values[7];
        double tSin = taylorSin(radX, eps);
        double rSin = sin(radX);
        double tCos = taylorCos(radX, eps);
        double rCos = cos(radX);
        values[0] = x; // Argument
        values[1] = tSin; // Taylor sin
        values[2] = rSin; // Math.h sin
        values[3] = rSin - tSin; // Sin difference
        values[4] = tCos; // Taylor cos
        values[5] = rCos; // Math.h cos
        values[6] = rCos - tCos; // Cos difference
        printTableLine(values);
        x += dx;
    }
}