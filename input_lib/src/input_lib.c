#include <stdio.h>
#include <string.h>

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