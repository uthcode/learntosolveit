/* Concept: day_of_year using a 2D month-day table, leap year handled */
#include <stdio.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int day_of_year(int year, int month, int day) {
    int i, leap = (year%4==0 && year%100!=0) || year%400==0;
    for (i = 1; i < month; i++) day += daytab[leap][i];
    return day;
}
int main(void) {
    printf("%d\n", day_of_year(2024, 3, 1));  /* leap: 31+29+1 = 61 */
    printf("%d\n", day_of_year(2023, 3, 1));  /* non-leap: 31+28+1 = 60 */
    return 0;
}
