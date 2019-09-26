#include <stdio.h>
#include "input_lib/input_lib.h"

/**
 * Swaps two double variables
 * @param a First variable to swap
 * @param b Second variable to swap
 */
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Sorts array via bubble sort algorithm
 * @param arr Pointer to integer array
 * @param isDescending Boolean value which determines sort order
 */
void bubbleSort(double arr[], size_t n, int isDescending) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if ((isDescending == 0 && arr[j] > arr[j + 1]) || (isDescending > 0 && arr[j] < arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    // Data input
    int len = inputInt("Input array length: ", 1, 1);
    double arr[len];
    for (int i = 0; i < len; ++i) {
        printf("Enter arr[%d]", i);
        arr[i] = inputDouble(": ", 0, 0);
    }
    // Sorting
    bubbleSort(arr, len, 0);
    // Sorted array output
    for (int i = 0; i < len; ++i) {
        printf("%lf ", arr[i]);
    }
    return 0;
}