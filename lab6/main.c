#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input_lib/input_lib.h"

int main() {
    int n = inputIntMin("Input n (more or equal than 2): ", 0, 0, 2);

    /*
     * Memory allocation
     */
    double **a = (double **) calloc(n, sizeof(double *)); // Coef matrix
    for (int i = 0; i < n; ++i) {
        a[i] = (double *) calloc(n, sizeof(double));
    }
    double *b = (double *) calloc(n, sizeof(double)); // Right vector
    double *xp = (double *) calloc(n, sizeof(double)); // Intermediate vector
    double *x = (double *) calloc(n, sizeof(double)); // Result vector
    double *delta = (double *) calloc(n, sizeof(double)); // Delta vector
    double *sum = (double *) calloc(n, sizeof(double)); // Sum vector
    double prop;
    double eps;

    /*
     * Data input
     */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char message[25];
            sprintf(message, "Enter a[%d][%d]: ", i, j);
            a[i][j] = inputDouble(message, 0, 0);
        }
        char message[20];
        sprintf(message, "Enter b[%d]: ", i);
        b[i] = inputDouble(message, 0, 0);
    }
    eps = inputDouble("Enter eps (between 1e-10 and 1): ", 1, 1);

    /*
     * System validation
     */
    for (int i = 0; i < n; ++i) {
        sum[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                sum[i] += a[i][j];
            }
        }
        if (fabs(a[i][i]) <= fabs(sum[i])) {
            printf("Error: diagonal elements may not be less than sum of other elements in a row.\n");
            return 1;
        }
    }

    /*
     * Initial value calculation
     */
    for (int i = 0; i < n; ++i) {
        xp[i] = b[i] / a[i][i];
    }

    /*
     * Calculation
     */
    do {
        prop = 0;
        for (int i = 0; i < n; ++i) {
            sum[i] = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum[i] += a[i][j] * xp[j];
                }
            }
            x[i] = (b[i] - sum[i]) / a[i][i];
            delta[i] = fabs(x[i] - xp[i]);
            if (delta[i] >= prop) {
                prop = delta[i];
            }
            xp[i] = x[i];
        }
    } while (prop >= eps);

    /*
     * Answer output
     */
    for (int i = 0; i < n; ++i) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }

    /*
     * Memory freeing
     */
    for (int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);
    free(b);
    free(x);
    free(xp);
    free(delta);
    free(sum);
}
