#include<stdio.h>

static char daytab[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pday);

int main(void)
{
	int day,mon,dat;

	day=day_of_year(1981,10,2);
	
	printf("%d\n",day);

	month_day(1981,81,&mon,&dat);

	printf("%d,%d",mon,dat);
	
	return 0;
}

/* day_of_year: set day of year from month and day */

int day_of_year(int year,int month,int day)
{
	int i,leap;
	
	leap=year%4==0 && year%100 !=0 || year %400 == 0;

	if(month < 1 || month > 12)
		return -1;
	if(day < 1 || day > daytab[leap][month])
		return -1;

	for(i=1;i<month;i++)
		day += daytab[leap][i];

	return day;
}

/* month_day: set month,day from day of the year */

void month_day(int year,int yearday,int *pmonth,int *pday)
{
	int i,leap;
	
	if(year < 1)
	{
		*pmonth = -1;
		*pday = -1;
		return;
	}

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for(i=1;i<=12 && yearday > daytab[leap][i];i++)
		yearday -= daytab[leap][i];

	if(i > 12 && yearday > daytab[leap][12])
	{
		*pmonth=-1;
		*pday=-1;
	}
	else
	{
		*pmonth=i;
		*pday=yearday;
	}
}

