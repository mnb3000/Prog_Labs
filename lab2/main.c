#include <stdio.h>
#include <math.h>

int main() {
    double sides[3];
    for (int i = 0; i < 3; ++i) {
        printf("Enter side %d: ", i + 1);
        scanf("%lf", &sides[i]);
        if (sides[i] < 0) {
            printf("No negative sides!");
            return 1;
        }
    }
    if (sides[0] + sides[1] <= sides[2] || sides[0] + sides[2] <= sides[1] || sides[1] + sides[2] <= sides[0]) {
        printf("Impossible triangle!");
        return 1;
    }
    double P = sides[0] + sides[1] + sides[2];
    double p = P / 2;
    double S = sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
    double heights[3];
    double medians[3];
    double bisectors[3];
    for (int i = 0; i < 3; ++i) {
        const double a = sides[i];
        const double b = sides[(i + 1) % 3];
        const double c = sides[(i + 2) % 3];
        heights[i] = 2 * S / a;
        medians[i] = 0.5  * sqrt(2 * pow(b, 2) + 2 * pow(c, 2) - pow(a, 2));
        bisectors[i] = (2 / (b + c)) * sqrt(b * c * p * (p - a));
    }
    printf("\nPerim: %lf\n\n", P);
    printf("\nArea: %lf\n\n", S);
    for (int i = 0; i < 3; ++i) {
        printf("Side %d:\nHeight: %lf\nMedian: %lf\nBisector: %lf\n\n", i + 1, heights[i], medians[i], bisectors[i]);
    }
}