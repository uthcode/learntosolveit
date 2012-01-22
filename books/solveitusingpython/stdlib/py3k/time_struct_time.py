import time

print 'gmtime   :', time.gmtime()
print 'localtime:', time.localtime()
print 'mktime   :', time.mktime(time.localtime())

print

t = time.localtime()

print 'Day of the month:', t.tm_mday
print 'Day of the week:', t.tm_wday
print 'Day of the year:', t.tm_yday

