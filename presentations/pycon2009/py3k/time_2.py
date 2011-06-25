# Processor Clock time
# While time() returns a wall clock time, clock() returns processor clock time.
# The values returned from clock() should be used for performance testing,
# benchmarking etc, since they reflect the actual time used by programs and can
# be more precise than the values from time()

import hashlib
import time

# Data to use to calculate md5 checksums
data = open(__file__,'rt').read()

for i in range(5):
    h = hashlib.sha1()
    print time.ctime(), ': %0.3f %0.3f' % (time.time(), time.clock())
    for i in range(10000000):
        h.update(data)
    cksum = h.digest()

