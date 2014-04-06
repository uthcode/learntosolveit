"""
Calculate the number of Friday the 13th from 1900 to 2009.
"""

import calendar

START_YEAR = 1900
END_YEAR = 2009

CALOBJ = calendar.Calendar()

LUCKY = 0

for year in range(START_YEAR, END_YEAR):
    for month in range(1, 13):
        for day in CALOBJ.itermonthdays2(year, month):
            if day[0] == 13 and day[1] == 4:
                LUCKY = LUCKY + 1

print LUCKY
