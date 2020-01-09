#include <stdio.h>
#include <string.h>
#include <float.h>

/**
 * Reads double value from stdin and checks validity of input
 * If validation fails - calls itself recursively
 * @param message Message to print before prompt
 * @param doNegativeCheck Boolean value for negative check
 * @return Double value from stdin
 */
double inputDouble(char message[], int doNegativeCheck, int doZeroCheck) {
    double out;
    char str[128];
    printf("%s", message);
    printf("Input should be between %e and %e\n", -DBL_MAX, DBL_MAX);
    scanf("%lf", &out);
    fgets(str, sizeof(str), stdin);
    if (strlen(str) > 1 || out > DBL_MAX || out < -DBL_MIN) {
        printf("Invalid input! Try again!\n");
        return inputDouble(message, doNegativeCheck, doZeroCheck);
    }
    if (doNegativeCheck > 0 && out < 0) {
        printf("Input is negative! Try again!\n");
        return inputDouble(message, doNegativeCheck, doZeroCheck);
    }
    if (doZeroCheck > 0 && out == 0) {
        printf("Input is zero! Try again!\n");
        return inputDouble(message, doNegativeCheck, doZeroCheck);
    }
    return out;
}

/**
 * Reads int value from stdin and checks validity of input
 * If validation fails - calls itself recursively
 * @param message Message to print before prompt
 * @param doNegativeCheck Boolean value for negative check
 * @return Int value from stdin
 */
int inputInt(char message[], int doNegativeCheck, int doZeroCheck) {
    int out;
    char str[128];
    printf("%s", message);
    scanf("%d", &out);
    fgets(str, sizeof(str), stdin);
    if (strlen(str) > 1) {
        printf("Invalid input! Try again!\n");
        return inputInt(message, doNegativeCheck, doZeroCheck);
    }
    if (doNegativeCheck > 0 && out < 0) {
        printf("Input is negative! Try again!\n");
        return inputInt(message, doNegativeCheck, doZeroCheck);
    }
    if (doZeroCheck > 0 && out == 0) {
        printf("Input is zero! Try again!\n");
        return inputInt(message, doNegativeCheck, doZeroCheck);
    }
    return out;
}

int inputIntMin(char message[], int doNegativeCheck, int doZeroCheck, int min) {
    int res = inputInt(message, doNegativeCheck, doZeroCheck);
    if (res < min) {
        printf("Invalid boundaries!\n");
        res = inputIntMin(message, doNegativeCheck, doZeroCheck, min);
    }
    return res;
}

int inputIntMax(char message[], int doNegativeCheck, int doZeroCheck, int max) {
    int res = inputInt(message, doNegativeCheck, doZeroCheck);
    if (res > max) {
        printf("Invalid boundaries!\n");
        res = inputIntMax(message, doNegativeCheck, doZeroCheck, max);
    }
    return res;
}

int inputIntMinMax(char message[], int min, int max) {
    int res = inputInt(message, 0, 0);
    if (res < min || res > max) {
        printf("Invalid boundaries!\n");
        res = inputIntMinMax(message, min, max);
    }
    return res;
}

void clean_stdin(){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * Reads string from stdin and writes it to memory location
 * If input is longer than len - other input is flushed
 * @param message Message to print before prompt
 * @param string Pointer to string to write to
 * @param len Maximum length of input
 */
void inputString(char message[], char* string, size_t len) {
    printf("%s", message);
    char format[100];
    sprintf(format, "%%%zus", len);
    scanf(format, string);
    if (string[len] != '\0') {
        string[len] = '\0';
    }
    clean_stdin();
}
