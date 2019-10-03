#include <stdio.h>
#include <string.h>

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
    scanf("%lf", &out);
    fgets(str, sizeof(str), stdin);
    if (strlen(str) > 1) {
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
