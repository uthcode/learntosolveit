# module localtime -- Time conversions

import posix

epoch = 1970                           # 1 jan 00:00:00, UCT
day0  = 4                              # day 0 was a thursday

day_names = ('Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat')

month_names =               ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun')
month_names = month_names + ('Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec')

month_sizes = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)

def isleap(year):
       return year % 4 = 0 and (year % 100 <> 0 or year % 400 = 0)

def gmtime(secs):                      # decode time into UCT
       mins, secs = divmod(secs, 60)
       hours, mins = divmod(mins, 60)
       days, hours = divmod(hours, 24)
       wday = (day0 + days) % 7
       year = epoch
       lp = isleap(year)
       dpy = 365 + lp
       while days >= dpy:
               days = days - dpy
               year = year + 1
               lp = isleap(year)
               dpy = 365 + lp
       yday = days
       month = 0
       dpm = month_sizes[month] + (lp and month = 1)
       while days >= dpm:
               days = days - dpm
               month = month + 1
               dpm = month_sizes[month] + (lp and month = 1)
       return (year, month, days+1, hours, mins, secs, yday, wday)

def dd(x):
       s = `x`
       while len(s) < 2: s = '0' + s
       return s

def zd(x):
       s = `x`
       while len(s) < 2: s = ' ' + s
       return s

def format(year, month, days, hours, mins, secs, yday, wday):
       s = day_names[wday] + ' ' + zd(days) + ' ' + month_names[month] + ' '
       s = s + dd(hours) + ':' + dd(mins) + ':' + dd(secs)
       return s
