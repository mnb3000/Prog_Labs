#include <stdio.h>
#include "input_lib/input_lib.h"

int inputIntAndCheckBoundaries(char *message, int doNegativeCheck, int notLessThan, int notGreaterThen) {
    int res = inputInt(message, doNegativeCheck, 0);
    if (res < notLessThan || res > notGreaterThen) {
        printf("Invalid boundaries!\n");
        return inputIntAndCheckBoundaries(message, doNegativeCheck, notLessThan, notGreaterThen);
    }
    return res;
}

int isLeapYear(int year) {
    int isLeapYear = 0;
    if (((year % 100 != 0) && (year % 4 == 0)) || ((year % 100 == 0) && (year % 400 == 0))) {
        isLeapYear = 1;
    }
    return isLeapYear;
}

int getDayIndex(int date, int month, int year) {
    int LeapYear = isLeapYear(year);
    int n = 0;
    if (month <= 2) {
        if (LeapYear == 1) {
            n = 1;
        } else {
            n = 2;
        }
    }
    return ((int) (365.25 * year) + (int) (30.56 * month) + date + n) % 7;
}

int main() {
    int date, month, year;
    char *days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    do {
        date = inputIntAndCheckBoundaries("Input date: ", 1, 1, 31);
        month = inputIntAndCheckBoundaries("Input month: ", 1, 1, 12);
        year = inputIntAndCheckBoundaries("Input year: ", 1, 1000, 9999);
        daysInMonth[1] = 28 + isLeapYear(year);
        if (date > daysInMonth[month - 1]) {
            printf("Invalid date!\n");
        }
    } while (date > daysInMonth[month - 1]);
    int day = getDayIndex(date, month, year);
    printf("%s", days[day]);
}
