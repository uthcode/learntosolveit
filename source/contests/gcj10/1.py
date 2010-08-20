import time
print time.ctime()
for i in xrange(10000):
    for j in xrange(100000000):
        for k in xrange(30):
            pass
print time.ctime()
