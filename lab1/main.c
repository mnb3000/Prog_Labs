#include <stdio.h>

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
    int a = 0;
    char s[128];
    printf("ENTER NUMBER:\n");
    fgets(s, 128, stdin);
    for (int i = 0; i < 128; ++i) {
        if (s[i] == 10) {
            break;
        }
        if (s[i] < 48 || s[i] > 57) {
            printf("Invalid number!");
            return 1;
        }
        a += (int) s[i] - 48;
    }
    a=roman(a,1000,'M');
    a=roman(a,500,'D');
    a=roman(a,100,'C');
    a=roman(a,50,'L');
    a=roman(a,10,'X');
    a=roman(a,5,'V');
    a=roman(a,1,'I');
    return 0;
}

