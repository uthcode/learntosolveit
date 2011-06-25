#!/usr/bin/env python2.6

import time

now = time.ctime()
print 'time.ctime:', now
parsed = time.strptime(now)
print 'time.strptime(now):', parsed

print 'time.strftime(format,strptime):',time.strftime("%a %b %d %H:%M:%S %Y", parsed)
print 'time.strftime(format,gmtime):',time.strftime("%a %b %d %H:%M:%S %Y", time.gmtime())
print 'time.strftime(format,localtime):',time.strftime("%a %b %d %H:%M:%S %Y", time.localtime())

t = time.localtime()

print 'Day of the month:', t.tm_mday
print 'Day of the week:', t.tm_wday
print 'Day of the year:', t.tm_yday

print 'mktime   :', time.mktime(time.localtime())


