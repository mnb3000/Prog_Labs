#include <stdio.h>
#include <string.h>
#include "input_lib/input_lib.h"

/**
 * Sorts string array via bubble sort algorithm by length of strings
 * @param arr Pointer to integer array
 * @param isDescending Boolean value which determines sort order
 * @param maxStrLen Maximal string length
 */
void bubbleSort(char *arr[], size_t n, int isDescending) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if ((isDescending == 0 && strcmp(arr[j], arr[j + 1]) > 0) || (isDescending > 0 && strcmp(arr[j], arr[j + 1]) < 0)) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int len = inputInt("Enter array length: ", 1, 1); // Array length
    int stringLen = inputInt("Enter maximum string length: ", 1, 1); // Maximum string length
    char arr[len][stringLen + 1]; // 2D array init
    char *pointerArr[len]; // Pointer array init

    /*
     * String input
     */
    for (int i = 0; i < len; ++i) {
        printf("Enter string %d (All strings longer than maximum length will be shortened)", i);
        inputString(": ", arr[i], stringLen);
        pointerArr[i] = arr[i];
    }

    bubbleSort(pointerArr, len, 0);

    /*
     * Array output
     */
    for (int i = 0; i < len; ++i) {
        printf("%s\n", pointerArr[i]);
    }
}