/*
 * Error check in day_of_year and month_day
 */

#include<stdio.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);

void month_day(int year, int yearday, int *month, int *day);

int main(void) {
    int yearday, month, day;

    yearday = day_of_year(1988, 2, 29);
    printf("%d\n", yearday);

    yearday = day_of_year(2020, 2, 31);
    printf("%d\n", yearday);

    month_day(1988, 60, &month, &day);
    printf("Month: %d, Day: %d\n", month, day);

    month_day(1999, 366, &month, &day);
    printf("Month: %d, Day: %d\n", month, day);

    return 0;
}

/* day_of_year: set day of year from month & day */

int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
        return -1;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

/* month_day: set month,day from day of year */

void month_day(int year, int yearday, int *month, int *day) {
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if (year < 1 || yearday < 1 || yearday > (leap ? 366 : 365)) {
        *month = -1;
        *day = -1;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *month = i;
    *day = yearday;
}
