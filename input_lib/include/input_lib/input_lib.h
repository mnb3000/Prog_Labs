#ifndef PROG_LABS_INPUT_LIB_H
#define PROG_LABS_INPUT_LIB_H
    extern double inputDouble(char message[], int doNegativeCheck, int doZeroCheck);
    extern int inputInt(char message[], int doNegativeCheck, int doZeroCheck);
    extern void inputString(char message[], char* string, size_t len);
#endif //PROG_LABS_INPUT_LIB_H
