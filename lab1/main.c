#include <stdio.h>
#include "input_lib/input_lib.h"

int roman(int n, int a, char r) {
    if (n < 0) {
        printf("No negative numbers!");
        return 0;
    }
    while (n >= a) {
        putchar(r);
        n = n - a;
    }
    return n;
}

int main() {
    int a = inputInt("ENTER NUMBER:\n", 1, 0);
    a=roman(a,1000,'M');
    a=roman(a,500,'D');
    a=roman(a,100,'C');
    a=roman(a,50,'L');
    a=roman(a,10,'X');
    a=roman(a,5,'V');
    a=roman(a,1,'I');
    return 0;
}

