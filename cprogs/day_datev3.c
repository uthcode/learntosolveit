#include<stdio.h>

static char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pday);

int main(void)
{
	int day,dat,mon;

	day=day_of_year(1981,10,2);
	printf("%d\n",day);

	month_day(1981,252,&mon,&dat);
	printf("%d,%d",mon,dat);

	return 0;
}

/* day_of_year: set day of year from month and day */
int day_of_year(int year,int month,int day)
{
	int leap;
	char *p;

	leap = year%4 == 0 && year % 100 !=0 || year %400 == 0;
	p = daytab[leap];

	while(--month)
		day += *++p;
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year,int yearday,int *pmonth,int *pday)
{
	int leap;
	char *p;

	leap = year%4 == 0 && year %100 !=0 || year % 400 == 0;

	p = daytab[leap];

	while(yearday > *++p)
		yearday -= *p;

	*pmonth = p - *(daytab + leap);
	*pday = yearday;
}

	
