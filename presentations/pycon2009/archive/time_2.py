#!/usr/bin/env python2.6
# PyMOTW Copyright (c) 2009 Doug Hellmann All rights reserved.

import hashlib
import time

# Data to use to calculate md5 checksums
data = open(__file__,'rt').read()

for i in range(5):
    h = hashlib.sha1()
    print time.ctime(), ': %0.3f %0.3f' % (time.time(), time.clock())
    for i in range(100000):
        h.update(data)
    cksum = h.digest()

