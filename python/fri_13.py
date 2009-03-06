import calendar

START_YEAR = 1900
END_YEAR = 2009

calobj = calendar.Calendar()

lucky = 0

for year in range(START_YEAR, END_YEAR):
    for month in range(1, 13):
        for day in calobj.itermonthdays2(year, month):
            if day[0] == 13 and day[1] == 4:
                lucky = lucky + 1

print lucky
