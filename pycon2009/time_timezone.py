import time
import os

def show_zone_info():
    print '\tTZ     :', os.environ.get('TZ','(not set)')
    print '\ttzname :', time.tzname
    print '\tZone   : %d (%d)' % (time.timezone, (time.timezone / 3600))
    print '\tDST    :', time.daylight
    print '\tTime   :', time.ctime()
    print

print 'Default:'
show_zone_info()

for zone in ['US/Eastern','US/Pacific', 'GMT',
             'Europe/Amsterdam','Asia/Culcutta']:
    os.environ['TZ'] = zone
    time.tzset()
    print zone, ':'
    show_zone_info()
