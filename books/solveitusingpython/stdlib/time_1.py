#!/usr/bin/env python2.6

import time
print 'unix time:', time.time()
print 'wallclock time:', time.ctime()
print 'processsor clock time:', time.clock()

for i in range(1,6):
    print '%s %0.2f %0.2f' % (time.ctime(), time.time(), time.clock())
    time.sleep(i)
