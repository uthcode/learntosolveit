#!/usr/bin/env python

import sys

if len(sys.argv) == 5:
    x1,y1,x2,y2 = [int(sys.argv[i+1])for i in range(len(sys.argv)-1)]
else:
    sys.exit("Usage: python %s x1 y1 x2 y2" % sys.argv[0])

if not len(filter(lambda x: (0<=x<=10000),(x1,y1,x2,y2))) == 4:
    sys.exit("Coordinates value should be between 0 and 10000")

   
intercepts = []

# Solution involves, equation of Straight Line

# first straight line

if (x1 == x2) or (y1 == y2):
    print len(intercepts)
    sys.exit()


# next (y-y1) = m * (x-x1)

dx=float(x2-x1)
dy=float(y2-y1)
m = dy/dx


if dx > 0:
    for x in range(x1,x2+1):
        y = y1+ m * (x - x1)
        if (float(x),y) not in intercepts:
            intercepts.append((float(x),y))
else:
    for x in range(x1,x2-1,-1):
        y = y1+ m * (x - x1)
        if (float(x),y) not in intercepts:
            intercepts.append((float(x),y))

if dy > 0:
    for y in range(y1,y2+1):
        x = x1 + (y-y1)/m
        if (x,float(y)) not in intercepts:
            intercepts.append((x,float(y)))
else:
    for y in range(y1,y2-1,-1):
        x = x1 + (y-y1)/m
        if (x,float(y)) not in intercepts:
            intercepts.append((x,float(y)))

print len(intercepts) - 1
