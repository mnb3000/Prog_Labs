#ifndef PROG_LABS_INPUT_LIB_H
#define PROG_LABS_INPUT_LIB_H
    extern double inputDouble(char message[], int doNegativeCheck, int doZeroCheck);
    extern int inputInt(char message[], int doNegativeCheck, int doZeroCheck);
    extern int inputIntMin(char message[], int doNegativeCheck, int doZeroCheck, int min);
    extern int inputIntMax(char message[], int doNegativeCheck, int doZeroCheck, int max);
    extern int inputIntMinMax(char message[], int min, int max);
    extern void inputString(char message[], char* string, size_t len);
#endif //PROG_LABS_INPUT_LIB_H
